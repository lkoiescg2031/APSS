#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[16][16], d[(1 << 16)][16];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	memset(d, 0x3f, sizeof(d));
	d[1][0] = 0;
	for (int i = 0; i < (1 << n); i++) for (int j = 1; j < n; j++)
		if ((i & (1 << j)) != 0) for (int k = 0; k < n; k++)
			if (j != k && (i & (1 << k)) != 0 && a[k][j] != 0)
				d[i][j] = min(d[i][j], d[i - (1 << j)][k] + a[k][j]);
					
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < n; i++)
		if(a[i][0] != 0) ans = min(ans, d[(1 << n) - 1][i] + a[i][0]);
	printf("%d", ans);
	return 0;
}