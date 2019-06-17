#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long arr[100000], m;

int main() {

	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int l = 0, r = 0, ans = 0x3f3f3f3f;
	long long sum = arr[0];

	while (l <= r && r < n) {
		if (sum >= m) 
			ans = min(ans, r - l + 1);
		if (sum <= m) 
			sum += arr[++r];
		else {
			sum -= arr[l++];
			if (l > r && l < n) 
				r = l, sum = arr[r];
		}
	}
	
	if (ans == 0x3f3f3f3f) printf("0");
	else printf("%d", ans);

	return 0;
}