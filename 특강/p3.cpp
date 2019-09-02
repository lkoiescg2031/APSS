// 위상정렬

#include <cstdio>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int testcase, test;
int n;
int map[500][500];
int dp[500][500], ind[500][500];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int main() {

	scanf("%d", &testcase);
	for (test = 1; test <= testcase; test++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
				dp[i][j] = 1;
				ind[i][j] = 0;
			}
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
			for (int k = 0; k < 2; k++) {
				int mx = i + dx[k];
				int my = j + dy[k];
				if (mx < n && my < n) {
					if (map[mx][my] > map[i][j]) ind[mx][my]++;
					else if (map[i][j] > map[mx][my]) ind[i][j]++;
				}
			}

		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
			if (ind[i][j] == 0) q.push({ i,j });

		int x, y, ans = 0;
		while (!q.empty()) {
			tie(x, y) = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int mx = x + dx[i];
				int my = y + dy[i];
				if (mx >= 0 && mx < n && my >= 0 && my < n
					&& map[mx][my] > map[x][y]) {
					ind[mx][my]--;
					dp[mx][my] = max(dp[mx][my], dp[x][y] + 1);
					ans = max(ans, dp[mx][my]);
					if (ind[mx][my] == 0) q.push({ mx,my });
				}
			}
		}

		printf("#%d %d\n", test, ans);
	}

	return 0;
}