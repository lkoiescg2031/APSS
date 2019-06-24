#include <cstdio>

int n, m, a[101];

int find(int x) {
	if (x == a[x])
		return x;
	return a[x] = find(a[x]);
}
void merge(int x, int y) {
	int px = find(x);
	int py = find(y);
	a[px] = py;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) a[i] = i;
	
	while (m-- > 0) {
		int x, y;
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	int ans = 0;
	int target = find(1);
	for (int i = 2; i <= n; i++)
		ans += find(i) == target;
	printf("%d", ans);
	return 0;
}