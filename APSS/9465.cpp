#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 100000
#define NO 0
#define UP 1
#define DOWN 2

int dp[MAX][3];

int T, N;
pair<int, int> sticker[MAX];

int ans;

int main() {

	ios_base::sync_with_stdio(false);
	
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> sticker[i].first;
		for (int i=0;i<N;i++)
			cin >> sticker[i].second;
		dp[0][0] = 0;
		dp[0][1] = sticker[0].first;
		dp[0][2] = sticker[0].second;
		for (int i = 1; i < N; i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][0] = max(dp[i][0], dp[i - 1][2]);
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2])+sticker[i].first;
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1])+sticker[i].second;
		}
		ans = max(dp[N - 1][0], dp[N - 1][1]);
		ans = max(ans, dp[N - 1][2]);
		cout << ans << endl;
	}
	return 0;
}