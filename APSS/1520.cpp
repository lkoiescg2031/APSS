#include <cstdio>
#include <cstring>

int m, n;
int map[500][500];
long long dp[500][500];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
// 방문 해보지 않은 경우와 방문하였으나 가능성이 0인 경우는 다름
// TOP DOWN과 BOTTOM UP의 경우 계산 속도가 다름 (불가능한 경우까지 확인 해야 함으로)
long long go(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < m && ny < n
			&& map[nx][ny] < map[x][y]) {
			dp[x][y] += go(nx, ny);
		}
	}
	return dp[x][y];
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
		scanf("%d", &map[i][j]);

	memset(dp, -1, sizeof(dp));
	dp[m-1][n-1] = 1;
	printf("%lld", go(0,0));
	return 0;
}
