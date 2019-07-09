#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 65535;

void update(vector<int>& tree, int node, int start, int end, int i, int diff) {
	if (i > end || i < start) {
		return;
	}
	tree[node] += diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, i, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, diff);
	}
}
int kth(vector<int>& tree, int node, int start, int end, int k) {
	if (start == end) return start;
	if (k <= tree[node * 2]) return kth(tree, node * 2, start, (start + end) / 2, k);
	return kth(tree, node * 2 + 1, (start + end) / 2 + 1, end, k - tree[node * 2]);
}

int main() {

	int h = (int)ceil(log2(MAX + 1));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);

	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> a(n);
	for (auto& i : a) scanf("%d", &i);

	for (int i = 0; i < k - 1; i++) 
		update(tree, 1, 0, MAX, a[i], 1);

	long long ans = 0;
	for (int i = k - 1; i < n; i++) {
		update(tree, 1, 0, MAX, a[i], 1);
		ans += (long long)kth(tree, 1, 0, MAX, (k + 1) / 2);
		update(tree, 1, 0, MAX, a[i - k + 1], -1);
	}
	printf("%lld\n", ans);
	return 0;
}