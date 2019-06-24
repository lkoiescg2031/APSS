#include <cstdio>
#include <tuple>
#include <queue>
using namespace std;

const int inf = 0x3f3f3f3f;

int n, m;
vector<pair<int, int>> adj[501];

int main() {

	int from, to, cost;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		adj[from].push_back({ to,cost });
	}

	bool neg_cycle = false;
	vector<int> dist(n + 1, inf);
	vector<int> qcnt(n + 1, 0);
	vector<bool> inq(n + 1, 0);
	
	queue<int> q;
	dist[1] = 0;
	q.push(1); inq[1] = true; qcnt[1]++;
	while (!q.empty()) {
		from = q.front();
		q.pop();
		inq[from] = false;
		for (auto i : adj[from]) {
			tie(to, cost) = i;
			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
				if (!inq[to]) 
					if (qcnt[to] >= n)
						neg_cycle = true;
					else 
						q.push(to), inq[to] = true, qcnt[to]++;
			}
		}
	}
	
	if (neg_cycle) printf("-1");
	else
		for (int i = 2; i <= n; i++)
			if (dist[i] == inf) printf("-1\n");
			else printf("%d\n", dist[i]);

	return 0;
}