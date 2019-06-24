#include <cstdio>
#include <algorithm>
using namespace std;

int k, n;
long long arr[10000];
long long l = 1, r, ans;

long long cut(long long cut_size) {
	long long ret = 0;
	for (int i = 0; i < k; i++)
		ret += arr[i] / cut_size;
	return ret;
}

int main() {

	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%d", &arr[i]);
		r = max(r, arr[i]);
	}

	long long mid, num;
	while (l <= r) {
		mid = (l + r) / 2;
		num = cut(mid);
		if (num >= n) {
			ans = max(ans, mid);
			l = mid + 1;
		}else r = mid - 1;
	}

	printf("%lld", ans);

	return 0;
}