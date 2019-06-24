#include<cstdio>
#include<algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;

int v, e;
int adj[401][401];

int main() {
	int from, to, cost;

	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			adj[i][j] = inf;
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		adj[from][to] = cost;
	}

	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	int ans = inf;
	for (int i = 1; i <= v; i++)
		ans = min(ans, adj[i][i]);	
	if (ans == inf) printf("-1");
	else printf("%d", ans);

	return 0;
}