#include <cstdio>
#include <algorithm>
using namespace std;

//math
template<typename T>
inline int sign(T a) {
	return a < 0 ? -1 : (a > 0);
}

using ll = long long;
//geometry
using Point = pair<ll, ll>;
#define x first
#define y second

Point getp() {
	Point ret;
	scanf("%lld %lld", &ret.x, &ret.y);
	return ret;
}

ll ccw(const Point& a, const Point& b, const Point& c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

using Line = pair<Point, Point>;

Line getl() {
	Line a;
	a.x = getp();
	a.y = getp();
	if (a.x > a.y) swap(a.x, a.y);
	return a;
}

bool is_cross(const Line& a, const Line& b) {
	int ab = sign(ccw(a.x, a.y, b.x)) * sign(ccw(a.x, a.y, b.y));
	int ba = sign(ccw(b.x, b.y, a.x)) * sign(ccw(b.x, b.y, a.y));
	if (!ab && !ba) return a.x <= b.y && b.x <= a.y;
	return ab <= 0 && ba <= 0;
}