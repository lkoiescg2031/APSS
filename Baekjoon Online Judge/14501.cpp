<<<<<<< HEAD
#include  <cstdio>
#include  <utility>
#include  <vector>
#include  <algorithm>
using namespace std;

#define FOR(x,n) for(int (x)=0;(x)<(n);++(x))

struct work {
	int index, time, price;
};

int N;
vector<work> schedule;

vector<int> day;
int ans;

int main() {

	scanf("%d", &N);
	schedule = vector<work>(N);

	FOR(i, N) {
		scanf("%d %d", &schedule[i].time, &schedule[i].price);
		schedule[i].index = i;
	}
	sort(schedule.begin(), schedule.end(), [](const work& a,const work& b) -> bool {
		if (a.time*b.price == a.price*b.time)
			return a.price  b.price;
		return a.time*b.price < a.price*b.time;
	});

	day = vector<int>(N);
	FOR(i, N) {
		bool is_work = true;
		work w = schedule[i];
		
		if (w.time + w.index > N)
			continue;
	    FOR(j,w.time) if (day[w.index + j] == 1) {
			is_work = false;
			break;
		}
		if (is_work) {
			ans += w.price;
			FOR(j, w.time) {
				day[w.index + j] = 1;
			}
		}
	}
	printf("%d", ans);
=======
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
>>>>>>> 81c56e78e130692d6af93adfed821eb30144615c

	return 0;
}