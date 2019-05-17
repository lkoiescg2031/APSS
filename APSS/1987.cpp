#include <cstdio>
#include <algorithm>
using namespace std;

int r, c, visit['Z' + 1];
char map[20][20];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int cnt(int n,int x,int y) {
	int ret = n;
	for (int i = 0; i < 4; i++) {
		int mx = x + dx[i];
		int my = y + dy[i];
		if (mx >= 0 && my >= 0 && mx < r && my < c && !visit[map[mx][my]]) {
			visit[map[mx][my]] = true;
			ret = max(ret, cnt(n + 1, mx, my));
			visit[map[mx][my]] = false;
		}
	}
	return ret;
}

int main() {
	
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf(" %c", &map[i][j]);
	
	visit[map[0][0]] = true;
	printf("%d", cnt(1,0,0));
	return 0;
}