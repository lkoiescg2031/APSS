#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;

using Point = pair<ll, ll>;
#define x first
#define y second
Point getP() {
	Point ret;
	scanf("%lld %lld", &ret.x, &ret.y);
	return ret;
}

ll dst(const Point& a, const Point& b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

ll ccw(const Point& a, const Point& b, const Point& c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}
Point operator - (const Point& a, const Point& b) {
	return Point(a.x - b.x, a.y - b.y);
}

using Polygon = vector<Point>;

Polygon convexhull(Polygon& poly) {
	int len = poly.size(),top = 0;
	Polygon ret(len * 2);

	sort(begin(poly), end(poly));
	for (int i = 0; i < len; i++) {
		while (top > 1 && ccw(ret[top - 2], ret[top - 1], poly[i]) <= 0) top--;
		ret[top++] = poly[i];
	}
	for (int i = len - 2,lower = top; i >= 0; i--) {
		while (top > lower && ccw(ret[top - 2], ret[top - 1], poly[i]) <= 0) top--;
		ret[top++] = poly[i];
	}
	
	ret.resize(top - 1);
	return ret;
}

pair<Point, Point> rotating_Calipers(const Polygon& conv) {
	ll maxdst = 0;
	int len = conv.size();
	pair<Point, Point> ret;

	for (int i = 0, inext = (i + 1) % len, j = inext, jnext = (j + 1) % len;
		i < len; inext = (++i + 1) % len) {

		ll CCW = ccw({ 0,0 }, conv[inext] - conv[i], conv[jnext] - conv[j]);
		while (CCW > 0) {
			j = (j + 1) % len, jnext = (j + 1) % len;
			CCW = ccw({ 0,0 }, conv[inext] - conv[i], conv[jnext] - conv[j]);
		}

		ll dist = dst(conv[i], conv[j]);
		if (maxdst < dist) maxdst = dist, ret = { conv[i],conv[j] };
	}
	return ret;
}

int main() {
	int tc, n;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		Polygon p(n),conv;
		pair<Point, Point> ans;
		for (auto& i : p) i = getP();
		conv = convexhull(p);
		ans = rotating_Calipers(conv);
		printf("%lld %lld %lld %lld\n", ans.first.x, ans.first.y, ans.second.x, ans.second.y);
	}
	return 0;
}