#include <cstdio>
int n, m, k, tn = 1;
long long tree[3000000];
void update(int i, long long num) {
	long long diff;
	i += tn, diff = num - tree[i];
	while (i >= 1) tree[i] += diff, i /= 2;
}
long long sum(int i, int j) {
	long long ret = 0;
	i += tn;j += tn;
	while (i < j) {
		if (i % 2 == 0) i /= 2;
		else ret += tree[i], i = (i + 1) / 2;
		if (j % 2 == 1) j /= 2;
		else ret += tree[j], j = (j - 1) / 2;
	}
	if (i == j) ret += tree[i];
	return ret;
}
int main() {

	scanf("%d %d %d", &n, &m, &k);
	m += k;
	while (tn <= n) tn *= 2; tn--;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		update(i, k);
	}

	while (m--) {
		long long  a1, a2, a3;
		scanf("%lld %lld %lld", &a1, &a2, &a3);
		if (a1 == 1) update(a2-1, a3);
		else printf("%lld\n", sum(a2-1, a3-1));
	}
	return 0;
}