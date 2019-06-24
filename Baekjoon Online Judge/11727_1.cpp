#include <iostream>
using namespace std;

#define MAX 1000
#define MOD 10007

int N;
int dp[MAX + 1];

int solve(int n) {
	if (dp[n] != 0)
		return dp[n];
	else if (n == 0 || n == 1)
		return dp[n] = 1;

	return dp[n] = (solve(n - 1) + 2 * solve(n - 2)) % MOD;
}

int main() {
	
	ios_base::sync_with_stdio(false);

	cin >> N;

	cout << solve(N);

	return 0;
}
