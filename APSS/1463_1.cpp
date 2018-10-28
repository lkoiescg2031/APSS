#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 1000000

int N;
int dp[MAX + 1];

int solve(int n) {
	int &ret = dp[n];

	if (ret != 0x3f3f3f3f)//�̹� ����� ������ �ٽ� ����Ͽ� Ÿ�Ӹ���
		return ret;
	else if (n == 1)
		return dp[n] = 0;

	ret = min(ret, solve(n - 1) + 1);

	if (!(n % 3))//������ �켱���� �Ǽ� !�� %���� ����
		ret = min(ret, solve(n / 3) + 1);
	if (!(n % 2))
		ret = min(ret, solve(n / 2) + 1);

	return ret;
}

int main() {
	
	memset(dp, 0x3f, sizeof(dp));
	cin >> N;
	cout << solve(N);

	return 0;
}