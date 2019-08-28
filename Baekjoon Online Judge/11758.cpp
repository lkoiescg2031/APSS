#include <cstdio>
#include <queue>

using ll = long long;
ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1;
}

int main() {
	int x1, x2, x3, y1, y2, y3;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	printf("%d", ccw(x1, y1, x2, y2, x3, y3));
	return 0;
}