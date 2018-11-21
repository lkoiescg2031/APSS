#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 200
#define MOD 1000000000

int N, K;
long long dp[MAX + 1][MAX + 1];

int main() {
	
	cin >> N >> K;
	
	dp[0][0] = 1;
	for (int i = 0; i <= N; i++)
		for (int j = 1; j <= K; j++)
			for (int k = 0; k <= i; k++)
				dp[i][j] += dp[i - k][j - 1],dp[i][j] %= MOD;

	cout << dp[N][K];
	
	return 0;
}