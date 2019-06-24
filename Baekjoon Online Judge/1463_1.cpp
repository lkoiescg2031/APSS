#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 1000000

int N;
int dp[MAX + 1];

int solve(int n) {
	int &ret = dp[n];

	if (ret != 0x3f3f3f3f)//이미 계산한 구문은 다시 계산하여 타임리밋
		return ret;
	else if (n == 1)
		return dp[n] = 0;

	ret = min(ret, solve(n - 1) + 1);

	if (!(n % 3))//연산자 우선순위 실수 !가 %보다 높음
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