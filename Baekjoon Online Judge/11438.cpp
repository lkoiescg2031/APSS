#include <cstdio>
#include <queue>
using namespace std;

int n, m;
vector<int> adj[100001];
int from[100001], dep[100001];
int parent[100001][20];

int main() {

	int u, v;

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	q.push(1);
	from[1] = -1;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (auto i : adj[u]) 
			if (from[i] == 0) {
				from[i] = u;
				dep[i] = dep[u] + 1;
				q.push(i);
			}
	}
	from[1] = 0;

	for (int i = 1; i <= n; i++)
		parent[i][0] = from[i];

	for (int j = 1; (1 << j) < n; j++)
		for (int i = 1; i <= n; i++)
			if (parent[i][j - 1] != 0)
				parent[i][j] = parent[parent[i][j - 1]][j - 1];

	scanf("%d", &m);
	while(m--){
		scanf("%d %d", &u, &v);
		if (dep[v] > dep[u])
			swap(u, v);

		int exp = 1,i;
		for (; (1 << exp) <= dep[u]; exp++);
		exp--;
		for (i = exp; i >= 0; i--)
			if (dep[u] - (1 << i) >= dep[v])
				u = parent[u][i];
		if (u == v)
			printf("%d\n", u);
		else {
			for (i = exp; i >= 0; i--)
				if (parent[u][i] != 0 && parent[u][i] != parent[v][i])
					u = parent[u][i], v = parent[v][i];
			printf("%d\n", parent[u][0]);
		}
	}

	return 0;
}