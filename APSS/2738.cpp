#include <cstdio>

int n, m, t;
int mat[100][100];

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &mat[i][j]);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &t);
			printf("%d ", mat[i][j] + t);
		}
		printf("\n");
	}

	return 0;
}