#include <iostream>
using namespace std;

#define MAX 1000
#define MOD 10007
int dp[MAX];

int main() {

	int N;

	cin >> N;
	
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) //dp[2] = 3�̹Ƿ� �ʱⰪ ���� 2���Ͱ��
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;

	cout << dp[N];

	return 0;
}