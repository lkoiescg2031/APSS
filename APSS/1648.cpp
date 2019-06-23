#include <cstdio>
#include <cstring>
const int mod = 9901;

int n, m;
int d[14 * 14][1 << 14];

int go(int i, int j) {
	if (i == n * m) return j == 0 ? 1 : 0;

	int& ret = d[i][j];

	if (ret != -1) return d[i][j];
	if (j & 1) return ret = go(i + 1, j >> 1);

	ret = go(i + 1, j >> 1 | 1 << (m - 1)) % mod;
	if (i % m + 1 != m && (j & 2) == 0) ret = (ret + go(i + 2, j >> 2)) % mod;	
	return ret;
}

int main() {
	
	scanf("%d %d", &n, &m);
	memset(d, -1, sizeof(d));
	printf("%d", go(0, 0));
	return 0;
}