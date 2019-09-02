#include <cstdio>

int n;
int arr[101];
long long dp[101][21];

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	dp[1][arr[1]] = 1;
	for (int i = 2; i<n; i++)
		for (int j = 0; j <= 20; j++) {
			if (j - arr[i] >= 0 && dp[i - 1][j - arr[i]] != 0) dp[i][j] += dp[i - 1][j - arr[i]];
			if (j + arr[i] <= 20 && dp[i - 1][j + arr[i]] != 0) dp[i][j] += dp[i - 1][j + arr[i]];
		}

	printf("%lld", dp[n - 1][arr[n]]);
	return 0;
}