#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[100];

vector<int> pre;
vector<bool> visit;

int dfs(int i) {
	if (i == -1) return true;
	for(auto j : adj[i])
		if (!visit[j]) {
			visit[j] = true;
			if (dfs(pre[j])) {
				pre[j] = i;
				return true;
			}
		}
	return false;
}

int flow() {
	int ret = 0;
	pre = vector<int>(n, -1);
	visit = vector<bool>(n);
	for (int i = 0; i < n; i++) {
		fill(begin(visit), end(visit), false);
		if (dfs(i)) ret++;
	}
	return ret;
}

int main() {
	int u, v;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		adj[u - 1].push_back(v - 1);
	}
	printf("%d", flow());
	return 0;
}