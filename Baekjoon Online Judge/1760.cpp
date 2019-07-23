#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct bipartite_matching {
	bipartite_matching(int n) : n(n) {
		graph.resize(n);
		check.resize(n);
		pre.resize(n, -1);
	}
	void add_edge(int u, int v) {
		graph[u].push_back(v);
	}
	bool dfs(int x) {
		if (x == -1) return true;
		for (int next : graph[x]) {
			if (check[next] == step) continue;
			check[next] = step;
			if (dfs(pre[next])) {
				pre[next] = x;
				return true;
			}
		}
		return false;
	}
	int flow() {
		int ret = 0;
		for (int i = 0; i < n; i++) {
			step++;
			if (dfs(i)) ret++;
		}
		return ret;
	}
	int n;
	vector<vector<int>> graph;
	vector<int> pre;
	vector<int> check;
	int step;
};

int n, m;
int map[100][100];
int row[100][100], col[100][100];

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++) 
			scanf("%d", &map[i][j]);
		
	int L = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2) L++;
			else row[i][j] = L;
		}
		L++;
	}
	int R = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[j][i] == 2) R++;
			else col[j][i] = R;
		}
		R++;
	}

	bipartite_matching mf(max(L, R) + 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			if (map[i][j] == 0) 			
				mf.add_edge(row[i][j], col[i][j]);		
	
	printf("%d", mf.flow());
	return 0;
}