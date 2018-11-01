#include <iostream>
using namespace std;

#define MAX 1000
#define MOD 10007

int N;
int dp[MAX + 1][10];
int ans;

int main() {

	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k <= j; k++)
				dp[i][j] += dp[i - 1][k], dp[i][j] %= MOD;

	for (int i = 0; i < 10; i++)
		ans += dp[N][i], ans %= MOD;

	cout << ans;

	return 0;
}