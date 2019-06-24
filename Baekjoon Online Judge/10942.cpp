#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, arr[2001];
int dp[2001][2001];
int q, b, e;

int go(int s, int f) {
	if (dp[s][f] != -1) return dp[s][f];
	else if (s == f) return dp[s][f] = 1;
	else if (s + 1 == f) return dp[s][f] = arr[s] == arr[f];
	return dp[s][f] = arr[s] == arr[f] && go(s + 1, f - 1);
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &q);
	memset(dp, -1, sizeof(dp));
	while (q-- > 0) {
		scanf("%d %d", &b, &e);
		printf("%d\n", go(b,e));
	}
	return 0;
}