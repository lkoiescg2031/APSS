#include <cstdio>
#include <vector>
#include <tuple>
using namespace std;

#define abs(a) ((a)<0 ? -(a) : (a))
#define get_sign(i) ((i) < 0 ? -1 : (i) > 0)

#define x first
#define y second

using ll = long long;
ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1;
}

using point = pair<ll, ll>;
ll ccw(const point& a, const point& b, const point& c) {
	return ccw(a.x, a.y, b.x, b.y, c.x, c.y);
}
point get_point() {
	ll x, y;
	scanf("%lld%lld", &x, &y);
	return{ x, y };
}

int main() {

	int n, x, y;
	vector<pair<int, int>> a;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &x, &y);
		a.emplace_back(x, y);
	}

	double ans = 0;
	for (int i = 2; i < a.size(); i++)
		ans += ccw(a[0].x, a[0].y, a[i - 1].x, a[i - 1].y, a[i].x, a[i].y);

	printf("%.1lf", abs(ans / 2));
	return 0;
}