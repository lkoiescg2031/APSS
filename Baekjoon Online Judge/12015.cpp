#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

int n;
vector<int> tree;

int query(int node, int start, int end, int i, int j) {
	if (end < i || j < start) return 0;
	if (i <= start && end <= j) return tree[node];
	return max(query(2 * node, start, (start + end) / 2, i, j),
		query(2 * node + 1, (start + end) / 2 + 1, end, i, j));
}

void update(int node, int start, int end, int i, int value) {
	if (i > end || i < start) return;
	tree[node] = max(tree[node], value);
	if(start != end){
		update(node * 2, start, (start + end) / 2, i, value);
		update(node * 2 + 1, (start + end) / 2 + 1, end, i, value);
	}
}

int main() {

	int tree_high = ceil(log2(MAX));
	int tree_size = 1 << (tree_high + 1);
	tree.resize(tree_size);

	int ans = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		int range_max = query(1, 1, MAX, 1, t - 1);
		ans = max(range_max + 1, ans);
		update(1, 1, MAX, t, range_max + 1);
	}
	printf("%d", ans);
	return 0;
}