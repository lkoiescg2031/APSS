#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[100001];
int tin[100001], tout[100001], timer;
int parent[100001][20];
int high = 1;

void dfs(int v, int from) {
	tin[v] = ++timer;
	
	parent[v][0] = from;
	for (int i = 1; i <= high; i++)
		parent[v][i] = parent[parent[v][i - 1]][i - 1];

	for (auto i : adj[v])
		if (i != from)
			dfs(i, v);

	tout[v] = ++timer;
}
bool upper(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}
int lca(int u, int v) {
	if (upper(u, v)) return u;
	if (upper(v, u)) return v;
	for (int i = high; i >= 0; i--)
		if (!upper(parent[u][i], v))
			u = parent[u][i];
	return parent[u][0];
}

int main() {

	int u, v;

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (; (1 << high) < n; high++);
	dfs(1, 1);

	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u, v));
	}
	return 0;
}