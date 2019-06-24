#include <cstdio>
#include <array>
using namespace std;

template<typename t, size_t i, size_t j = i>
using Mat = array<array<t, j>, i>;

template<typename t, size_t i, size_t j, size_t k>
Mat<t, i, k> operator* (const Mat<t, i, j>& left, const Mat<t, j, k>& right) {
	const int mod = 1000000007;
	Mat<t, i, k> ret;
	for (size_t a = 0; a < i; a++)
		for (size_t b = 0; b < k; b++) {
			t& tmp = ret[a][b];
			tmp = 0;
			for (int c = 0; c < j; c++) {
				tmp += left[a][c] * right[c][b];
				tmp %= mod;
			}
		}
	return ret;
}

long long get_fib(long long n) {
	Mat<long long, 2, 2> ret, fib;

	fib[0][0] = fib[0][1] = fib[1][0] = 1;
	fib[1][1] = 0;

	ret[0][0] = ret[1][1] = 1;
	ret[0][1] = ret[1][0] = 0;

	while (n > 0) {
		if (n & 1) ret = ret * fib;
		fib = fib * fib;
		n /= 2;
	}

	return ret[0][1];
}

int main() {

	long long n;
	scanf("%lld", &n);
	printf("%lld", get_fib(n));
	return 0;
}