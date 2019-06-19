#include <cstdio>

int n, m;
long long a[1025][1025], tree[1025][2025];

void update(int x,int y, long long diff) {
	for (int i = x; i <= n; i += (i & -i))
		for (int j = y; j <= n; j += (j & -j))
			tree[i][j] += diff;
}
long long sum(int x, int y) {
	long long ret = 0;
	for (int i = x; i > 0; i -= (i & -i))
		for (int j = y; j > 0; j -= (j & -j))
			ret += tree[i][j];
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
			update(i, j, a[i][j]);
		}

	int t1, t2, t3, t4, t5;
	while (m--) {
		scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
		if (t1 == 0) {
			update(t2, t3, t4 - a[t2][t3]);
			a[t2][t3] = t4;
		} else {
			scanf("%d", &t5);
			printf("%lld\n", sum(t4, t5) 
				- sum(t2 - 1, t5) - sum(t4, t3 - 1) 
				+ sum(t2 - 1, t3 - 1));
		}		
	}
	return 0;
}