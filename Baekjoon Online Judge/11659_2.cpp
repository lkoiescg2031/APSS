#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

void init(vector<int>& t, vector<int>& arr, int node, int b, int e) {
	if (b == e) {
		t[node] = arr[b];
		return;
	}
	init(t, arr, node * 2, b, (b + e) / 2);
	init(t, arr, node * 2 + 1, (b + e) / 2 + 1, e);
	t[node] = t[node * 2] + t[node * 2 + 1];
}

int query(vector<int>& t, int node, int b, int e, int i, int j) {
	if (e < i || j < b) return 0;
	if (i <= b && e <= j) return t[node];
	return query(t, node * 2, b, (b + e) / 2, i, j)
		+ query(t, node * 2 + 1, (b + e) / 2 + 1, e, i, j);
}

int main() {

	int N, M;
	scanf("%d %d", &N, &M);

	vector<int> a(N);
	for (auto& i : a) scanf("%d", &i);

	int h = (int)ceil(log2(N));
	int size = 1 << (h + 1);
	vector<int> tree(size);
	init(tree, a, 1, 0, N - 1);

	int i, j;
	while (M--) {
		scanf("%d %d", &i, &j);
		printf("%d\n", query(tree, 1, 0, N-1, i-1, j-1));
	}
	return 0;
}