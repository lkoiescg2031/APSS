#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,N) for(int i=0;i<(N);i++)
#define MAX 300

int N;
int num[MAX+1], dp[MAX];

int main() {
	
	cin >> N;
	FOR(i, N) cin >> num[i];

	dp[0] = num[0];
	dp[1] = dp[0] + num[1];
	for (int i = 2; i < N; i++)
		dp[i] = max(dp[i - 2] + num[i], dp[i - 3] + num[i] + num[i - 1]);

	cout << dp[N-1];

	return 0;
}