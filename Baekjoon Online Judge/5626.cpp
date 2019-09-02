#include <cstdio>
#include <cstring>
#define MOD 1000000007
#define MAX 10000

int n;
int a[MAX];
int d[2][MAX / 2 + 2];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	d[0][0] = a[0] == -1 || a[0] == 0;
	for (int i = 1; i < n; i++) {
		if (a[i] != -1) {
			memset(d[i & 1], 0, sizeof(d[i & 1]));
			d[i & 1][a[i]] = d[1 - i & 1][a[i] - 1] + d[1 - i & 1][a[i] + 1];
			d[i & 1][a[i]] %= MOD;
			d[i & 1][a[i]] += d[1 - i & 1][a[i]];
			d[i & 1][a[i]] %= MOD;
			continue;
		}
		for (int j = 0; j <= 5000; j++) {
			d[i & 1][j] = d[1 - i & 1][j + 1] + d[1 - i & 1][j];
			d[i & 1][j] %= MOD;
			if (j > 0) d[i & 1][j] += d[1 - i & 1][j - 1],d[i & 1][j] %= MOD;
		}
	}

	printf("%d", d[1 - n & 1][0]);

	return 0;
}