#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;
vector<vector<int>> adj, from;

vector<int> path(int src, int des) {
	if (from[src][des] == des) return vector<int>();
	auto ret = path(src, from[src][des]);
	auto ed = path(from[src][des], des);
	ret.push_back(from[src][des]);
	ret.insert(end(ret), begin(ed), end(ed));
	return ret;
}

int main() {
	int n, m, st, ed, cost;
	scanf("%d %d", &n, &m);

	adj = vector<vector<int>>(n + 1, vector<int>(n + 1, inf));
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &st, &ed, &cost);
		adj[st][ed] = min(adj[st][ed],cost);
	}

	from = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			from[i][j] = j;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) 
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
					from[i][j] = from[i][k];
				}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (adj[i][j] >= inf || i == j) printf("0 ");
			else printf("%d ", adj[i][j]);
		printf("\n");
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		if (adj[i][j] >= inf || i==j) {
			printf("0\n");
			continue;
		}
		auto p = path(i, j);
		printf("%d %d ", p.size() + 2, i);
		for (auto k : p) printf("%d ", k);
		printf("%d\n", j);
	}
	
	return 0;
}