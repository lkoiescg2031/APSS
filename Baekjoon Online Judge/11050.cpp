#include <cstdio>

long long permu[11];
int n, k;

int main() {

	permu[0] = permu[1] = 1;
	for (int i = 2; i <= 10; i++)
		permu[i] = permu[i - 1] * i;

	scanf("%d %d", &n, &k);
	printf("%lld", (permu[n] / permu[k]) / permu[n - k]);

	return 0;
}