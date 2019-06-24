#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,N) for(int (i)=0;(i)<(n);(i)++)
#define MAX 2000

int N;
int card[MAX], subsum[MAX+1];
int dp[MAX + 1][MAX + 1];

int main() {
	
	cin >> N;
	for (int i = N - 1; i >= 0; i--) cin >> card[i];

	subsum[1] = card[0];
	for (int i = 1; i < N; i++) subsum[i+1] = subsum[i] + card[i];
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i][j - 1];
			dp[i][j] = max(dp[i][j], subsum[i] - (2 * j <= i - j ? 
				dp[i - j][2 * j] 
				: dp[i - j][i - j]));
		}

	cout << dp[N][2];
	return 0;
}
