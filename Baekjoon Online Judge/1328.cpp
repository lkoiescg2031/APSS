#include <cstdio>

const long long mod = 1000000007;

int n, l, r;
long long dp[101][101][101];


int main() {
	
	scanf("%d %d %d", &n, &l, &r);

	dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++) for(int j=1;j<=l;j++)for (int k = 1; k <= r; k++) {
		dp[i][j][k] += dp[i - 1][j - 1][k];
		dp[i][j][k] %= mod;
		dp[i][j][k] += dp[i - 1][j][k - 1];
		dp[i][j][k] %= mod;
		dp[i][j][k] += dp[i - 1][j][k] * (i - 2);
		dp[i][j][k] %= mod;

	}

	printf("%lld",dp[n][l][r]);
	return 0;
}