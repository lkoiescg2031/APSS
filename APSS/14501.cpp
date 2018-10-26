#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int (i) = 0;(i)<(n);(i)++)
#define MAX 15

int working_day;
vector<pair<int, int>> list;


int recur(int day ,int sum) {

	int ret = sum;

	if (day >= working_day)
		return ret;

	if (day + list[day].first <= working_day) //일 할 수 있는 지 확인후 확인하는 경우를 확인
		ret = max(ret, recur(day + list[day].first, sum + list[day].second));

	//일을 하지 않는 경우
	ret = max(ret, recur(day + 1, sum));

	return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	
	cin >> working_day;
	list = vector<pair<int, int>>(working_day);
	FOR(i, working_day) cin >> list[i].first >> list[i].second;

	cout << recur(0, 0);

	return 0;
}