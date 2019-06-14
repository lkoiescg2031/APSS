#include <cstdio>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

const int inf = 100000000;

int n, e;
vector<pair<int, int>> adj[801];

vector<int> dijkstra(int start) {
	int from, to, cost;
	vector<bool> visit(n + 1, false);
	vector<int> dist(n + 1, inf);
	dist[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ -dist[start],start });
	while (!pq.empty()) {
		from = pq.top().second;
		pq.pop();
		if (visit[from]) continue;
		visit[from] = true;
		for (auto j : adj[from]) {
			tie(to, cost) = j;
			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
				pq.push({ -dist[to],to });
			}
		}
	}
	return dist;
}

int main() {
	int from, to, cost;

	scanf("%d %d", &n, &e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		adj[from].push_back({ to,cost });
		adj[to].push_back({ from,cost });
	}
	int v1, v2;
	scanf("%d %d", &v1, &v2);

	vector<int> d0 = dijkstra(1);
	vector<int> d1 = dijkstra(v1);
	vector<int> d2 = dijkstra(v2);

	int ans1 = d0[v1] + d1[v2] + d2[n];
	int ans2 = d0[v2] + d2[v1] + d1[n];
	int ans = min(ans1, ans2);
	
	if (ans >= inf) printf("-1");
	else printf("%d", ans);

	return 0;
}