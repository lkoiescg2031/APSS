#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n;
vector<int> a;
vector<int> tree;

int query(int node, int b, int e, int i, int j) {
	if (e < i || j < b) return 0;
	if (i <= b && e <= j) return tree[node];
	return max(query(node * 2, b, (b + e) / 2, i, j),
		query(node * 2 + 1, (b + e) / 2 + 1, e, i, j));
}

void update(int node, int b, int e, int i, int v) {
	if (e < i || i < b) return;
	tree[node] = max(tree[node], v);
	if (b != e) {
		update(node * 2, b, (b + e) / 2, i, v);
		update(node * 2 + 1, (b + e) / 2 + 1, e, i, v);
	}
}

int main() {

	scanf("%d", &n);
	a.resize(n);
	for (auto& i : a) scanf("%d", &i);

	vector<int> b = a;
	sort(begin(b), end(b));
	b.erase(unique(begin(b), end(b)), end(b));
	map<int, int> c;
	int terminal_node_size = b.size();
	for (int i = 0; i < terminal_node_size; i++) c[b[i]] = i + 1;
	for (int i = 0; i < a.size(); i++) a[i] = c[a[i]];

	int h = ceil(log2(terminal_node_size));
	int tree_size = 1 << (h + 1);
	tree.resize(tree_size);

	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		int range_max = query(1, 1, terminal_node_size, 1, a[i] - 1);
		ans = max(range_max + 1, ans);
		update(1, 1, terminal_node_size, a[i], range_max + 1);
	}
	printf("%d", ans);
	
	return 0;
}