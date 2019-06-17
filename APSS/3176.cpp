#include <cstdio>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

const int MAX = 100001;
const int inf = 10000000;

int n, m;
vector< pair<int, int> > adj[MAX];
int dep[MAX],from[MAX],dist[MAX];
int parent[MAX][20], mindst[MAX][20], maxdst[MAX][20];

int main() {
	
	int u, v, cost;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &u, &v, &cost);
		adj[u].push_back({ v,cost });
		adj[v].push_back({ u,cost });
	}

	queue<int> q;
	q.push(1);
	from[1] = -1;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (auto i : adj[u]) {
			tie(v, cost) = i;
			if (from[v] == 0) {
				tie(from[v], dist[v], dep[v]) = make_tuple(u, cost, dep[u] + 1);
				q.push(v);
			}
		}
	}

	from[1] = 0;
	for (int i = 1; i <= n; i++) {
		parent[i][0] = from[i];
		mindst[i][0] = maxdst[i][0] = dist[i];
	}
	
	for (int j = 1; (1 << j) < n; j++)
		for (int i = 1; i <= n; i++)
			if (parent[i][j - 1] != 0) {
				int& mind = mindst[i][j];
				int& maxd = maxdst[i][j];
				parent[i][j] = parent[parent[i][j - 1]][j - 1];
				mind = mindst[i][j - 1];
				maxd = maxdst[i][j - 1];
				if (parent[parent[i][j - 1]][j - 1] != 0) {
					mind = min(mind, mindst[parent[i][j - 1]][j - 1]);
					maxd = max(maxd, maxdst[parent[i][j - 1]][j - 1]);
				}
			}

	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &u, &v);
		
		if (dep[v] > dep[u])swap(u, v);

		int min_ans = inf, max_ans = 0, log = 1;
		for (; (1 << log) <= dep[u]; log++);
		log--;

		for (int i = log; i >= 0; i--)
			if (dep[u] - (1 << i) >= dep[v]) {
				min_ans = min(min_ans, mindst[u][i]);
				max_ans = max(max_ans, maxdst[u][i]);
				u = parent[u][i];
			}

		if (u != v) {
			for (int i = log; i >= 0; i--) {
				if (parent[u][i] != 0 && parent[u][i] != parent[v][i]) {
					min_ans = min({ min_ans,mindst[u][i],mindst[v][i] });
					max_ans = max({ max_ans,maxdst[u][i],maxdst[v][i] });
					u = parent[u][i];
					v = parent[v][i];
				}
			}
			min_ans = min({ min_ans,mindst[u][0],mindst[v][0] });
			max_ans = max({ max_ans,maxdst[u][0],maxdst[v][0] });
		}

		printf("%d %d\n", min_ans, max_ans);
	}

	return 0;
}
