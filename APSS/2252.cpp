#include <cstdio>
#include <queue>
using namespace std;

int n, m, b, e;
int indegree[32001];
vector<int> adj[32001];

int main() {

	scanf("%d %d", &n, &m);	
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &b, &e);
		adj[b].push_back(e);
		indegree[e]++;
	}
	
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) q.push(i);

	for (int i = 0; i < n; i++) {
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		for (auto next : adj[cur]) {
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}

	return 0;
}