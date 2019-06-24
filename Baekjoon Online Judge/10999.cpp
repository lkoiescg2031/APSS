#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int n, m, k;
vector<long long> a, tree, lazy;
long long init(int node, int start, int end) {
	if (start == end) return tree[node] = a[start];
	return tree[node] =	init(node * 2, start, (start + end) / 2) +
		init(node * 2 + 1, (start + end) / 2 + 1, end);
}
void lazy_update(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
long long sum(int node, int start, int end, int i, int j) {
	lazy_update(node, start, end);
	if (end < i || j < start) return 0;
	if (i <= start && end <= j) return tree[node];
	return sum(2 * node, start, (start + end) / 2, i, j) +
		sum(2 * node + 1, (start + end) / 2 + 1, end, i, j);
}
void update_range(int node, int start, int end, int i, int j, long long diff) {
	lazy_update(node, start, end);
	if (end < i || j < start) return;
	if (i <= start && end <= j) {
		if (start != end) {
			lazy[2 * node] += diff;
			lazy[2 * node + 1] += diff;
		}
		tree[node] += (end - start + 1) * diff;
		return;
	}
	update_range(2 * node, start, (start + end) / 2, i, j, diff);
	update_range(2 * node + 1, (start + end) / 2 + 1, end, i, j, diff);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int main() {

	scanf("%d %d %d", &n, & m, &k);
	m += k;

	int tree_high = ceil(log2(n));
	int tree_size = (1 << (tree_high + 1));
	a = vector<long long>(n);
	tree = lazy = vector<long long>(tree_size);
	for (auto& i : a) scanf("%lld", &i);
	init(1, 0, n - 1);

	int i1, i2, i3;
	long long int i4;
	while (m--) {
		scanf("%d %d %d", &i1, &i2, &i3);
		if (i1 == 1) {
			scanf("%lld", &i4);
			update_range(1, 0, n - 1, i2 - 1, i3 - 1, i4);
		} else printf("%lld\n", sum(1, 0, n - 1, i2 - 1, i3 - 1));
	}

	return 0;
}