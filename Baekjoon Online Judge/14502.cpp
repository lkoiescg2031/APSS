#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define MAX 8
#define EMPTY 0
#define WALL 1
#define VIRUS 2

int N,M;
int max_point;
vector<vector<int>> map;

queue<pair<int, int>> virus;
int safe_size = -3;

int move_x[4] = { 0,1,0,-1 };
int move_y[4] = { 1,0,-1,0 };

int cnt_safe_zone(vector<vector<int>> adj) {
	int ret = safe_size;
	int cur_x, cur_y, dx, dy;
	queue<pair<int, int>> q = virus;

	while (!q.empty()) {
		cur_x = q.front().first;
		cur_y = q.front().second;
		q.pop();

		FOR(i, 4) {
			dx = cur_x + move_x[i];
			dy = cur_y + move_y[i];
			if (0 <= dx && dx < M &&/*x 범위 확인*/	 0 <= dy && dy < N &&/*y 범위 확인*/
				adj[dy][dx] == EMPTY) {//비어있는가
				adj[dy][dx] = VIRUS;//감염
				q.push(make_pair(dx, dy));//bfs
				ret--;//세이프존 수 감소
			}
		}
	}
	return ret;
}


int brute_force(int point, int wal_cnt) {
	int ret = 0;

	if (wal_cnt == 3) 
		return cnt_safe_zone(map);

	//1차 작성한 코드 i,j범위 오류 (처음만 x,y로 초기화 하고 이후부터는 0으로 초기화 하여야함)
	//for (int i = y; i < N; i++) 
	//	for (int j = x; j < M; j++) 
	//		if (map[i][j] == 0) {
	//			map[i][j] = 1;
	//			ret = max(ret, brute_force(j, i, wal_cnt + 1));
	//			map[i][j] = 0;
	//		}

	for (int cur = point; cur < max_point; cur++) {//모든 범위
		int i = cur / M;
		int j = cur % M;
		if (map[i][j] == 0) {
			map[i][j] = 1;
			ret = max(ret, brute_force(cur, wal_cnt + 1));
			map[i][j] = 0;
		}
	}
	return ret;
}

int main() {

	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	max_point = N * M;
	map = vector<vector<int>>(N, vector<int>(M));

	FOR(i, N) FOR(j, M) {
		cin >> map[i][j];

		safe_size += (map[i][j] == EMPTY);
		if (map[i][j] == VIRUS)
			virus.push(make_pair(j, i));
	}

	cout << brute_force(0, 0);
	
	return 0;
}