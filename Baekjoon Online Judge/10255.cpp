#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

inline int sign(ll a) {
	return a < 0 ? -1 : a > 0;
}

using point = pair<ll, ll>;
#define x first
#define y second

point getp() {
	point ret;
	scanf("%lld%lld", &ret.x, &ret.y);
	return ret;
}
ll ccw(const point& a, const point& b, const point& c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

using line = pair<point, point>;

line makel(const point& a, const point& b) {
	line ret = { a, b };
	if (ret.x > ret.y) swap(ret.x, ret.y);
	return ret;
}

line getl() {
	line ret;
	ret.x = getp(), ret.y = getp();
	if (ret.x > ret.y) swap(ret.x, ret.y);
	return ret;
}

int intersect(const line& a, const line& b) { // 0 교차하지 않음, 1 교점이 하나 -1 교점이 무수히 많음
	int ab = sign(ccw(a.x, a.y, b.x)) * sign(ccw(a.x, a.y, b.y));
	int ba = sign(ccw(b.x, b.y, a.x)) * sign(ccw(b.x, b.y, a.y));
	if (!ab && !ba) {
		if (a.x > b.y || a.y < b.x) return 0;
		else if (a.x == b.y || a.y == b.x) return 1;
		return -1;
	}
	return ab <= 0 && ba <= 0;
}

using rect = pair<point, point>;

rect getr() {
	rect ret;
	ret.x = getp();
	ret.y = getp();
	if (ret.x.x > ret.y.x) swap(ret.x.x, ret.y.x);
	if (ret.x.y > ret.y.y) swap(ret.x.y, ret.y.y);
	return ret;
}

bool pointInBox(const point& a, const rect& b) {
	return b.x.x <= a.x && a.x <= b.y.x && b.x.y <= a.y && a.y <= b.y.y;
}

bool pointInLine(const point& a, const line& b,int not_use) {
	return sign(ccw(b.x, b.y, a)) == 0 && pointInBox(a, b);
}

int intersect(const line& a, const rect& b,int not_use) { // 교점의 수 , 4 무수히 많은 교점
	int ret = 0;
	point p[4] = { b.x,{b.x.x,b.y.y},b.y,{b.y.x,b.x.y} };
	for (int i = 0; i < 4; i++) {
		int res = intersect(a, makel(p[i], p[(i + 1) % 4]));
		if (res == -1) return 4;
		else if(res == 1 && !pointInLine(p[i],a,NULL))
			ret++;
	}
	return ret;
}

int tc;

int main() {
	scanf("%d", &tc);
	while (tc--) {
		rect r = getr();
		line l = getl();
		printf("%d\n", intersect(l, r, NULL));
	}
	return 0;
}
