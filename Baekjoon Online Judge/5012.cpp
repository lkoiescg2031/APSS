#include <cstdio>
#include <vector>
using namespace std;

void update(vector<int>& tree, int i, int diff) {
	while (i < tree.size()) 
		tree[i] += diff,i += (i & -i);
}
int sum(vector<int>& tree, int i) {
	int ret = 0;
	while (i > 0)
		ret += tree[i], i -= (i & -i);
	return ret;
}
int sum(vector<int>& tree, int i, int j) {
	if (i > j) return 0;
	return sum(tree,j) - sum(tree,i - 1);
}

int main() {
	int n;
	vector<int> l, r, a;
	vector<int> t1, t2;

	scanf("%d", &n);
	l = r = a = t1 = t2 = vector<int>(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	for (int i = 1; i <= n; i++) {
		update(t2, a[i], 1);
		r[i] = sum(t2, a[i] + 1, n);
	}

	for (int i = n; i > 0; i--) {
		update(t1, a[i], 1);
		l[i] = sum(t1, a[i] - 1);
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += (long long)l[i] * (long long)r[i];
	printf("%lld", ans);
	return 0;
}