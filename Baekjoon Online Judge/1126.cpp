#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 250001;

int n;
int a[50];
int dp[50][inf];

int go(int k, int d) {
	if (d > 250000) return -inf;
	if (k == n) {
		if (d == 0) return 0;
		return -inf;
	}

	int& ret = dp[k][d];

	if (ret != -1) return ret;
	
	ret = go(k + 1, d);
	ret = max(ret, go(k + 1, d + a[k]));
	if (d > a[k]) ret = max(ret, go(k + 1, d - a[k]) + a[k]);
	else ret = max(ret, go(k + 1, a[k] - d) + d);
	
	return ret;
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	memset(dp, -1, sizeof(dp));
	
	if (go(0, 0) != 0) printf("%d", dp[0][0]);
	else printf("-1");

	return 0;
}