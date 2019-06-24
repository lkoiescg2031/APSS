#include <iostream>
using namespace std;

#define MAX 1000
#define MOD 10007
int dp[MAX];

int main() {

	int N;

	cin >> N;
	
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

	cout << dp[N];

	return 0;
}