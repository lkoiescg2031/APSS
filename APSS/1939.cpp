#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;
using pairii = pair<int, int>;;
using arri = vector<pairii>;
using ADJ = vector<arri>;

int n, m;
ADJ adj;
int a, b, c;
int sour, des;
int l, r;
int ans;
bool bfs(int b, int e, int w) {
	bool ret = false;
	queue<int> q;
	vector<int> visit(n + 1, false);
	visit[b] = true;
	q.push(b);
	while (!q.empty() && !ret) {
		int cur = q.front();
		q.pop();
		for (auto i : adj[cur]) {
			int next = i.first;
			int weight = i.second;
			if (!visit[next] && weight >= w) {
				if (next == e) {
					ret = true;
					break;
				}
				else q.push(next), visit[next] = true;
			}
		}
	}
	return ret;
}
int main() {

	scanf("%d %d", &n, &m);
	adj = ADJ(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
		r = max(r, c);
	}
	scanf("%d %d", &sour, &des);

	while (l <= r) {
		int mid = (l + r) / 2;
		if (bfs(sour, des, mid)) {
			ans = max(ans, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}
	printf("%d", ans);

	return 0;
}