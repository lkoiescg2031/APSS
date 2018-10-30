#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int (i) = 0;(i)<(n);(i)++)
#define MAX 15

int working_day;
int dp[MAX + 1]; //dp[day] = day일 까지 했을 때 벌수 있는 최대 금액

int main() {

	ios_base::sync_with_stdio(false);
	
	int time, price;
	cin >> working_day;
	FOR(i, working_day) {
		cin >> time >> price;
		//일을 수락하는 경우
		if(i+time <= working_day)//수락할 수 있는 경우
			dp[i + time] = max(dp[i + time], dp[i] + price);
		//수락하지 않는 경우
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	cout << dp[working_day];

	return 0;
}