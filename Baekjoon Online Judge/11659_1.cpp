#include <cstdio>
#include <vector>
using namespace std;

template<typename T = int>
using BIT = vector<T>;

template<typename T = int>
void init_tree(BIT<T> & tree, int terminal_node_size, T value) {
	tree = BIT<T>(terminal_node_size + 1, value);
}

template<typename T = int>
void update(BIT<T> & tree, int i, T diff) {
	while (i < tree.size())
		tree[i] += diff, i += (i & -i);
}

template<typename T = int>
T sum(BIT<T> & tree, int i) {
	T ret = 0;
	while (i > 0)
		ret += tree[i], i -= (i & -i);
	return ret;
}

template<typename T = int>
T sum(BIT<T> & tree, int i, int j) {
	if (j < i) return 0;
	return sum(tree, j) - sum(tree, i - 1);
}

int main() {

	int N, M;
	scanf("%d %d", &N, &M);
	BIT<int> tree;
	init_tree(tree, N, 0);

	int t;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &t);
		update(tree, i, t);
	}
	int i, j;
	while (M--) {
		scanf("%d %d", &i, &j);
		printf("%d\n", sum(tree, i, j));
	}
	return 0;
}