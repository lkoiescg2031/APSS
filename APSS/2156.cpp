#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000

int N;
int drink_size[MAX];

int dp[MAX][3];
int ans;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> drink_size[i];
	dp[0][1] = drink_size[0];
	for (int i = 1; i < N; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][0] = max(dp[i][0], dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + drink_size[i];
		dp[i][2] = dp[i - 1][1] + drink_size[i];
	}
	ans = max(dp[N - 1][0], dp[N - 1][1]);
	ans = max(ans, dp[N - 1][2]);
	cout << ans;

	return 0;
}