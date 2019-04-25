#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
#include <memory.h>
using namespace std;

int n;
vector<pair<int, int>> adj[100001];
int u, v, w;
int dist[100001];
int visit[100001];
int ans;

int bfs(int start) {
	int ret = 0,max = 0;
	queue<int> q;
	memset(dist, 0, sizeof(dist));
	memset(visit, 0, sizeof(dist));

	q.push(start);
	visit[start] = true;
	dist[start] = 0;
	while (!q.empty()) {
		int parent = q.front(); q.pop();
		for(auto child : adj[parent])
			if (visit[child.first] == false) {
				visit[child.first] = true;
				dist[child.first] = dist[parent] + child.second;
				q.push(child.first);
				if (max < dist[child.first]) {
					ret = child.first;
					max = dist[child.first];
				}
			}
	}
	return ret;
}
int main(){
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &u);
		while (scanf("%d", &v) && v != -1) {
			scanf("%d", &w);
			adj[u].push_back({ v,w });
		}
	}

	u = bfs(1);
	v = bfs(u);

	printf("%d", dist[v]);

	return 0;
}