#include <cstdio>

long long a,b,c;
long long pow(long long a,long long b) {
	long long ret = 1;
	while (b > 0) {
		if (b & 1) ret = ( ret * a ) % c;
		a = (a * a) % c;
		b /= 2;
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &a, &b, &c);
	printf("%lld", pow(a, b));
	return 0;
}