#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int sign(ll i) {
	return i < 0 ? -1 : i>0;
}

using Point = pair<ll, ll>;
#define x first
#define y second

Point getP() {
	Point ret;
	scanf("%lld %lld", &ret.x, &ret.y);
	return ret;
}

ll ccw(const Point& a, const Point& b, const Point& c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

bool pointInBox(const Point& a, const Point& b1, const Point& b2) {
	return min(b1.x, b2.x) <= a.x && a.x <= max(b1.x, b2.x) &&
		min(b1.y, b2.y) <= a.y && a.y <= max(b1.y, b2.y);
}

using Line = pair<Point, Point>;

Line makeLine(Point a, Point b) {
	Line ret = { a,b };
	if (a > b) swap(a, b);
	return ret;
}

bool intersect(const Line& a, const Line& b) {
	int AB = sign(ccw(a.x, a.y, b.x)) * sign(ccw(a.x, a.y, b.y));
	int BA = sign(ccw(b.x, b.y, a.x)) * sign(ccw(b.x, b.y, a.y));
	if (!AB && !BA) return a.x <= b.y && a.y >= b.x;
	return AB <= 0 && BA <= 0;
}
bool pointInLine(const Point& a, const Line& b) {
	return ccw(b.x, b.y, a) == 0 && pointInBox(a, b.x, b.y);
}

using Polygon = vector<Point>;

Polygon convexhull(Polygon& poly) {
	int len = poly.size();
	Polygon ret(len * 2);
	sort(begin(poly), end(poly));

	int top = 0;
	for (int i = 0; i < len; i++) {
		while (top > 1 && ccw(ret[top - 2], ret[top - 1], poly[i]) <= 0) top--;
		ret[top++] = poly[i];
	}
	for (int i = len - 2, lower = top; i >= 0; i--) {
		while (top > lower && ccw(ret[top - 2], ret[top - 1], poly[i]) <= 0) top--;
		ret[top++] = poly[i];
	}
	ret.resize(top - 1);
	return ret;
}

bool pointInPolygon(const Polygon& poly, Point& a) {
	bool ret = false;
	Line aline = makeLine(a, { 10001,a.y + 1 });
	for (int i = 0; i < poly.size() - 1; i++) {
		Line polyline = makeLine(poly[i], poly[(i + 1) % poly.size()]);
		if (intersect(aline, polyline)) ret = !ret;
	}
	if (poly.size() > 2) {
		Line polyline = makeLine(poly[poly.size() - 1], poly[0]);
		if (intersect(aline, polyline)) ret = !ret;
	}
	return ret;
}

int tc;
int n, m;

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		Polygon a(n), b(m);
		for (auto& i : a) i = getP();
		for (auto& i : b) i = getP();

		Polygon aConv, bConv;
		if (n>1) aConv = convexhull(a);
		else aConv = a;
		if (m > 1) bConv = convexhull(b);
		else bConv = b;

		bool isSep = true;

		if (aConv.size() == 1 && bConv.size() == 2) {
			Line l = makeLine(bConv[0],bConv[1]);
			isSep = !pointInLine(aConv[0], l);
			if (isSep) printf("YES\n");
			else printf("NO\n");
			continue;
		} else if (aConv.size() == 2 && bConv.size() == 1) {
			Line l = makeLine(aConv[0], aConv[1]);
			isSep = !pointInLine(bConv[0], l);
			if (isSep) printf("YES\n");
			else printf("NO\n");
			continue;
		}

		for (auto& point : aConv)
			if (pointInPolygon(bConv, point)) {
				isSep = false;
				break;
			}
		if (!isSep) {
			printf("NO\n");
			continue;
		}

		for (auto& point : bConv)
			if (pointInPolygon(aConv, point)) {
				isSep = false;
				break;
			}
		if (isSep) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}