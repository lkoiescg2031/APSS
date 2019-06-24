#include <cstdio>
#include <algorithm>

int n;
long long map[110][110], dp[110][110];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		scanf("%d", &map[i][j]);
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		int move = map[i][j];
		if (move == 0) continue;
		dp[i + move][j] += dp[i][j];
		dp[i][j + move] += dp[i][j];
	}
	printf("%lld", dp[n][n]);
	return 0;
}