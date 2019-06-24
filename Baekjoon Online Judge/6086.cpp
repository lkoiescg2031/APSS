#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;

int n;
vector<int> adj['z' + 1];
int source, sink;

vector<bool> visit;
int capacity['z' + 1]['z' + 1];

int dfs(int i, int c) {
	visit[i] = true;
	if (i == sink) return c;
	for(auto j : adj[i])
		if (!visit[j] && capacity[i][j] > 0) {
			int flow = dfs(j, min(c, capacity[i][j]));
			if (flow != 0) {
				capacity[i][j] -= flow;
				capacity[j][i] += flow;
				return flow;
			}
		}
	return 0;
}

int flow() {
	int ans = 0;
	while (true) {
		visit = vector<bool>('z' + 1, false);
		int flow = dfs(source, inf);
		if (flow == 0) break;
		ans += flow;
	}
	return ans;
}

int main() {

	char u, v,tmp;
	int c;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%c %c %c %d",&tmp, &u, &v, &c);
		adj[u].push_back(v);
		capacity[u][v] += c;
		adj[v].push_back(u);
		capacity[v][u] += c;
	}
	source = 'A', sink = 'Z';
	printf("%d", flow());

	return 0;
}