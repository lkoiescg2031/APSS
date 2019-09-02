#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int cost[101], mem[101];

int d[101][10001];

int main() {

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%d",&mem[i]);
	for (int i = 1; i <= N; i++) scanf("%d",&cost[i]);

	int ans = 0x3f3f3f3f;
	memset(d, 0xff, sizeof(d));
	d[0][0] = 0;
	for(int i=0;i<10001;i++) d[0][i] = 0;
	for (int i = 1; i <= N; i++) 
		for (int j = 0; j < 10001; j++) {
			if (d[i-1][j] != -1) d[i][j] = d[i - 1][j];
			if (j-cost[i]>=0 && d[i - 1][j - cost[i]] != -1) d[i][j] = max(d[i][j], d[i - 1][j - cost[i]] + mem[i]);
			if (d[i][j] >= M) ans = min(ans, j);
		}
	printf("%d\n", ans);
	return 0;
}