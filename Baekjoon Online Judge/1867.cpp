#include <cstdio>
#include <vector>
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

int main() { 

	int n, k, u, v;
	scanf("%d %d", &n, &k);
	bipartite_matching mf(n);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &u, &v);
		mf.add_edge(u - 1, v - 1);
	}
	printf("%d", mf.flow());
	return 0;
}