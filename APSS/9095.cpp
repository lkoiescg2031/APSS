#include <iostream>
using namespace std;

#define MAX 11
int dp[MAX + 1];

int main() {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= MAX; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << dp[N] << endl;
	}
	return 0;
}