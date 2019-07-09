#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

void init(vector<int>& tree, int node, int start, int end) {
	if (start == end) {
		tree[node] = 1;
		return;
	}
	init(tree, node * 2, start, (start + end) / 2);
	init(tree, node * 2 + 1, (start + end) / 2 + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void update(vector<int>& tree, int node, int start, int end, int i, int diff) {
	if (i > end || i < start) return;
	if (start == end) {
		tree[node] += diff;
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, i, diff);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int sum(vector<int>& tree, int node, int start, int end, int i, int j) {
	if (i > end || j < start) return 0;
	if (i <= start && end <= j) return tree[node];
	return sum(tree, node * 2, start, (start + end) / 2, i, j) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
int kth(vector<int>& tree, int node, int start, int end, int k) {
	if (start == end) return start;
	if (k <= tree[node * 2]) return kth(tree, node * 2, start, (start + end) / 2, k);
	return kth(tree, node * 2 + 1, (start + end) / 2 + 1, end, k - tree[node * 2]);
}
int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	int h = (int)ceil(log2(n));
	int size = (1 << (h + 1));
	vector<int> ans(n + 1);
	vector<int> tree(size);
	init(tree, 1, 1, n);

	int last = 0;
	printf("<");
	for (int i = n; i >= 1; i--) {
		int pre = last != 0 ? sum(tree, 1, 1, n, 1, last) : 0;
		int index = (pre + k) % i;
		if (index == 0) index = i;

		last = kth(tree, 1, 1, n, index);
		printf("%d", last);
		if (i != 1) printf(", ");
		update(tree, 1, 1, n, last, -1);
	}
	printf(">\n");
	return 0;
}