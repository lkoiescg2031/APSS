#include <cstdio>
#include <vector>
using namespace std;

int n;
int pos[1000001];
vector<int> tree;

void update(int x, int diff) {
	for (int i = x; i < tree.size(); i += (i & -i))
		tree[i] += diff;
}
int sum(int x) {
	int ret = 0;
	for(int i=x;i>0;i-=(i&-i))
		ret += tree[i];
	return ret;
}
int sum(int i, int j) {
	if (i > j) return 0;
	return sum(j) - sum(i - 1);
}

int main() {

	int x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		pos[x] = i;
	}
	tree.resize(n + 1);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		ans += (long long)sum(pos[x] + 1, n);
		update(pos[x], 1);
	}
	printf("%lld\n", ans);
	return 0;
}