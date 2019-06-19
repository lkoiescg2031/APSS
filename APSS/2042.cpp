#include <cstdio>

const int max = 1000000;

int n, m, k;
long long a[max + 1];
long long tree[2097149];

long long init(int node, int src, int des) {
	if (src == des)	return tree[node] = a[src];
	return tree[node] = init(2 * node, src, (src + des) / 2) +
		init(2 * node + 1, (src + des) / 2 + 1, des);
}
void update(int loc, long long diff, int node = 1, int src = 1, int des = n) {
	if (loc < src || des < loc) return;
	tree[node] += diff;
	if (src != des) {
		update(loc, diff, 2 * node, src, (src + des) / 2);
		update(loc, diff, 2 * node + 1, (src + des) / 2 + 1, des);
	}
}
long long sum(int i, int j, int node = 1, int src = 1, int des = n) {
	if (des < i || j < src) return 0;
	if (i <= src && des <= j) return tree[node];
	return sum(i, j, node * 2, src, (src + des) / 2) +
		sum(i, j, node * 2 + 1, (src + des) / 2 + 1, des);
}
int main() {

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	m += k;
	init(1, 1, n);

	long long c1 = 0, c2 = 0, c3 = 0;
	while (m--) {
		scanf("%lld %lld %lld", &c1, &c2, &c3);
		if (c1 == 1) {
			update(c2, c3 - a[c2]);
			a[c2] = c3;
		}else printf("%lld\n", sum(c2, c3));
	}

	return 0;
}