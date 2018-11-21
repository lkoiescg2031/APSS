#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,N) for(int (i)=0;(i)<(N);(i)++)
#define MAX 1000

int N;
int num[MAX], dp[MAX];
int ans;

int main() {

	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, N) cin >> num[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++)
			if (num[i] < num[j])
				dp[i] = max(dp[j], dp[i]);
		dp[i]++;
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}