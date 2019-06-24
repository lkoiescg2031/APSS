#include <cstdio>

long long min, max;
bool check[1000001];

int main() {

	scanf("%lld %lld", &min, &max);

	for (long long i = 2; i * i <= max; i++) {
		long long start = i * i - min % (i * i);
		if (start == i * i) start = 0;
		for (long long j = start; j <= max - min; j += i * i)
			check[j] = true;
	}

	int ans = 0;
	for (int i = 0; i <= max - min; i++)
		if (check[i] == 0) ans++;
	printf("%d", ans);

	return 0;
}