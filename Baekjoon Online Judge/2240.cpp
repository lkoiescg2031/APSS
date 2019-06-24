#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T, W;
int arr[1001];
int dp[1001][31];

int main() {

	scanf("%d %d", &T, &W);
	for (int i = 1; i <= T; i++) scanf("%d", &arr[i]), arr[i]--;

	for(int j=0;j<=W;j++)
		for (int i = 1; i <= T; i++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			dp[i][j] += j % 2 == arr[i];
		}
	printf("%d", max(dp[T][W], dp[T][W - 1]));
	return 0;
}