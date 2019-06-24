#include <cstdio>
#include <algorithm>

#define FOR(x,n) for(int (x)=0;(x)<(n);++(x))
#define MAX 500
#define NO_ANS -1;

int col, row;
int map[MAX][MAX];

int visit[MAX][MAX];
int move_x[4] = { -1,0,1,0 };
int move_y[4] = { 0,-1,0,1 };

int ans = 0;
//4개인 테트로미노를 찾음
int dfs(int cur_x, int cur_y, int sum, int tetro_cnt) {
	int ret = sum;

	if (tetro_cnt == 4)
		return ret;

	FOR(i, 4) {
		int next_x = cur_x + move_x[i];
		int next_y = cur_y + move_y[i];

		if (next_x < 0 || next_y < 0 || next_x >= row || next_y >= col)
			continue;
		if (visit[next_y][next_x] == 1)
			continue;

		visit[next_y][next_x] = 1;//방문
		ret = std::max(ret, dfs(next_x, next_y, sum + map[next_y][next_x], tetro_cnt + 1));//max 계산
		visit[next_y][next_x] = 0;//방문 취소
	}
	return ret;
}
//예외 T 테트로 미노는 dfs로 검색되지 않으므로 따로 확인
int t_spin(int cur_x, int cur_y) {
	int edge = 4;
	int sum = 0;
	int min = 987654321;
	FOR(i, 4) {
		int next_x = cur_x + move_x[i];
		int next_y = cur_y + move_y[i];
		//edge가 그보다 작은경우 테트리미노가 아니므로 답이 아님
		if (edge < 3)
			return NO_ANS;
		if (next_x < 0 || next_y < 0 || next_x >= row || next_y >= col) {
			edge--;
			continue;
		}
		sum += map[next_y][next_x];
		if (min > map[next_y][next_x])
			min = map[next_y][next_x];
	}
	//edge가 3개인 경우 T미노 이므로 제거하지 않음0
	if (edge == 3)
		return sum + map[cur_y][cur_x];
	//edge가 4개 인 경우 max를 구하므로 가장 작은 edge를 제거
	else
		return sum + map[cur_y][cur_x] - min;
}

int main() {

	scanf("%d %d", &col, &row);
	FOR(i, col)FOR(j, row)
		scanf("%d", &map[i][j]);

	FOR(y, col)FOR(x, row) {
		visit[y][x] = 1;
		ans = std::max(ans, dfs(x, y, map[y][x], 1));
		ans = std::max(ans, t_spin(x, y));
		visit[y][x] = 0;
	}
	printf("%d\n", ans);

	return 0;
}