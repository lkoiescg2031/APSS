#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int n, m;
vector<int> a, tree, pos;

void update(int x, int diff) {
	for (int i = x; i < tree.size(); i += (i & -i))
		tree[i] += diff;
}
int sum(int x) {
	int ret = 0;
	for (int i = x; i > 0; i -= (i & -i))
		ret += tree[i];
	return ret;
}

int main() {

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		tree = vector<int>(n + m + 1);
		pos = vector<int>(n + 1);
		for (int i = 1; i <= n; i++) {
			update(m + i, 1);
			pos[i] = m + i;
		}
		for (int i = m; i >= 1; i--) {
			int x;
			scanf("%d", &x);
			printf("%d ", sum(pos[x] - 1));
			update(pos[x], -1);
			pos[x] = i;
			update(i, 1);
		}
		printf("\n");
	}

	return 0;
}