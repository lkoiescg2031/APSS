#include <cstdio>

int n, m;
long long a[1000001];
long long b[1000];

int main() {

	int t;

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		a[i] = a[i - 1] + t;
		a[i] = a[i] % m;
		b[a[i]]++;
	}
	b[0]++;

	long long ans = 0;
	for (int i = 0; i < m; i++) 
		ans += b[i] * (b[i] - 1)/ 2;
	
	printf("%lld", ans);
	return 0;
}