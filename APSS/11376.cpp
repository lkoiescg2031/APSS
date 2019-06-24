#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[2002];
int s, t;

int capacity[2002][2002];
vector<bool> visit;

int dfs(int i, int c) {
	visit[i] = true;
	if (i == t) return c;
	for(auto j : adj[i])
		if (!visit[j] && capacity[i][j] > 0) {
			int flow = dfs(j, min(c, capacity[i][j]));
			if (flow != 0) {
				capacity[i][j] -= flow;
				capacity[j][i] += flow;
				return flow;
			}
		}
	return 0;
}

int flow() {
	int ret = 0;
	visit = vector<bool>(t + 1, false);
	while (true) {
		fill(begin(visit), end(visit), false);
		int flow = dfs(s, 0x3f3f3f3f);
		if (flow == 0) break;
		ret += flow;
	}
	return ret;
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int l, k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &l);
			adj[i].push_back(n + l);
			adj[n + l].push_back(i);
			capacity[i][n + l] = 1;
		}
	}
	s = 0, t = n + m + 1;
	for (int i = 1; i <= n; i++) {
		adj[s].push_back(i);
		capacity[s][i] = 2;
	}
	for (int i = 1; i <= m; i++) {
		adj[i + n].push_back(t);
		capacity[i + n][t] = 1;
	}
	printf("%d", flow());
	return 0;
}