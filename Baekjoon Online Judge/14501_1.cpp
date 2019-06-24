#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int (i) = 0;(i)<(n);(i)++)
#define MAX 15

int working_day;
int dp[MAX + 1]; //dp[day] = day�� ���� ���� �� ���� �ִ� �ִ� �ݾ�

int main() {

	ios_base::sync_with_stdio(false);
	
	int time, price;
	cin >> working_day;
	FOR(i, working_day) {
		cin >> time >> price;
		//���� �����ϴ� ���
		if(i+time <= working_day)//������ �� �ִ� ���
			dp[i + time] = max(dp[i + time], dp[i] + price);
		//�������� �ʴ� ���
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	cout << dp[working_day];

	return 0;
}