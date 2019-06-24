#include <cstdio>
#include <vector>
#include <tuple>
#include <bitset>
using namespace std;

int map[9][9];
int hasi[9][10], hasj[9][10], hasq[9][10];
vector<pair<int, int>> loc;
bool draw(int recur) {
	int x, y;

	if (recur == loc.size()) {
		printf("\n");
		for (int k = 0; k < 9; k++){
			for (int l = 0; l < 9; l++)
				printf("%d ", map[k][l]);
			printf("\n");
		}
		return 1;
	}

	tie(x, y) = loc[recur];
	for (int i = 1; i < 10; i++) {
		int& w = hasj[y][i];
		int& h = hasi[x][i];
		int& q = hasq[x / 3 * 3 + y / 3][i];
		if (!w && !h && !q) {
			w = h = q = 1;
			map[x][y] = i;
			if (draw(recur + 1))
				return 1;
			w = h = q = map[x][y] = 0;
		}
	}

	return 0;
}
int main() {
	for(int i=0;i<9;i++)
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) loc.push_back({ i,j });
		}	
	for (int i = 0; i < 9; i++) {
		int x = i / 3;
		int y = i % 3;
		for (int j = 0; j < 9; j++) {
			hasi[i][map[i][j]] = 1;
			hasj[i][map[j][i]] = 1;
		}
		for(int j=0;j<3;j++)for (int k = 0; k < 3; k++) 
			hasq[i][map[x * 3 + j][y * 3 + k]] = 1;
	}
	draw(0);
	return 0;
}
