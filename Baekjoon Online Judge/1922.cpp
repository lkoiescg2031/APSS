#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
vector<pair<int, int>> adj[1001];
int is_visit[1001];
int ans;

int main() {

	int u, v, cost;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &cost);
		adj[u].push_back({ v,cost });
		adj[v].push_back({ u,cost });
	}

	priority_queue<pair<int, int>> q;

	is_visit[1] = true;
	for (auto i : adj[1]) {
		tie(v, cost) = i;
		q.push({ -cost,v });
	}

	while (!q.empty()) {
		tie(cost, u) = q.top();
		q.pop();
		if (is_visit[u]) continue;
		is_visit[u] = true;
		ans += -cost;
		for (auto i : adj[u]) {
			tie(v, cost) = i;
			if (!is_visit[v]) q.push({ -cost,v });
		}
	}

	printf("%d", ans);

	return 0;
}