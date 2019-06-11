#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
int coin[101];
int dp[10001];

int main() {
	
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
		scanf("%d", &coin[i]);

	memset(dp, 0x3f3f3f3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= k; j++)
			if (j - coin[i] >= 0) dp[j] = min(dp[j], dp[j - coin[i]] + 1);
	printf("%d", dp[k] == 0x3f3f3f3f ? -1 : dp[k]);
	return 0;
}