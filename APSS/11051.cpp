#include <cstdio>

int mod = 10007;
int d[1000][1000];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		d[i][0] = d[i][i] = 1;
		for (int j = 1; j < i; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
			d[i][j] %= mod;
		}
	}
	printf("%d", d[n][k]);
	return 0;
}
