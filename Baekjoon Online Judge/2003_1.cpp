#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, arr[10000];

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);

	int l=0 ,r = 0;
	long long sum = arr[0], ans = 0;
	while (l <= r && r < n) {
		if (sum == m) ans++;
		if (sum <= m) sum += arr[++r];//같은경우 기본 조건이 l<=r 이므로  r을 증가
		else {
			sum -= arr[l++];
			if (l > r && l < n) {//한숫자만 있는데 m보다 큰경우 l>r이 됨
				r = l;
				sum = arr[l];
			}
		}
	}

	printf("%lld", ans);
	return 0;
}