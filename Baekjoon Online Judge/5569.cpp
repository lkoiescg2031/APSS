#include <cstdio>
#include <tuple>
using namespace std;

#define MOD 100000

#define RR 0
#define DR 1
#define RD 2
#define DD 3

int n, m;
int d[101][101][4];

int main() {

	scanf("%d %d", &n, &m);
	
	d[0][0][1] = d[0][0][2] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i - 1 >= 0) {
				d[i][j][RD] = d[i - 1][j][RR];
				d[i][j][DD] = (d[i - 1][j][DD] + d[i - 1][j][RD]) % MOD;
			}
			if (j - 1 >= 0) {
				d[i][j][DR] = d[i][j - 1][DD];
				d[i][j][RR] = (d[i][j - 1][RR] + d[i][j - 1][DR]) % MOD;	
			}
		}

	int ans = 0;
	for (int i = 0; i < 4; i++) ans += d[n - 1][m - 1][i]; ans %= MOD;
	printf("%d", ans);

	return 0;
}