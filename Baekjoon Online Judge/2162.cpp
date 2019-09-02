#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(k,i,j) for(int k=i; k<j; k++)

struct disjoint_set {
	vector<int> _set;
	disjoint_set(int n) {
		_set.resize(n);
		for (int i = 0; i < n; i++)
			_set[i] = i;
	}
	int find(int index) {
		if (_set[index] == index) return index;
		return _set[index] = find(_set[index]);
	}
	void merge(int a, int b) {
		int set_a = this->find(a);
		int set_b = this->find(b);
		if (set_a != set_b) _set[set_a] = set_b;
	}
	void update() {
		for (int i = 0; i< _set.size(); i++) this->find(i);
	}
};
//math
template<typename T>
inline int sign(T a) {
	return a < 0 ? -1 : (a > 0);
}

using ll = long long;
//geometry
using point = pair<ll, ll>;
#define x first
#define y second

point getp() {
	point ret;
	scanf("%lld %lld", &ret.x, &ret.y);
	return ret;
}

ll ccw(const point& a, const point& b, const point& c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

using line = pair<point, point>;

line getl() {
	line a;
	a.x = getp();
	a.y = getp();
	if (a.x > a.y) swap(a.x, a.y);
	return a;
}

bool is_cross(const line& a, const line& b) {
	int ab = sign(ccw(a.x, a.y, b.x)) * sign(ccw(a.x, a.y, b.y));
	int ba = sign(ccw(b.x, b.y, a.x)) * sign(ccw(b.x, b.y, a.y));	
	if (!ab&&!ba) return a.x <= b.y && b.x <= a.y;
	return ab <= 0 && ba <= 0;
}

int n, bucket[3001], g;

int main() {

	scanf("%d", &n);
	vector<line> a(n);
	for (auto& i : a) i = getl();

	disjoint_set set(n);
	FOR(i, 0, n) FOR(j, i + 1, n)
		if (is_cross(a[i], a[j])) set.merge(i, j);

	set.update();
	for (auto i : set._set) g = max(g, ++bucket[i]);
	sort(begin(set._set), end(set._set));
	printf("%d\n%d", unique(begin(set._set), end(set._set)) - begin(set._set), g);
	return 0;
}