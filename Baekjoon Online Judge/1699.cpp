#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000

int N;
int dp[MAX + 1];

int main() {

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		dp[i] = i;//�ʱ�ȭ ����
		for (int j = 1; j*j <= i; j++)//dp �Ŀ���
			dp[i] = min(dp[i], dp[i - j * j] + 1);			
	}

	std::cout << dp[N];

	return 0;
}