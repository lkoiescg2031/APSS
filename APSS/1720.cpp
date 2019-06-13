#include <cstdio>

int n;
long long a[31], d[31];

int main() {

	d[1] = a[1] = 1;
	d[2] = a[2] = 3;

	for (int i = 3; i <= 30; i++) {
		a[i] = a[i - 1] + a[i - 2] * 2;
		if (i % 2 == 1) d[i] = a[(i - 1) / 2];
		else d[i] = a[i / 2] + a[(i - 2) / 2] * 2;
		d[i] += a[i];
		d[i] /= 2;
	}

	scanf("%d", &n);
	printf("%d", d[n]);
	return 0;
}