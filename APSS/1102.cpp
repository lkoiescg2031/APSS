#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;

int n, a[16][16],p;
int d[1 << 16];
char str[17];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	scanf("%s %d", str,&p);

	memset(d, 0x3f, sizeof(d));

	int len = strlen(str);
	int start = 0;
	for (int i = 0; i < n; i++)
		if (str[i] == 'Y')
			start |= (1 << i);
	d[start] = 0;

	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j < n; j++) if ((i & (1 << j)) != 0)
			for (int k = 0; k < n; k++)
				if ((i & (1 << k)) != 0 && k != j)
					d[i] = min(d[i], d[i - (1 << j)] + a[k][j]);

	int ans = inf;
	for (int i = 0; i < (1 << n); i++) {
		int cnt = 0;
		for (int j = i; j > 0; j >>= 1) cnt += j & 1;
		if (cnt >= p) ans = min(ans, d[i]);
	}
	if (ans == inf) printf("-1");
	else printf("%d", ans);
	return 0;
}