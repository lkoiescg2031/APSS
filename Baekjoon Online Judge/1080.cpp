#include <cstdio>
using namespace std;
#define MAX 50
int n, m, ans;
int map[MAX][MAX], des[MAX][MAX];

void flip(int i, int j) {
	for (int k = 0; k < 3; k++)
		for (int l = 0; l < 3; l++)
			map[i + k][j + l] = 1 - map[i + k][j + l];
}

int main() {
	
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%1d", &des[i][j]);
		}

	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 2; j++)
			if (map[i][j] != des[i][j])
				flip(i, j),ans++;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] != des[i][j]) {
				printf("-1");
				return 0;
			}
	printf("%d", ans);
	return 0;
}