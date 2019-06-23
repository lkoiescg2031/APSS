#include <cstdio>

const int mod = 1000000;
int n, d[1001][3][3][3][2];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			for (int k = 0; k < 3; k++) {
				if (i == 2 && j == 2 && k == 2) continue;
				if (j == 1 && k == 1) continue;
				if (i == 1 && k == 1) continue;
				if (i == 1 || j == 1 || k == 1) d[3][i][j][k][1] = 1;
				else d[3][i][j][k][0] = 1;
			}
		}

	for (int i = 4; i <= n; i++)
		for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) for (int l = 0; l < 3; l++) {
			auto& pre = d[i - 1][j][k][l];
			auto& cur0 = d[i][0][j][k]; // 출석
			auto& cur1 = d[i][1][j][k]; // 지각
			auto& cur2 = d[i][2][j][k]; // 결석
			//출석
			cur0[0] = (cur0[0] + pre[0]) % mod;
			cur0[1] = (cur0[1] + pre[1]) % mod;
			//지각
			cur1[1] = (cur1[1] + pre[0]) % mod;
			//결석
			if (j != 2 || k != 2) {
				cur2[0] = (cur2[0] + pre[0]) % mod;
				cur2[1] = (cur2[1] + pre[1]) % mod;
			}
		}

	if (n == 0) printf("0");
	else if (n == 1) printf("3");
	else if (n == 2) printf("8");//3*3 - 2번 지각
	else {
		int ans = 0;
		for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)for (int k = 0; k < 3; k++)
			ans = (ans + d[n][i][j][k][0] + d[n][i][j][k][1]) % mod;
		printf("%d", ans);
	}
	return 0;
}