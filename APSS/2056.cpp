#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int v,ans;
int indegree[10000], time[10000],d[10000];
vector<int> adj[10000];

int main() {

	scanf("%d", &v);
	for (int i = 0; i < v; i++) {
		int weight, ind, pre;
		scanf("%d %d",&weight,ind);
		time[i] = weight;
		indegree[i] = ind;
		for (int j = 0; j < ind; j++) {
			scanf("%d", &pre);
			adj[pre].push_back(i);
		}
	}

	queue<int> q;
	for (int i = 0; i < v; i++)
		if (indegree[i] == 0) {
			q.push(i);
			d[i] = time[i];
		}

	for (int i = 0; i < v; i++) {
		int cur = q.front();
		q.pop();
		for (auto next : adj[cur]) {
			d[next] = max(d[next], d[cur] + time[next]);
			indegree[i]--;
			if (indegree[i] == 0) {
				q.push(i);
				ans = max(ans, d[i]);
			}
		}
	}
	
	printf("%d", ans);

	return 0;
}