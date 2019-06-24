#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, u, v;
vector<int> adj[100001];
int ans[100001], visit[100001];

int main() {

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	visit[1] = true;
	ans[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int parent, child;
		parent = q.front();
		q.pop();
		for (auto child : adj[parent]) {
			if (visit[child] == false) {
				visit[child] = true;
				ans[child] = parent;
				q.push(child);
			}
		}
	}

	for (int i = 2; i <= n; i++)
		printf("%d\n", ans[i]);

	return 0;
}