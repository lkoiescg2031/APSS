#include <cstdio>
int n, s, a[20];
int cnt(int i, int sum,int c) {
	int ret = 0;
	if (i == n)
		return c > 0 && sum == s;
	ret += cnt(i + 1, sum + a[i],c+1);
	ret += cnt(i + 1, sum, c);
	return ret;
}
int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%d", cnt(0, 0, 0));
	return 0;
}