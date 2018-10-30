#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1000000 //10�� 6��

int N;
int dp[MAX + 1];

int main() {
	memset(dp, 0x3f, sizeof(dp));//header:: cstring
	dp[1] = 0;//�ʱ갪 �Ǽ� 1�� �̹� 1�̹Ƿ� 0ȸ�� ���
	dp[2] = dp[3] = 1;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (i + 1 <= N)
			dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if (i * 2 <= N)
			dp[i * 2] = min(dp[i * 2], dp[i] + 1);
		if (i * 3 <= N)
			dp[i * 3] = min(dp[i * 3], dp[i] + 1);
	}

	cout << dp[N];
	return 0;
}