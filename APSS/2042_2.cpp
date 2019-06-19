#include <cstdio>

int n, m, k;
long long a[1000001], tree[1000001];

long long sum(int x) {
	long long ret = 0;
	for (int i = x; i > 0; i -= (i & -i))
		ret += tree[i];
	return ret;
}

void update(int x,long long diff) {
	for (int i = x; i <= n; i += (i & -i))
		tree[i] += diff;
}

int main() {

	scanf("%d %d %d", &n, &m, &k);
	m += k;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		update(i, a[i]);
	}

	int t1, t2;
	long long t3;
	while (m--) {
		scanf("%d %d %lld", &t1, &t2, &t3);
		if (t1 == 1) {
			update(t2, t3 - a[t2]);
			a[t2] = t3;
		} else printf("%lld\n", sum(t3) - sum(t2 - 1));
	}
	return 0;
}