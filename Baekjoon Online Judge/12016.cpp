#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int sum(vector<int>& a, int x) {
	int ret = 0;
	for (int i = x; i > 0; i -= (i & -i))
		ret += a[i];
	return ret;
}

void update(vector<int>& a, int x, int v) {
	for (int i = x; i < a.size(); i += (i & -i))
		a[i] += v;
}

int sum(vector<int>& a, int i, int j) {
	if (i > j) return 0;
	return sum(a, j) - sum(a, i - 1);
}


int main() {

	int n;
	scanf("%d", &n);

	vector<pair<int, int>> a(n + 1);
	vector<int> tree(n + 1);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
		update(tree, i, 1);
	}

	sort(begin(a) + 1, end(a));

	long long total = 0;
	int last = 0, remain = n;
	vector<long long> ans(n + 1);

	for (int i = 1; i <= n; i++) {
		total += (long long)(a[i].first - last) * remain;
		remain--;
		last = a[i].first;
		ans[a[i].second] = total - (long long)sum(tree, a[i].second + 1, n);
		update(tree, a[i].second, -1);
	}
	for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);

	return 0;
}