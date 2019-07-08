#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const static int null = -1;

int n;
vector<int> a;
vector<int> tree;

void init(int node, int b, int e) {
	if (b == e) {
		tree[node] = b;
		return;
	}
	init(node * 2, b, (b + e) / 2);
	init(node * 2 + 1, (b + e) / 2 + 1, e);
	if (a[tree[node * 2]] > a[tree[node * 2 + 1]]) tree[node] = tree[node * 2 + 1];
	else tree[node] = tree[node * 2];
}

int query(int node, int b, int e, int i, int j) {
	if (e < i || j < b) return null;
	else if (i <= b && e <= j) return tree[node];
	int left = query(node * 2, b, (b + e) / 2, i, j);
	int right = query(node * 2 + 1, (b + e) / 2 + 1, e, i, j);
	if (left == null) return right;
	else if (right == null) return left;
	else {
		if (a[left] > a[right]) return right;
		else return left;
	}
}

long long go(int b, int e) {
	int loc = query(1, 0, n - 1, b, e);
	long long height = a[loc];
	long long area = height * (long long)(e - b + 1);
	if (b <= loc - 1) area = max(area, go(b, loc - 1));
	if (e >= loc + 1) area = max(area, go(loc + 1, e));
	return area;
}

int main() {
	while (scanf("%d", &n) && n != 0) {
		a.resize(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int tree_height = ceil(log2(n));
		int tree_size = 1 << (tree_height + 1);
		tree.resize(tree_size);
		init(1, 0, n - 1);
		printf("%lld\n", go(0, n - 1));
	}
	return 0;
}