#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

using point = pair<int, int>;
#define x_ first
#define y_ second

int n;
vector<point> a;

int dist(point& a, point& b) {
	return (a.x_ - b.x_) * (a.x_ - b.x_) + (a.y_ - b.y_) * (a.y_ - b.y_);
}

int solve(int b, int e) {
	int ret = -1;
	if (e - b + 1 <= 3) {
		for (int i = b; i <= e - 1; i++)
			for (int j = i + 1; j <= e; j++) {
				int d = dist(a[i], a[j]);
				if (ret == -1 || d < ret)
					ret = d;
			}
		return ret;
	}

	int m = (b + e) / 2;
	ret = min(solve(b, m), solve(m + 1, e));

	vector<point> p;
	for (int i = b; i <= e; i++) {
		int d = a[i].x_ - a[m].x_;
		if (d * d < ret)
			p.push_back(a[i]);
	}
	sort(begin(p), end(p), [](point & a, point & b) {
		return a.y_ < b.y_;
		});
	int len = p.size();
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j++) {
			int d = p[j].y_ - p[i].y_;
			if (d * d < ret)
				ret = min(ret, dist(p[i], p[j]));
			else break;
		}
	return ret;
}

int main() {

	scanf("%d", &n);
	a = vector<point>(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i].x_, &a[i].y_);
	sort(begin(a), end(a));
	printf("%d", solve(0, n - 1));
	return 0;
}