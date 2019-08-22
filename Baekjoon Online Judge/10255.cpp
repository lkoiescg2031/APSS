#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

inline int sign(ll a) {
	return a < 0 ? -1 : a > 0;
}

using Point = pair<ll, ll>;
#define x first
#define y second

Point getPoint() {
	Point ret;
	scanf("%lld%lld", &ret.x, &ret.y);
	return ret;
}

ll ccw(const Point& a, const Point& b, const Point& c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

bool pointInBox(const Point& point, const Point& B1,const Point& B2) {
	return min(B1.x, B2.x) <= point.x && point.x <= max(B1.x, B2.x) &&
		min(B1.y, B2.y) <= point.y && point.y <= max(B1.y, B2.y);
}

using Line = pair<Point, Point>;

Line genLine(const Point& a, const Point& b) {
	Line ret = { a, b };
	if (ret.x > ret.y) swap(ret.x, ret.y);
	return ret;
}

Line getLine() {
	Line ret;
	ret.x = getPoint(), ret.y = getPoint();
	if (ret.x > ret.y) swap(ret.x, ret.y);
	return ret;
}

int intersect2Line(const Line& a, const Line& b) { // 0 교차하지 않음, 1 교점이 하나 -1 교점이 무수히 많음
	int ab = sign(ccw(a.x, a.y, b.x)) * sign(ccw(a.x, a.y, b.y));
	int ba = sign(ccw(b.x, b.y, a.x)) * sign(ccw(b.x, b.y, a.y));
	if (!ab && !ba) {
		if (a.x > b.y || a.y < b.x) return 0;
		else if (a.x == b.y || a.y == b.x) return 1;
		else if (a.x == b.x && ccw(a.y, a.x, b.y)) return 1;
		else if (a.y == b.y && ccw(a.x, a.y, b.x)) return 1;
		return -1;
	}
	return ab <= 0 && ba <= 0;
}

using Rect = pair<Point, Point>;

Rect getr() {
	Rect ret;
	ret.x = getPoint();
	ret.y = getPoint();
	if (ret.x.x > ret.y.x) swap(ret.x.x, ret.y.x);
	if (ret.x.y > ret.y.y) swap(ret.x.y, ret.y.y);
	return ret;
}

bool pointInLine(const Point& a, const Line& b) {
	return ccw(b.x, b.y, a) == 0 && pointInBox(a, b.x, b.y);
}

int intersectLineRect(const Line& line, const Rect& rect) { // 교점의 수 , 4 무수히 많은 교점
	int ret = 0;
	Point p[4] = { rect.x,{rect.x.x,rect.y.y},rect.y,{rect.y.x,rect.x.y} };
	for (int i = 0; i < 4; i++) {
		Line l = genLine(p[i], p[(i + 1) % 4]);
		int res = intersect2Line(line, l);
		if (res == -1) return 4;
		else if (res == 1 && !pointInLine(p[i], line)) ret++;
	}
	return ret;
}

int tc;

int main() {
	scanf("%d", &tc);
	while (tc--) {
		Rect r = getr();
		Line l = getLine();
		printf("\n%d\n\n", intersectLineRect(l, r));
	}
	return 0;
}
