#include <cstdio>
int n, s, a[20], ans;
int main() {

	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				sum += a[j];
		ans += sum == s;
	}
	printf("%d", ans);
	return 0;
}