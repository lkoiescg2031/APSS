#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

void init(vector<int>& tree, int node, vector<int>& terminal, int s, int e) {
	if (s == e) {
		tree[node] = terminal[s];
		return;
	}
	init(tree, node * 2, terminal, s, (s + e) / 2);
	init(tree, node * 2 + 1, terminal, (s + e) / 2 + 1, e);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(vector<int>& tree, int node, int b, int e, int i, int diff) {
	if (i < b || e < i) return;
	tree[node] += diff;
	if (b != e) {
		update(tree, node * 2, b, (b + e) / 2, i, diff);
		update(tree, node * 2 + 1, (b + e) / 2 + 1, e, i, diff);
	}
}

int nth(vector<int>& tree, int node, int b, int e, int n) {
	if (b == e) return b;
	if (n <= tree[node * 2]) return nth(tree, node * 2, b, (b + e) / 2, n);
	return nth(tree, node * 2 + 1, (b + e) / 2 + 1, e, n - tree[node * 2]);
}

int main() {

	int n, k;
	scanf("%d", &n);

	int h = (int)ceil(log2(n));
	int size = 1 << (h + 1);
	vector<int> tree(size);
	vector<int> ans(n + 1, 1);
	init(tree, 1, ans, 1, n);

	for(int i=1;i<=n;i++){
		scanf("%d", &k);
		int kth = nth(tree, 1, 1, n, k+1);
		ans[kth] = i;
		update(tree, 1, 1, n, kth, -1);
	}

	for (int i = 1; i <= n; i++) 
		printf("%d\n", ans[i]);

	return 0;
}