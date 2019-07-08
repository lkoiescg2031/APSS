#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const long long mod = 1000000007;
const int MAX = 200000;

void update(vector<long long>& tree,int x, int diff) {
	for (int i = x; i < tree.size(); i += (i & -i))
		tree[i] += diff;
}
long long sum(vector<long long>& tree, int x) {
	long long ret = 0;
	for (int i = x; i > 0; i -= (i & -i))
		ret += tree[i];
	return ret;
}
long long sum(vector<long long>& tree, int i, int j) {
	if (i > j) return 0;
	return sum(tree, j) - sum(tree, i - 1);
}

int main() {

	int n;
	vector<long long> cnt(MAX + 1), dist(MAX + 1);

	scanf("%d", &n);

	long long x, ans = 1;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		x++;
		if (i != 0) {
			long long cost = x * (sum(cnt, x - 1) - sum(cnt, x + 1, MAX)) - sum(dist, x - 1) + sum(dist, x + 1, MAX);
			ans *= cost % mod;
			ans %= mod;
		}
		update(cnt, x, 1);
		update(dist, x, x);
	}
	printf("%lld", ans);
	return 0;
}