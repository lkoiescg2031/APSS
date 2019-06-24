#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans, bitmap[25][25];
vector<int> building;

int movex[] = { 0,1,0,-1 };
int movey[] = { 1,0,-1,0 };

void dfs(int curi, int curj) {
	bitmap[curi][curj] = 0;
	building[building.size() - 1]++;
	for (int i = 0; i < 4; i++) {
		int dx = curi + movex[i];
		int dy = curj + movey[i];
		if (dx >= 0 && dx < n && dy >= 0 && dy < n
			&& bitmap[dx][dy] == 1)
			dfs(dx, dy);
	}
}

int main() {

	scanf("%d",&n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%1d",&bitmap[i][j]);
		}


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (bitmap[i][j] == 1) {
				ans++;
				building.push_back(0);
				dfs(i, j);
			}

	sort(begin(building), end(building));

	printf("%d\n",ans);
	for (auto i : building) printf("%d\n",i);

	return 0;
}