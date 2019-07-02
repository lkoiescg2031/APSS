#include <cstdio>
#include <vector>
using namespace std;

struct biparite_matching {
	biparite_matching(int n) : n(n) {
		adj.resize(n);
		visit.resize(n);
		pre.resize(n, -1);
	}
	void add_edge(int u, int v) {
		adj[u].push_back(v);
	}
	bool dfs(int i) {
		if (i == -1) return true;
		for (auto j : adj[i]) {
			if (visit[j]) continue;
			visit[j] = true;
			if (dfs(pre[j])) {
				pre[j] = i;
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
	int n;
	vector<vector<int>> adj;
	vector<bool> visit;
	vector<int> pre;
};

int t, n, m;
char map[80][80];

int dx[] = { 0,-1,-1 };
int dy[] = { -1,-1,1 };

int main() {
	scanf("%d\n", &t);
	while (t--) {
		int ans = 0;
		scanf("%d %d\n", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%c", &map[i][j]);
				if (map[i][j] == '.') ans++;
			}
			getchar();
		}
		biparite_matching mf(n * m);
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 'x') continue;
				int u = i * m + j;
				for (int k = 0; k < 3; k++) {
					int mx = i + dx[k];
					int my = j + dy[k];
					int v = mx * m + my;
					if (mx >= 0 && mx < n && my >= 0 && my < m){
						if (map[mx][my] == 'x') continue;
						if (j % 2) mf.add_edge(u, v);
						else mf.add_edge(v, u);
					}
				}
			}
		printf("%d\n", ans - mf.flow());
	}
	return 0;
}