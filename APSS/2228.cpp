#include <cstdio>
#include <algorithm>
using namespace std;

#define MIN -32768
const int INF = MIN * 101;
//음수 조심
int n,m;
int arr[101], subsum[101];
int dp[101][51];

int go(int n, int m) {
	if (m == 0) return 0;
	if (n <= 0) return INF;
	if (dp[n][m] != INF) return dp[n][m];
	
	dp[n][m] = go(n - 1, m);
	for (int k = 1; k <= n; k++)
		dp[n][m] = max(dp[n][m], go(k - 2, m - 1) + subsum[n] - subsum[k - 1]);
	return dp[n][m];
}

int main() {
	
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		subsum[i] = subsum[i - 1] + arr[i];
	}

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j] = INF;

	printf("%d", go(n, m));
	
	return 0;
}