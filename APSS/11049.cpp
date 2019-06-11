#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, arr[501],t;
int dp[501][501];

int go(int b, int e) {
	if (dp[b][e] != 0x3f3f3f3f) return dp[b][e];
	else if (b + 1 == e) return dp[b][e] = 0;
	else if (b + 2 == e) return dp[b][e] = arr[b] * arr[b + 1] * arr[e];
	for (int i = b + 1; i < e; i++)
		dp[b][e] = min(dp[b][e], go(b,i) + go(i,e) + arr[b] * arr[i] * arr[e]);
	return dp[b][e];
}

int main() {

	scanf("%d", &n);
	scanf("%d", &arr[0]);
	for (int i = 1; i < n; i++)
		scanf("%d %d", &arr[i], &t);
	scanf("%d", &arr[n]);
	
	memset(dp, 0x3f3f3f3f,sizeof(dp));
	printf("%d", go(0, n));

	return 0;
}