#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;

int main() {
	int n, m, from, to;
	scanf("%d %d", &n, &m);

	vector<vector<int>> adj(n + 1, vector<int>(n + 1, inf));
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &from, &to);
		adj[from][to] = adj[to][from] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	int ans = inf, who;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			sum += adj[i][j];
		}
		if (ans > sum) {
			ans = sum;
			who = i;
		}
	}
	printf("%d", who);

	return 0;
}