#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int v;
int time[10001];
vector<int> adj[10001];
int indegree[10001], d[10001];

int main() {

	int pre;
	scanf("%d", &v);
	for (int i = 1; i <= v; i++) {
		scanf("%d %d",&time[i], &indegree[i]);
		for (int j = 0; j < indegree[i]; j++) {
			scanf("%d", &pre);
			adj[pre].push_back(i);
		}
	}

	queue<int> q;
	for (int i = 1; i <= v; i++)
		if (indegree[i] == 0) {
			q.push(i);
			d[i] = time[i];
		}

	for (int i = 0; i < v; i++) {
		int cur = q.front();
		q.pop();
		for (auto next : adj[cur]) {
			indegree[next]--;
			d[next] = max(d[next], d[cur] + time[next]);
			if (indegree[next] == 0) q.push(next);
		}
	}

	int ans = 0;
	for (int i = 1; i <= v; i++)
		ans = max(ans, d[i]);

	printf("%d", ans);

	return 0;
}