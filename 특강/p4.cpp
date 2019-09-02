#include <cstdio>
#include <queue>
#include <functional>
#include <tuple>
using namespace std;
using iiiint = tuple<int, int, int, int>;

int test, t;
int n;
int map[300][300];
pair<int, int> dp[300][300];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int main() {

	scanf("%d", &test);
	for (t = 1; t <= test; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
				dp[i][j] = { -1,-1 };
			}

		int x, y;
		priority_queue<iiiint, vector<iiiint>, greater<iiiint>> q;

		int cur_odd = map[0][0] % 2 == 1;
		int cur_even = map[0][0] % 2 == 0;
		q.push(make_tuple(cur_odd, cur_even, 0, 0));
		while (!q.empty()) {

			tie(cur_odd, cur_even, x, y) = q.top();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int mx = x + dx[k];
				int my = y + dy[k];
				if (mx >= 0 && mx < n && my >= 0 && my < n && dp[mx][my].first == -1) {
					int next_even = !(map[mx][my] % 2);
					int next_odd = map[mx][my] % 2;
					dp[mx][my].first = cur_odd + next_odd;
					dp[mx][my].second = cur_even + next_even;
					q.push(make_tuple(dp[mx][my].first, dp[mx][my].second, mx, my));
				}
			}
		}
		printf("#%d %d %d\n", t, dp[n - 1][n - 1].first, dp[n - 1][n - 1].second);
	}

	return 0;
}