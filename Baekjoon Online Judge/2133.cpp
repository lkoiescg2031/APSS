#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 30

int N;
int dp[MAX + 1];

int main() {
	
	cin >> N;

	dp[0] = 1;

	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 2];
		for (int j = 1; j <= i / 2; j++)
			dp[i] += (2 * dp[i - 2 * j]);
	}

	cout << dp[N];

	return 0;
}