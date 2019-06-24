#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;

int main() {

	int n, m, from, to, cost;
	scanf("%d %d", &n, &m);
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, inf));
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		adj[from][to] = min(adj[from][to], cost);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (adj[i][j] >= inf || i==j) printf("0 ");
			else printf("%d ", adj[i][j]);
		printf("\n");
	}
	return 0;
}