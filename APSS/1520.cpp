#include <cstdio>
#include <cstring>

int m, n;
int map[500][500];
long long dp[500][500];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
// �湮 �غ��� ���� ���� �湮�Ͽ����� ���ɼ��� 0�� ���� �ٸ�
// TOP DOWN�� BOTTOM UP�� ��� ��� �ӵ��� �ٸ� (�Ұ����� ������ Ȯ�� �ؾ� ������)
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
