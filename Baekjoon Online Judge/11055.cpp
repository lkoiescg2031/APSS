#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,j) for(int (i)=0;i<(j);(i)++)
#define MAX 1000

int N;
int num[MAX];
int dp[MAX];
int ans;

int main() {

	ios_base::sync_with_stdio(false);
	
	cin >> N;
	FOR(i, N) cin >> num[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++)
			if (num[i] > num[j])
				dp[i] = max(dp[i], dp[j]);
		dp[i] += num[i];
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}