#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

void init(vector<int>& tree,int node, vector<int>& terminal, int b, int e) {
	if (b == e) {
		tree[node] = terminal[b];
		return;
	}
	init(tree, node * 2, terminal, b, (b + e) / 2);
	init(tree, node * 2 + 1, terminal, (b + e) / 2 + 1, e);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int query(vector<int>& tree, int node, int b, int e, int i, int j) {
	if (e < i || j < b) return 1;
	if (i <= b && e <= j) return tree[node];
	return query(tree, node * 2, b, (b + e) / 2, i, j)
		* query(tree, node * 2 + 1, (b + e) / 2 + 1, e, i, j);
}

void update(vector<int>& tree, int node, int b, int e, int i, int v) {
	if (i < b || e < i) return;
	if (b == e) {
		tree[node] = v;
		return;
	}
	update(tree, node * 2, b, (b + e) / 2, i, v);
	update(tree, node * 2 + 1, (b + e) / 2 + 1, e, i, v);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int sign(int x) {
	if (x == 0) return 0;
	else if (x > 0) return 1;
	return -1;
}

int main() {

	int n, k;
	while (scanf("%d %d", &n, &k) != EOF) {
		int size = 1 << ((int)ceil(log2(n)) + 1);
		vector<int> a(n);
		vector<int> tree(size);
		for (auto& i : a) scanf("%d", &i),i = sign(i);
		init(tree, 1, a, 0, n - 1);
		char c;
		int i, j;
		while (k--) {
			scanf("\n%c %d %d", &c, &i, &j);
			if (c == 'C') {
				update(tree, 1, 0, n - 1, i - 1, sign(j));
			} else {
				int ans = query(tree, 1, 0, n - 1, i-1, j-1);
				if (ans == 0) printf("0");
				else if (ans > 0)printf("+");
				else printf("-");
			}
		}
		printf("\n");
	}

	return 0;
}