#include <iostream>
using namespace std;

#define MAX 100
#define MOD 1000000000//10¾ï

long long N;
long long dp[MAX + 1][10];
long long ans;

int main() {
	
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++) 
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0)dp[i][j] += dp[i - 1][j - 1], dp[i][j] %= MOD;
			if (j + 1 <= 9)dp[i][j] += dp[i - 1][j + 1], dp[i][j] %= MOD;
		}

	for (int i = 0; i < 10; i++)
		ans += dp[N][i], ans %= MOD;
	cout << ans;

	return 0;
}