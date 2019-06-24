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
//4���� ��Ʈ�ι̳븦 ã��
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

		visit[next_y][next_x] = 1;//�湮
		ret = std::max(ret, dfs(next_x, next_y, sum + map[next_y][next_x], tetro_cnt + 1));//max ���
		visit[next_y][next_x] = 0;//�湮 ���
	}
	return ret;
}
//���� T ��Ʈ�� �̳�� dfs�� �˻����� �����Ƿ� ���� Ȯ��
int t_spin(int cur_x, int cur_y) {
	int edge = 4;
	int sum = 0;
	int min = 987654321;
	FOR(i, 4) {
		int next_x = cur_x + move_x[i];
		int next_y = cur_y + move_y[i];
		//edge�� �׺��� ������� ��Ʈ���̳밡 �ƴϹǷ� ���� �ƴ�
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
	//edge�� 3���� ��� T�̳� �̹Ƿ� �������� ����0
	if (edge == 3)
		return sum + map[cur_y][cur_x];
	//edge�� 4�� �� ��� max�� ���ϹǷ� ���� ���� edge�� ����
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