#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define MAX 20

int N;
int map[MAX + 1][MAX + 1];

int team[2][MAX / 2];
int top[2];
int power[2];

int solve(int cnt) {
	int ret = 0x7fffffff;
	if (cnt > N) {
		if (top[0] + top[1] != N)
			return 0x7fffffff;
		FOR(i, 2){
			power[i] = 0;
			FOR(j, top[i])FOR(k, top[i]) 
				power[i] += map[team[i][j]][team[i][k]];			
		}
		return abs(power[0]-power[1]);
	}

	FOR(i,2) {
		if (top[i] >= N / 2)
			continue;

		team[i][top[i]++] = cnt;
		ret = min(ret, solve(cnt + 1));
		team[i][--top[i]] = 0;
	}
	return ret;
}


int main() {
	std::ios_base::sync_with_stdio(false);
	
	cin >> N;
	FOR(i, N)FOR(j, N) cin >> map[i + 1][j + 1];

	cout << solve(1) << endl;

	return 0;
}