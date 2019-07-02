#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct bipartite_matching {
	
	bipartite_matching(int n) : n(n) {
		adj.resize(n);
		visit.resize(n);
		from.resize(n, -1);
	}

	void add_edge(int u, int v) {
		adj[u].push_back(v);
	}

	bool dfs(int i) {
		if (i == -1) return true;
		for (auto j : adj[i]) {
			if (visit[j]) continue;
			visit[j] = true;
			if (dfs(from[j])) {
				from[j] = i;
				return true;
			}
		}
		return false;
	}

	int flow() {
		int ret = 0;
		for (int i = 0; i < n; i++) {
			fill(begin(visit), end(visit), false);
			if (dfs(i)) ret++;
		}
		return ret;
	}

	vector<vector<int>> adj;
	vector<bool> visit;
	vector<int> from;
	int n;
};

int n, m, rn, cn;
char map[50][50];
int row[50][50];
int col[50][50];

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
		}
		getchar();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m;) {
			if (map[i][j] == '*') {
				rn++;
				while (j < m && map[i][j] == '*') row[i][j] = rn, j++;
			}
			while (j < m && map[i][j] == '.') j++;
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n;) {
			if (map[i][j] == '*') {
				cn++;
				while (i < n && map[i][j] == '*') col[i][j] = cn, i++;
			}
			while (i < n && map[i][j] == '.') i++;
		}
	}
	bipartite_matching mf(max(rn, cn));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if(map[i][j] == '*')
			mf.add_edge(row[i][j] - 1, col[i][j] - 1);

	printf("%d", mf.flow());
	return 0;
}