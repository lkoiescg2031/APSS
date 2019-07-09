#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 1000000;

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

	int h = (int)ceil(log2(MAX + 1));
	int size = 1 << (h + 1);
	vector<int> tree(size);

	int n, a, b, c;
	scanf("%d", &n);

	while (n--) {
		scanf("%d %d", &a, &b);
		if (a == 2) {
			scanf("%d", &c);
			update(tree, 1, 1, MAX, b, c);
		} else {
			int box = nth(tree, 1, 1, MAX, b);
			printf("%d\n", box);
			update(tree,1,1,MAX,box,-1);
		}
	}

	return 0;
}