#include <cstdio>
#include <tuple>
#include <queue>
#include <stack>
using namespace std;

const int inf = 0x3f3f3f3f;

int n, m;
vector<pair<int, int>> adj[1001];
int src, des;

int main() {

	int st, ed, cost;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &st, &ed, &cost);
		adj[st].push_back({ ed,cost });
	}
	scanf("%d %d", &src, &des);

	vector<int> from(n + 1, 0);
	vector<bool> visit(n + 1, false);
	vector<int> dist(n + 1, inf);
	dist[src] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ -dist[src],src });
	while (!pq.empty()) {
		st = pq.top().second;
		pq.pop();
		if (visit[st]) continue;
		visit[st] = true;
		for (auto j : adj[st]) {
			tie(ed, cost) = j;
			if (dist[ed] > dist[st] + cost) {
				dist[ed] = dist[st] + cost;
				from[ed] = st;
				pq.push({ -dist[ed],ed });
			}
		}
	}
	stack<int> s;
	for (int i = des; from[i] != 0; i = from[i]) s.push(i);
	
	printf("%d\n%d\n%d", dist[des], s.size() + 1, src);
	while (!s.empty()) {
		printf(" %d", s.top());
		s.pop();
	}

	return 0;
}