#include <cstdio>
#include <cstring>
#include <deque>
#include <tuple>
using namespace std;

int n, m;
int a[100][100], d[100][100];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int main() {

	int x, y;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &a[i][j]);
	memset(d, -1, sizeof(d));

	deque<pair<int, int>> q;
	q.push_back({ 0,0 });
	d[0][0] = 0;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && d[nx][ny] == -1) {
				if (a[nx][ny] == 0) {
					d[nx][ny] = d[x][y];
					q.push_front({ nx,ny });
				} else {
					d[nx][ny] = d[x][y] + 1;
					q.push_back({ nx,ny });
				}
			}
		}
	}
	printf("%d", d[n-1][m-1]);
	return 0;
}