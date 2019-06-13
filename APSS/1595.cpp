#include <cstdio>
#include <algorithm>
using namespace std;

int n, s, m;
int v[101];
int dp[101][1001];

int main() {

	scanf("%d %d %d", &n, &s, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	
	dp[0][s] = 1;
	
	for(int i=1;i<=n;i++)
		for (int j = 0; j <= m; j++) {
			if (j + v[i] <= m && dp[i - 1][j + v[i]]) dp[i][j] = 1;
			if (j - v[i] >= 0 && dp[i - 1][j - v[i]]) dp[i][j] = 1;
		}

	for (int i = m; i >= 0; i--)
		if (dp[n][i]) {
			printf("%d", i);
			return 0;
		}
	printf("-1");
	return 0;
}