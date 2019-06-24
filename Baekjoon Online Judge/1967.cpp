#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
#include <memory.h>
using namespace std;

int n;
vector<pair<int, int>> adj[10001];
int visit[10001];
int dist[10001];
int u, v, w;

int bfs(int start) {
	int ret=0, max=0;
	queue<int> q;

	memset(visit, 0, sizeof(visit));
	memset(dist, 0, sizeof(visit));

	visit[start] = true;
	dist[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int parent = q.front(); q.pop();
		for (auto child : adj[parent]) {
			if (visit[child.first] == false) {
				visit[child.first] = true;
				dist[child.first] = dist[parent] + child.second;
				if (max < dist[child.first]) {
					max = dist[child.first];
					ret = child.first;
				}
				q.push(child.first);
			}
		}
	}
	return ret;
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}

	u = bfs(1);
	v = bfs(u);
	printf("%d", dist[v]);

	return 0;
}