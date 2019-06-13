#include <cstdio>

long long n, ans[1500001];

int main() {
	ans[1] = ans[2] = 1;
	for (int i = 3; i <= 1500000; i++) {
		ans[i] = ans[i - 1] + ans[i - 2];
		ans[i] %= 1000000;
	}

	scanf("%lld", &n);
	printf("%lld", ans[n % 1500000]);
	return 0;
}