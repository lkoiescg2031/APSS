#include <cstdio>

//dp[i][k] : i��° ȭ�� ������ ����Ͽ� k �ݾ��� ����� �ִ� ����� ��
//dp[i][k] = dp[i-1][k] + dp[i][k - coin[i]]
//��� �� dp[i-1][k] �� ���� ȭ�� ���� ���⸸ �ϹǷ�
//dp[k]�� 1���� �迭�� ���� ��� ���� �����Ͽ��� ����

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