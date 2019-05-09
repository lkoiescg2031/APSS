#include <cstdio>
#include <algorithm>
using namespace std;

int n, c;
int arr[200000];
int l = 1, r;
int ans;
int install(int dist) {
	int ret = 1;
	int pre = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] - pre >= dist)
			pre = arr[i], ret++;
	return ret;
}
int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	r = arr[n - 1] - arr[0];
	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = install(mid);
		if (cnt >= c) {
			ans = max(mid, ans);
			l = mid + 1;
		} else r = mid - 1;
	}
	printf("%d", ans);

	return 0;
}