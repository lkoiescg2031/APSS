#include <cstdio>
#include <vector>
#include <tuple>
using namespace std;

typedef long long ll;

inline int sign(ll i) {
	return i < 0 ? -1 : i > 0;
}

typedef pair<ll, ll> Point;
#define x first
#define y second

Point getp() {
	Point ret;
	scanf("%lld %lld", &ret.x, &ret.y);
	return ret;
}

ll ccw(const Point& a, const Point& b, const Point& c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

typedef pair<Point, Point> Line;

Line make_line(const Point& a, const Point& b) {
	Line ret = { a,b };
	if (ret.x > ret.y) swap(ret.x, ret.y);
	return ret;
}

Line getl() {
	Line ret;
	ret.x = getp(), ret.y = getp();
	if (ret.x > ret.y) swap(ret.x, ret.y);
	return ret;
}

bool intersect(const Line& a, const Line& b) {
	int AB = sign(ccw(a.x, a.y, b.x)) * sign(ccw(a.x, a.y, b.y));
	int BA = sign(ccw(b.x, b.y, a.x)) * sign(ccw(b.x, b.y, a.y));
	if (!AB && !BA) return b.y >= a.x && b.x <= a.y;
	return AB <= 0 && BA <= 0;
}

typedef pair<Point, Point> Rect;
Rect getr() {
	Rect ret;
	ret.x = getp(), ret.y = getp();
	if (ret.x.x > ret.y.x) swap(ret.x.x, ret.y.x);
	if (ret.x.y < ret.y.y) swap(ret.x.y, ret.y.y);
	return ret;
}

bool intersect(const Line& l, const Rect& r,int rest) {
	Point rp[4] = { r.x, { r.x.x,r.y.y }, r.y, { r.y.x,r.x.y } };
	Line lines[4];
	for (int i = 0; i < 4; i++) {
		lines[i] = make_line(rp[i], rp[(i + 1) % 4]);
		if (intersect(l, lines[i])) return true;
	}
	return false;
}

bool pointInBox(const Rect& r, const Point& p) {
	return r.x.x <= p.x && p.x <= r.y.x && r.y.y <= p.y && p.y <= r.x.y;
}

int tc;

int main() {

	scanf("%d", &tc);
	while (tc--) {
		Line l = getl();
		Rect r = getr();
		if (intersect(l, r, 0) || pointInBox(r, l.x)) printf("T\n");
		else printf("F\n");
	}
	return 0;
}