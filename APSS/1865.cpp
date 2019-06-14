#include <cstdio>
#include <tuple>
using namespace std;

const int inf = 0x3f3f3f3f;

int n, m, w, e;
tuple<int, int, int> adj[5200];
int dist[501];

int main() {

	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		int from, to, cost;
		scanf("%d %d %d", &n, &m, &w);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &from, &to, &cost);
			adj[i] = { from,to,cost };
			adj[m + i] = { to,from,cost };
		}
		for (int i = 0; i < w; i++) {
			scanf("%d %d %d", &from, &to, &cost);
			adj[2*m + i] = { from,to,-cost };
		}

		bool neg = false;
		dist[1] = 0;
		for (int i = 2; i <= n; i++)
			dist[i] = inf;
		e = 2 * m + w;
		for(int i=1;i<=n;i++)
			for (int j = 0; j < e; j++) {
				tie(from, to, cost) = adj[j];
				if (dist[from] != inf && dist[to] > dist[from] + cost) {
					dist[to] = dist[from] + cost;
					if (i == n) neg = true;
				}
			}

		if (neg) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}