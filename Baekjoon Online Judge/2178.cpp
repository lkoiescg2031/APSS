#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

int n, m, bitmap[100][100];
int movex[] = {1,0,- 1,0};
int movey[] = {0,1,0,-1};

int main() {

	queue<tuple<int, int, int>> q;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d",&bitmap[i][j]);

	bitmap[0][0] = 0;
	q.push({ 1,0,0});
	while(!q.empty()) {
		int x, y, ans;
		tie(ans, x, y) = q.front();
		q.pop();
		if (x == n - 1 && y == m - 1) {
			printf("%d", ans);
			break;
		}
		for (int i = 0; i < 4; i++) {
			int dx = x + movex[i];
			int dy = y + movey[i];
			if (dx >= 0 && dy >= 0 && dx < n&&dy < m
				&& bitmap[dx][dy] == 1) {
				bitmap[dx][dy] = 0;
				q.push({ ans + 1,dx,dy });
			}
		}

	}

	return 0;
}