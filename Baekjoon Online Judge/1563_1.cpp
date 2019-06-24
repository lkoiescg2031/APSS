#include <cstdio>

const int mod = 1000000;
int n, d[1001][3][3][2];

int main() {

	scanf("%d", &n);

	d[1][0][0][0] = d[1][1][1][0] = d[1][2][0][1] = 1;

	for(int i=1;i<=n;i++)
		for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) for (int l = 0; l < 2; l++) {
			d[i + 1][0][0][l] = (d[i + 1][0][0][l] + d[i][j][k][l]) % mod;
			if (k < 2) d[i + 1][1][k + 1][l] = (d[i + 1][1][k + 1][l] + d[i][j][k][l]) % mod;
			if (l == 0) d[i + 1][2][0][l + 1] = (d[i + 1][2][0][l + 1] + d[i][j][k][l]) % mod;
		}

	int ans = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 2; k++)
				ans = (ans + d[n][i][j][k]) % mod;
	printf("%d", ans);
	return 0;
}