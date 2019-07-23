#include <cstdio>
#include <vector>
using namespace std;

struct MaximumFlow {
	int n;
	vector<vector<int>> graph;
	vector<int> check;
	vector<int> matchR;
	vector<int> matchL;
	int step;
	MaximumFlow(int n) : n(n) {
		graph.resize(n);
		check.resize(n);
		matchR.resize(n, -1);
		matchL.resize(n, -1);
	};
	void add_edge(int u, int v) {
		graph[u].push_back(v);
	}
	bool dfs(int x) {
		if (x == -1) return true;
		for (int next : graph[x]) {
			if (check[next] == step) continue;
			check[next] = step;
			if (dfs(matchR[next])) {
				matchR[next] = x;
				matchL[x] = next;
				return true;
			}
		}
		return false;
	}
	int flow() {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			step = i + 1;
			if (dfs(i)) {
				ans += 1;
			}
		}
		return ans;
	}
};

int main() {
	int n;

	scanf("%d", &n);
	MaximumFlow mf(1000000);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		mf.add_edge(i, a - 1);
		mf.add_edge(i, b - 1);
	}

	if (mf.flow() != n) {
		printf("-1");
		return 0;
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", mf.matchL[i] + 1);

	return 0;
}