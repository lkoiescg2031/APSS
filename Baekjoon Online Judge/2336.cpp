#include <cstdio>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

struct grade {
	int a, b, c;
	bool operator< (const grade& rhs) const {
		return b < rhs.b;
	}
};

int n;
vector<grade> a;
vector<int> tree;

int query(int node, int b, int e, int i, int j) {
	if (e < i || j < b) return n+1;
	if (i <= b && e <= j) return tree[node];
	return min(query(node * 2, b, (b + e) / 2, i, j),
		query(node * 2 + 1, (b + e) / 2 + 1, e, i, j));
}

void update(int node, int b, int e, int i, int v) {
	if (e < i || i < b) return;
	tree[node] = min(tree[node], v);
	if (b != e) {
		update(node * 2, b, (b + e) / 2, i, v);
		update(node * 2 + 1, (b + e) / 2 + 1, e, i, v);
	}
}

int main() {

	int x;
	scanf("%d", &n);
	a.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &x), a[x-1].a = i + 1;
	for (int i = 0; i < n; i++)
		scanf("%d", &x), a[x-1].b = i + 1;
	for (int i = 0; i < n; i++)
		scanf("%d", &x), a[x-1].c = i + 1;

	sort(begin(a), end(a));

	int h = ceil(log2(n));
	int tree_size = 1 << (h + 1);
	tree.resize(tree_size, 0x3f3f3f3f);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int res = query(1, 1, n, 1, a[i].a);
		if (res > a[i].c) ans++;
		update(1, 1, n, a[i].a, a[i].c);
	}
	printf("%d", ans);
	return 0;
}