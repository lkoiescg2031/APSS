#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
using ll = long long;

template <typename T>
tuple<T, T, T> extended_euclidean(T a, T b) {
	if (b == 0) return make_tuple(a, 1, 0);
	T gcd, x, y;
	tie(gcd, x, y) = extended_euclidean(b, a % b);
	return make_tuple(gcd, y, x - (a / b) * y);
}

template <typename T>
T div_ceil(T a, T b) {
	return a >= 0 ? (a + b - 1) / b : a / b;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		ll k, c, gcd, x0, y0;
		scanf("%lld %lld", &k, &c);
		tie(gcd, x0, y0) = extended_euclidean(k, c);
		if (gcd != 1) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		ll t = min(div_ceil(-x0, c), div_ceil(y0, k)) - 1;
		if (y0 - 1e9 > k * t) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("%lld\n", y0 - t * k);
	}
	return 0;
}