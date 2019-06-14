#include <cstdio>
#include <tuple>
#include <vector>
using namespace std;

const int inf = 0x3f3f3f3f;

int n, m;
tuple<int, int, int> adj[6000];
int dist[501];
bool negative_cycle = false;

int main() {

	int from, to, cost;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		adj[i] = { from,to,cost };
	}

	for (int i = 1; i <= n; i++) dist[i] = inf;
	dist[1] = 0;

	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < m; j++) {
			tie(from, to, cost) = adj[j];
			if (dist[from] != inf && dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
				if (i == n) negative_cycle = true;
			}
		}

	if (negative_cycle)
		printf("-1");
	else
		for (int i = 2; i <= n; i++)
			if (dist[i] != inf) printf("%d\n", dist[i]);
			else printf("-1\n");

	return 0;
}