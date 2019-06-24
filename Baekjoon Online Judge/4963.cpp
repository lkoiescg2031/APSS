#include <iostream>
#include <vector>
using namespace std;

int n, m, ans;
vector<vector<int>> bitmap;
int movex[] = { -1,0,1,-1,1,-1,0,1 };
int movey[] = { -1,-1,-1,0,0,1,1,1 };

void dfs(int curi, int curj) {
	bitmap[curi][curj] = 0;
	for (int i = 0; i < 8; i++) {
		int dx = curi + movex[i];
		int dy = curj + movey[i];
		if (dx >= 0 && dx < m && dy >= 0 && dy < n
			&& bitmap[dx][dy] == 1)
			dfs(dx, dy);
	}
}
int main() {
	while (cin >> n >> m && n != 0 && m != 0) {
		ans = 0;
		bitmap = vector<vector<int>>(m, vector<int>(n));
		for (auto&row : bitmap)for (auto&i : row)
			cin >> i;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (bitmap[i][j] == 1) {
					dfs(i, j);
					ans++;
				}
		cout << ans << endl;
	}
	return 0;
}