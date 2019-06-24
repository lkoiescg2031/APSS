#include <cstdio>

int n, dp[31][8];

int main() {

	scanf("%d", &n);

	dp[0][7] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][7];
		dp[i][1] = dp[i - 1][6];
		dp[i][2] = dp[i - 1][5];
		dp[i][3] = dp[i - 1][4] + dp[i - 1][7];
		dp[i][4] = dp[i - 1][3];
		dp[i][5] = dp[i - 1][2];
		dp[i][6] = dp[i - 1][1] + dp[i - 1][7];
		dp[i][7] = dp[i - 1][0] + dp[i - 1][3] + dp[i - 1][6];
	}

	printf("%d", dp[n][7]);
	return 0;
}