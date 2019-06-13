//====================================================================
//====================================================================
//matrix 연산 소스코드
#include <array>
using namespace std;

template<typename t, size_t i, size_t j = i>
using Mat = array<array<t, j>, i>;

template<typename t, size_t i, size_t j, size_t k>
Mat<t, i, k> operator* (const Mat<t, i, j>& left, const Mat<t, j, k>& right) {
	Mat<t, i, k> ret;
	for (int a = 0; a < i; a++)
		for (int b = 0; b < k; b++) {
			t& tmp = ret[a][b];
			tmp = 0;
			for (int c = 0; c < j; c++) tmp += left[a][c] * right[c][b];
		}
	return ret;
}




//====================================================================
//====================================================================
//fibonacci 관련

//행렬의 곱을 이용
long long get_fib(long long n) {
	Mat<long long, 2> ret, fib;

	fib[0][0] = fib[0][1] = fib[1][0] = 1;
	fib[1][1] = 0;

	ret[0][0] = ret[1][1] = 1;
	ret[0][1] = ret[1][0] = 0;

	while (n > 0) {
		if (n & 1) ret = ret * fib;
		fib = fib * fib;
		n /= 2;
	}

	return fib[0][1];
}

// 분할정복을 이용한 피보나치 계산
// 빠른 계산을 하려면 메모이제이션 필요
long long fib(long long n) {
	long long tmp, tmp2;
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (n & 1) {
		tmp = fib((n + 1) / 2);
		tmp2 = fib((n + 1) / 2 - 1);
		return tmp * tmp + tmp2 * tmp2;
	}
	tmp = fib(n / 2 - 1);
	tmp2 = fib(n / 2);
	return (2 * tmp + tmp2) * tmp2;
}

//피사노 주기
long long pisano_period(long long m) {

	int f0 = 0, f1 = 1, f2 = f0 + f1;
	for (int i = 0; i < m * m; i++) {
		f2 = (f0 + f1) % m;
		f0 = f1;
		f1 = f2;
		if (f0 == 0 && f1 == 1) 
			return i + 1;
	}
}