#include <iostream>
using namespace std;

#define MAX 100

int T,N;
long long dp[MAX + 1];//오버플로우

int main() {

	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;

	for (int i = 6; i <= MAX; i++)
		dp[i] = dp[i - 1] + dp[i - 5];

	cin >> T;	
	while (T--) {
		cin >> N;
		cout << dp[N] << endl;
	}

	return 0;
}