#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a, tree;
vector<int> pos;

void update(int x, int diff) {
	for (int i = x; i <= n; i += (i & -i))
		tree[i] += diff;
}

int sum(int x) {
	int ret = 0;
	for (int i = x; i > 0; i -= (i & -i))
		ret += tree[i];
	return ret;
}

int sum(int i, int j) {
	return sum(j) - sum(i - 1);
}

int main() {

	scanf("%d", &n);
	
	a.resize(n + 1);
	tree.resize(n + 1);
	pos.resize(n + 1);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
		update(i, 1);
	}

	int left = 1;
	int right = n;
	for (int i = 1; i <= n; i++)
		if (i % 2) {
			update(pos[left], -1);
			printf("%d\n", sum(1, pos[left]));
			left++;
		} else {
			update(pos[right], -1);
			printf("%d\n", sum(pos[right], n));
			right--;
		}

	return 0;
}