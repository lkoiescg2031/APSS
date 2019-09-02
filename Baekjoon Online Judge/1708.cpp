#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

using ll = long long;

int sign(ll i) {
	return i < 0 ? -1 : i>0;
}

using Point = pair<ll, ll>;
#define x first
#define y second

ll ccw(const Point& a, const Point& b, const Point& c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

istream& operator >> (istream& is, Point& p) {
	is >> p.x >> p.y;
	return is;
}

using Polygon = vector<Point>;

Polygon convexhull (Polygon& p) {
	int top = 0;
	Polygon ret(p.size() * 2);

	sort(begin(p), end(p));	
	for (int i = 0; i < p.size();i++) {
		while (top >= 2 && ccw(ret[top - 2], ret[top - 1], p[i]) <= 0) top--;
		ret[top++] = p[i];
	}


	for (int i = p.size() - 2,lower = top; i >= 0; i--) {
		while (top > lower && ccw(ret[top - 2], ret[top - 1], p[i]) <= 0) top--;
		ret[top++] = p[i];
	}
	ret.resize(top - 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	Polygon poly(n);
	for (auto& i : poly) cin >> i;
	cout << convexhull(poly).size();
	return 0;
}