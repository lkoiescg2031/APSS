#include <cstdio>
#include <vector>
using namespace std;
int n;
vector<vector<char>>map;
void sol(int x, int y, int s) {
	if (s == 3) {
		for (int i = 0; i < 3; i++) 
			for (int j = 0; j <= i; j++) {
				if (i == 1 && j == 0)
					continue;
				map[x + i][y + j] = '*';
				map[x + i][y - j] = '*';
			}
	} else {
		int m = s / 2;
		sol(x, y, m);
		sol(x + m, y - m, m);
		sol(x + m, y + m, m);
	}
}
int main() {
	scanf("%d", &n);
	map = vector<vector<char>>(n, vector<char>(n * 2, ' '));
	sol(0, n, n);
	for (int i = 0; i < map.size(); i++) {
		for (int j = 1; j < map[i].size(); j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
	return 0;
}