#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const int max = 100000;
int n, m;
vector<int> tree;
vector<bool> lazy;
int h, tree_size;

void lazy_update(int node, int start, int end) {
	if (lazy[node]) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[2 * node] = !lazy[2 * node];
			lazy[2 * node + 1] = !lazy[2 * node + 1];
		}
		lazy[node] = false;
	}
}

void update_range(int node, int start, int end, int i, int j) {
	lazy_update(node, start, end);
	if (end < i || j < start) return;
	if (i <= start && end <= j) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		return;
	}
	update_range(2 * node, start, (start + end) / 2, i, j);
	update_range(2 * node + 1, (start + end) / 2 + 1, end, i, j);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int sum(int node, int start, int end, int i, int j) {
	lazy_update(node, start, end);
	if (end < i || j < start) return 0;
	if (i <= start && end <= j) return tree[node];
	return sum(2 * node, start, (start + end) / 2, i, j) +
		sum(2 * node + 1, (start + end) / 2 + 1, end, i, j);
}

int main() {

	scanf("%d %d", &n, &m);

	h = ceil(log2(n)) + 1;
	tree_size = (1 << (h + 1));
	tree = vector<int>(tree_size, 0);
	lazy = vector<bool>(tree_size, false);

	int t1, t2, t3;
	while (m--) {
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t1 == 0) update_range(1, 0, n - 1, t2 - 1, t3 - 1);
		else printf("%d\n", sum(1, 0, n - 1, t2 - 1, t3 - 1));
	}
	return 0;
}