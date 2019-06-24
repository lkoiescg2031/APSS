#include <cstdio>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int,int>> adj[40001];
int dep[40001];
pair<int,int> from[40001];

int main() {

	int u, v,cost;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &u, &v, &cost);
		adj[u].push_back({ v, cost });
		adj[v].push_back({ u, cost });
	}

	queue<int> q;
	q.push(1);
	dep[1] = 0;
	from[1] = { -1,0 };
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (auto i : adj[u]) {
			tie(v, cost) = i;
			if (from[v].first == 0) {
				from[v] = { u,cost };
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}

	scanf("%d", &m);
	while (m--) {
		int ans = 0;
		scanf("%d %d", &u, &v);
		if (dep[u] < dep[v]) swap(u, v);
		while (dep[u] > dep[v]) ans += from[u].second, u = from[u].first;
		while (u != v) {
			ans += from[u].second;
			u = from[u].first;
			ans += from[v].second;
			v = from[v].first;
		}
		printf("%d\n", ans);
	}

	return 0;
}