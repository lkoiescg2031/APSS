#include <cstdio>

int n, m, k;
int mat1[100][100], mat2[100][100],mat3[100][100];

int main() {
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		scanf("%d", &mat1[i][j]);
	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; i++) for (int j = 0; j < k; j++)
		scanf("%d", &mat2[i][j]);

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < k; j++) {
			int& tmp = mat3[i][j];
			for (int l = 0; l < m; l++)
				tmp += mat1[i][l] * mat2[l][j];
		}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
			printf("%d ", mat3[i][j]);
		printf("\n");
	}

	return 0;
}