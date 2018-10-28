#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define MAX 50

#define EMPTY 0
#define WALL 1
#define CLEAN 2

int N, M;
int area[MAX][MAX];
int r_x, r_y, r_d;
               //서,남,동,북
int move_x[4] = {-1,0,1,0};
int move_y[4] = {0,1,0,-1};

int ans = 0;

int clean(int x, int y, int dir,int sum) {// 0:북 
	
	if (area[y][x] == EMPTY) {
		area[y][x] = CLEAN;
		sum++;
	}

	for (int i = 0; i < 4; i++) {
		int rot = (4 - dir + i) % 4;
		int dx = x + move_x[rot];
		int dy = y + move_y[rot];
		if (0 <= dx && dx < M && 0 <= dy && dy < N &&
			area[dy][dx] == EMPTY)
			return clean(dx, dy, 3 - rot, sum);
	}
	//처음 생각한 값
	//int rot = (dir + 2) % 4;
	//int dx = x + move_x[rot];
	//int dy = y + move_y[rot];

	//모두 청소 되어있고 뒤가 벽이 아닌 경우
	int rot = 3 - dir;
	int dx = x - move_x[rot];
	int dy = y - move_y[rot];
	if (area[dy][dx] != WALL)
		return clean(dx, dy, dir, sum);
	//모두 청소 되어 있고 뒤가 벽인 경우
	return sum;
}


int main() {

	ios_base::sync_with_stdio(false);

	cin >> N >> M >>
		//r_x >> r_y >> r_d;
		r_y >> r_x >> r_d;
	FOR(i, N)FOR(j, M) cin >> area[i][j];

	cout << clean(r_x,r_y,r_d,0) << endl;

	return 0;
}