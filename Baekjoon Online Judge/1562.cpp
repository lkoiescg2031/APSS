#include <cstdio>

const long long mod = 1000000000;

int n;
long long d[101][10][1<<10];

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= 9; i++)
		d[1][i][1 << i] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < (1 << 10); k++) 
				if ((k & (1 << j)) != 0){
					if (j < 9) d[i][j][k] += (d[i - 1][j + 1][k] + d[i - 1][j + 1][k ^ (1 << j)]) % mod;
					if (j > 0) d[i][j][k] += (d[i - 1][j - 1][k] + d[i - 1][j - 1][k ^ (1 << j)]) % mod;
				};
	
	long long ans = 0;
	for (int i = 0; i < 10; i++)
		ans = (ans + d[n][i][1023]) % mod;
	printf("%lld", ans);

	return 0;
}