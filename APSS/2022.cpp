#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define eps 1e-6

double x, y, c, l, r;

int main() {

	scanf("%lf %lf %lf", &x, &y, &c);

	r = min(x, y);
	while (abs(r - l) > eps) {
		double mid = (l + r) / 2.;
		double h1 = sqrt(x * x - mid * mid);
		double h2 = sqrt(y * y - mid * mid);
		double cmp = (h1 * h2) / (h1 + h2);
		if (cmp > c)
			l = mid;
		else
			r = mid;
	}
	printf("%.3lf", l);
	return 0;
}