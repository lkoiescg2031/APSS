#include <cstdio>

int n;
long long m, arr[10001], subsum[10001];

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		subsum[i] = subsum[i - 1] + arr[i];
	}

	long long ans = 0;
	for (int st = 1; st <= n; st++) {
		if (subsum[n] - subsum[st - 1] < m)
			break;
		for (int ed = st; ed <= n; ed++) {
			if (subsum[ed] - subsum[st - 1] == m) {
				ans++;
				break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}