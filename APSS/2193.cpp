#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 90

long long dp[MAX + 1][2];//�����÷ο�
long long dp2[MAX];

int main() {

	int N;

	ios_base::sync_with_stdio(false);
	cin >> N;
	dp2[0]=dp2[1]=dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {

		dp[i][1] = dp[i - 1][0];
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];

		//�Ǻ���ġ ����
		dp2[i] = dp2[i - 1] + dp2[i - 2];
	}
	cout << dp[N][0] + dp[N][1];
	return 0;
}