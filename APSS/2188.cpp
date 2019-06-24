#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[201];

vector<bool> visit;
vector<int> pre;

int dfs(int i) {
	if (i == -1) return true;
	for(auto j:adj[i])
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
	visit = vector<bool>(max(n, m));
	pre = vector<int>(max(n, m), -1);
	for (int i = 0; i < n; i++) {
		fill(begin(visit), end(visit), false);
		if (dfs(i)) ret++;
	}
	return ret;
}

int main() {

	int cnt, k;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			scanf("%d", &k);
			adj[i].push_back(k - 1);
		}
	}
	printf("%d", flow());
	return 0;
}