#include <cstdio>

//dp[i][k] : i번째 화폐 까지만 사용하여 k 금액을 만들수 있는 경우의 수
//dp[i][k] = dp[i-1][k] + dp[i][k - coin[i]]
//사실 상 dp[i-1][k] 가 하위 화폐를 덮어 쓰기만 하므로
//dp[k]인 1차원 배열에 값을 계속 누적 저장하여도 무방

int n, k;
int coin[101];
int dp[10001];

int main() {

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &coin[i]);

	dp[0] = 1;
	for(int i=1;i<=n;i++)
		for (int j = 0; j <= k; j++) 
			if (j - coin[i] >= 0) dp[j] += dp[j - coin[i]];

	printf("%d", dp[k]);

	return 0;
}