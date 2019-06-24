#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector<int> adj[2002];

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
	int ret = 0, cnt = 0;
	pre = vector<int>(n + m, -1);
	visit = vector<bool>(n + m);
	for (int i = 0; i < n; i++) {
		fill(begin(visit), end(visit), false);
		if (dfs(i)) ret++;
	}
	for (int i = 0; i < n; i++) {
		while (true) {
			fill(begin(visit), end(visit), false);
			if (dfs(i)) ret++, cnt++;
			else break;
			if (cnt == k) break;
		}
		if (cnt == k) break;
	}
	return ret;
}

int main() {
	
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		int cnt, k;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			scanf("%d", &k);
			adj[i].push_back(k - 1);
		}
	}
	printf("%d", flow());
	return 0;
}