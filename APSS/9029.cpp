#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX 200
#define FOR(i,n) for(int (i)=1;(i)<(n);++(i))

int dp[MAX + 1][MAX + 1][MAX + 1];

int solve(int W, int L, int H) {
	int ret = dp[W][L][H];

	if (ret != INF) return ret;
	else if (W == L && L == H) return ret = 1;

	FOR(i, W)
		ret = min(ret, solve(i, L, H) + solve(W - i, L, H));

	FOR(i, L)
		ret = min(ret, solve(W, i, H) + solve(W, L - i, H));

	FOR(i, H)
		ret = min(ret, solve(W, L, i) + solve(W, L, H - i));

	return dp[W][L][H] = dp[W][H][L] = dp[L][W][H] = dp[L][H][W]
		= dp[H][W][L] = dp[H][L][W] = ret;
}
int main() {

	int testcase;
	int W, L, H;

	memset(dp, INF, sizeof(dp));
	ios_base::sync_with_stdio(false);

	cin >> testcase;
	while (testcase--) {
		cin >> W >> L >> H;
		cout << solve(W, L, H) << endl;
	}

	return 0;
}