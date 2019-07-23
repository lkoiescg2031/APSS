#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct bipartite_matching {
	int n;
	int source, sink;
	vector<vector<int>> graph;
	vector<int> check;
	int step;
	vector<int> pred;
	bipartite_matching(int n) : n(n) {
		graph.resize(n);
		check.resize(n);
		pred.resize(n, -1);
	};
	void add_edge(int u, int v) {
		graph[u].push_back(v);
	}
	bool dfs(int x) {
		if (x == -1) return true;
		for (int next : graph[x]) {
			if (check[next] == step) continue;
			check[next] = step;
			if (dfs(pred[next])) {
				pred[next] = x;
				return true;
			}
		}
		return false;
	}
	int flow() {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			step++;
			if (dfs(i)) ans += 1;
		}
		return ans;
	}
};

int map[100][100];
int l[100][100], r[100][100];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		map[u - 1][v - 1] = 1;
	}
	int rn = 1, cn = 1;
	// /
	for (int i = 0; i < n; i++) {
		int x = 0;
		int y = i;
		while (x < n && y >= 0) {
			if (map[x][y] == 1) rn++;
			else r[x][y] = rn;
			x++, y--;
		}
		rn++;
	}
	for (int i = 1; i < n; i++) {
		int x = i;
		int y = n - 1;
		while (x < n && y >= 0) {
			if (map[x][y] == 1) rn++;
			else r[x][y] = rn;
			x++,y--;
		}
		rn++;
	}
	// 반대방향
	for (int i = 0; i < n; i++) {
		int x = 0;
		int y = i;
		while (x < n && y < n) {
			if (map[x][y] == 1) cn++;
			else l[x][y] = cn;
			x++, y++;
		}
		cn++;
	}
	for (int i = 1; i < n; i++) {
		int x = i;
		int y = 0;
		while (x < n && y < n) {
			if (map[x][y] == 1) cn++;
			else l[x][y] = cn;
			x++, y++;
		}
		cn++;
	}
	bipartite_matching mf(max(cn, rn) + 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] == 0)
				mf.add_edge(l[i][j], r[i][j]);
	printf("%d", mf.flow());
	return 0;
}