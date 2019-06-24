#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int arr[1000000];
int l, r,ans;
long long cut(int h) {
	long long ret = 0;
	for (int i = 0; i < n; i++)
		ret += max(0, arr[i] - h);
	return ret;
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]), r = max(r, arr[i]);

	while (l <= r) {
		int mid = ((long long)l + r) / 2;
		auto size = cut(mid);
		if (size >= m) {
			ans = max(ans, mid);
			l = mid + 1;
		}else r = mid - 1;
	}

	printf("%d", ans);

	return 0;
}