#include <cstdio>

int n;
int dp[31];

int main() {

	scanf("%d", &n);

	dp[0] = 1;
	for (int i = 2; i <= n; i += 2) {
		dp[i] += dp[i - 2] * 3;
		for (int j = 0; j < i - 2; j += 2)
			dp[i] += dp[j] * 2;
	}
	printf("%d", dp[n]);

	return 0;
}