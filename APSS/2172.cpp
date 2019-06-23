#include <cstdio>

int n, l;
int a[20][20];
int d[21][20][20][20][20];

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

int main() {

	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);

	for (int i = 0; i < n; i++)	for (int j = 0; j < n; j++) {
		d[1][i][j][i][j] = 1;
		for (int k = 0; k < 8; k++) {
			int nx = i + dx[k], ny = j + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && a[i][j] == a[nx][ny])	d[2][i][j][nx][ny] = 1;
		}
	}

	for (int i = 3; i <= l; i++) 
		for (int x1 = 0; x1 < n; x1++) for (int y1 = 0; y1 < n; y1++) 
			for (int x2 = 0; x2 < n; x2++) for (int y2 = 0; y2 < n; y2++)
				for (int j = 0; j < 8; j++) {
					int dx1 = x1 + dx[j], dy1 = y1 + dy[j];
					if (dx1 >= 0 && dx1 < n && dy1 >= 0 && dy1 < n) 
						for (int k = 0; k < 8; k++) {
						int dx2 = x2 + dx[k], dy2 = y2 + dy[k];
						if (dx2 >= 0 && dx2 < n && dy2 >= 0 && dy2 < n && a[dx1][dy1] == a[dx2][dy2])
							d[i][dx1][dy1][dx2][dy2] += d[i-2][x1][y1][x2][y2];
					}
				}

	int ans = 0;
	for (int x1 = 0; x1 < n; x1++)for (int y1 = 0; y1 < n; y1++) for (int x2 = 0; x2 < n; x2++)for (int y2 = 0; y2 < n; y2++)
		ans += d[l][x1][y1][x2][y2];
	printf("%d", ans);
	return 0;
}