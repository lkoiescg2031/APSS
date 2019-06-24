#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k;
vector<int> adj[2003];
int s, t;

int capacity[2003][2003];
vector<bool> visit;

int dfs(int i, int c) {
	visit[i] = true;
	if (i == t) return c;
	for (auto j : adj[i])
		if (!visit[j] && capacity[i][j] > 0) {
			int f = dfs(j, min(c, capacity[i][j]));
			if (f != 0) {
				capacity[i][j] -= f;
				capacity[j][i] += f;
				return f;
			}
		}
	return 0;
}

int flow() {
	int ret = 0;
	visit = vector<bool>(t + 1);
	while (true) {
		fill(begin(visit), end(visit), false);
		int flow = dfs(s, 0x3f3f3f3f);
		if (flow == 0) break;
		ret += flow;
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		int k, l;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &l);
			adj[i].push_back(n + l);
			adj[n + l].push_back(i);
			capacity[i][n + l] = 1;
		}
	}
	s = 0, t = n + m + 2;
	adj[s].push_back(n + m + 1);
	capacity[s][n + m + 1] = k;
	for (int i = 1; i <= n; i++) {
		adj[s].push_back(i);
		adj[n + m + 1].push_back(i);
		capacity[n + m + 1][i] = capacity[s][i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		adj[n + i].push_back(t);
		capacity[n + i][t] = 1;
	}
	printf("%d", flow());

	return 0;
}