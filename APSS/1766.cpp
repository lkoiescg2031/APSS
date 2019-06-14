#include <cstdio>
#include <queue>
using namespace std;

int v,e;
int indegree[32001];
vector<int> adj[32001];

int main() {

	int begin, end;
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d", &begin, &end);
		adj[begin].push_back(end);
		indegree[end]++;
	}

	priority_queue<int,vector<int>,greater<int>> q;
	for (int i = 1; i <= v; i++)
		if (indegree[i] == 0) q.push(i);

	for (int i = 0; i < v; i++) {
		int cur = q.top();
		q.pop();
		printf("%d ", cur);
		for (auto next : adj[cur]) {
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}

	return 0;
}