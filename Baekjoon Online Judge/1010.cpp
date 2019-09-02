#include <cstdio>

int d[31][31];

int main() {

	for (int i = 0; i <= 30; i++) {
		d[i][0] = d[i][i] = 1;
		for (int j = 1; j < i; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
		}
	}
	int tc, a, b;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", d[b][a]);
	}

	return 0;
}
