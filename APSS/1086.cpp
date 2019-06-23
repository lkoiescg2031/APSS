#include <cstdio>
#include <cstring>

int n, k;
char str[15][51];
int a[15], len[15], ten[51];
long long d[1 << 15][100];

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
		len[i] = strlen(str[i]);
	}
	scanf("%d", &k);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < len[i]; j++)
			a[i] = (a[i] * 10 + str[i][j] - '0') % k;

	ten[0] = 1;
	for (int i = 1; i < 51; i++)
		ten[i] = (ten[i - 1] * 10) % k;

	d[0][0] = 1;
	for (int i = 0; i < (1 << n); i++) for (int j = 0; j < k; j++)
		for (int l = 0; l < n; l++) if ((i & (1 << l)) == 0)
			d[i | (1 << l)][(j * ten[len[l]] + a[l]) % k]
			+= d[i][j];


	long long a = d[(1 << n) - 1][0], b = 1;
	for (long long i = 2; i <= n; i++) b *= i;
	long long g = gcd(a, b);
	printf("%lld/%lld", a / g, b / g);
	return 0;
}