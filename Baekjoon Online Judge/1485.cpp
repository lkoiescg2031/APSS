#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,j,k) for(int i = (j); i<(k);i++)

typedef long long ll;

using point = pair<ll, ll>;
#define x first
#define y second

point getp() {
	point ret;
	scanf("%lld %lld", &ret.x, &ret.y);
	return ret;
}

long long dist(const point& a, const point& b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int tc;

int main() {

	scanf("%d", &tc);
	while (tc--) {
		point p[4];
		FOR(i, 0, 4) p[i] = getp();

		vector<ll> d;		
		FOR(i, 0, 4) FOR(j, i + 1, 4) d.push_back(dist(p[i], p[j]));
		sort(begin(d), end(d));
		printf("%d\n", (d[0] == d[1] && d[2] == d[3] && d[3] == d[4] && d[4] == d[5]) || 
			(d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5]));
	}
	return 0;
}