#include <cstdio>

long long a, b, c;

long long pow(long long a, long long b) {

	if (b == 0) return 1;
	else if (b == 1) return a % c;
	else if (b % 2 == 1) return (a % c * pow(a, b - 1) % c) % c;
	long long ret = pow(a, b / 2);
	return (ret % c * ret % c) % c;
}

int main() {
	
	scanf("%lld %lld %lld", &a, &b, &c);

	printf("%lld", pow(a, b));
	return 0;
}