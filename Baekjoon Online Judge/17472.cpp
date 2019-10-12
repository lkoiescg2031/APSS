#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

struct Edge {
	int u, v, cost;
};

int n, m, map[10][10], island;
int dist[7][7], last, parent[7];
vector<Edge> e;

void draw(int x, int y) {
	static int dx[] = { 0,1,0,-1 };
	static int dy[] = { 1,0,-1,0 };

	map[x][y] = island;

	for (int i = 0; i < 4; i++) {
		int mx = x + dx[i];
		int my = y + dy[i];
		if (mx >= 0 && my >= 0 && mx < n && my < m &&
			map[mx][my] == 1)
			draw(mx, my);
	}
}

int find(int i) {
	if (i == parent[i]) return i;
	return find(parent[i]);
}

bool is_connect() {
	int key = find(1);
	for (int i = 2; i <= island; i++)
		if (key != find(i)) return false;
	return true;
}

int go(int i, int sum) {
	if (i == last) {
		return is_connect() ? sum : INF;
	}

	int u_parent = find(e[i].u);
	int v_parent = find(e[i].v);
	int temp = parent[u_parent];

	parent[u_parent] = v_parent;
	int a = go(i + 1, sum + e[i].cost);

	parent[u_parent] = temp;
	int b = go(i + 1, sum);

	return min(a, b);
}

int main() {

	memset(dist, 0x3f, sizeof(dist));

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 1) island--, draw(i, j);
	island = -island;

	for (int i = 0; i < n; i++) {
		int j = 0; while (j < m && map[i][j] == 0) j++;
		int from = j == m ? -1 : map[i][j++];
		int d = 0;
		while (j < m) {
			while (j < m && map[i][j] == from) j++;
			while (j < m && map[i][j] == 0) d++, j++;
			if (j < m) {
				int to = map[i][j];
				if (from != to && d > 1 && dist[-from][-to] > d)
					dist[-from][-to] = dist[-to][-from] = d;
				d = 0;
				from = to;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int j = 0; while (j < n && map[j][i] == 0) j++;
		int from = j == n ? -1 : map[j++][i];
		int d = 0;
		while (j < n) {
			while (j < n && map[j][i] == from) j++;
			while (j < n && map[j][i] == 0) d++, j++;
			if (j < n) {
				int to = map[j][i];
				if (from != to && d > 1 && dist[-from][-to] > d)
					dist[-from][-to] = dist[-to][-from] = d;
				d = 0;
				from = to;
			}
		}
	}

	for (int i = 1; i <= island; i++) {
		parent[i] = i;
		for (int j = i + 1; j <= island; j++)
			if (dist[i][j] != INF) e.push_back({ i,j,dist[i][j] });
	}
	last = e.size();

	int ans = go(0, 0);
	if (ans == INF) ans = -1;
	printf("%d\n", ans);

	return 0;
}