#include <cstdio>
#include <tuple>
#include <queue>
using namespace std;

const int inf = 100000000;

int v, e;
vector<pair<int, int>> adj[20001];
int st, ed;

int main() {

	int from, to, cost;
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		adj[from].push_back({ to,cost });
	}
	scanf("%d %d", &st, &ed);

	vector<bool> visit(v + 1, false);
	vector<int> dist(v + 1, inf);
	dist[st] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ -dist[st],st });
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

	printf("%d", dist[ed]);

	return 0;
}