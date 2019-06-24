#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<int> adj['z' + 1];
int source, sink;

int capacity['z' + 1]['z' + 1];

int bfs(int source) {
	int flag = true;
	vector<char> from('z' + 1);
	queue<int> q;
	q.push(source);
	from[source] = -1;
	while (flag &&!q.empty()) {
		int i = q.front();
		q.pop();
		for(auto j : adj[i])
			if (from[j] == 0 && capacity[i][j] > 0) {
				from[j] = i;
				if (j == sink) {
					flag = false;
					break;
				}
				q.push(j);
			}
	}
	if (from[sink] != 0) {
		int c = 0x3f3f3f3f;
		for (int i = sink; from[i] != -1; i = from[i])
			c = min(c, capacity[from[i]][i]);
		for (int i = sink; from[i] != -1; i = from[i]) {
			capacity[from[i]][i] -= c;
			capacity[i][from[i]] += c;
		}
		return c;
	}
	return 0;
}

int flow() {
	int ans = 0;
	while (true) {
		int flow = bfs(source);
		if (flow == 0) break;
		ans += flow;
	}
	return ans;
}

int main() {

	char u, v, tmp;
	int c;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%c%c %c %d", &tmp, &u, &v, &c);
		adj[u].push_back(v); capacity[u][v] += c;
		adj[v].push_back(u); capacity[v][u] += c;
	}
	source = 'A', sink = 'Z';
	printf("%d", flow());

	return 0;
}