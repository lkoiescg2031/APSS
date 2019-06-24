#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,N) for(int (i)=0;(i)<(N);(i)++)
#define MAX 100000

int N;
int num[MAX], dp[MAX];
int ans;

int main() {

	cin >> N;
	FOR(i, N)cin >> num[i];
	
	ans = dp[0] = num[0];	
	for (int i = 1; i < N; i++) {
		dp[i] = max(dp[i - 1] + num[i], num[i]);
		ans = max(dp[i], ans);
	}
	cout << ans;

	return 0;
}