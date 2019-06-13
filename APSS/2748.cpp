#include <cstdio>

long long n, ans[91];

int main() {
	ans[1] = ans[2] = 1;
	for (int i = 3; i <= 90; i++)
		ans[i] = ans[i - 1] + ans[i - 2];

	scanf("%lld", &n);
	printf("%lld", ans[n]);
	return 0;
}