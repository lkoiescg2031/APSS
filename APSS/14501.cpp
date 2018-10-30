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

	return 0;
}