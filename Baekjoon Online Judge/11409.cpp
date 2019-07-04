#include <cstdio>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

struct MCMF {
	
	MCMF(int n, int s, int t) : n(n), source(s), sink(t) {
		graph.resize(n);
		inq.resize(n);
		from.resize(n);
		dist.resize(n);
	}
	void add_edge(int u, int v, int capacity, int cost) {
		Edge* ori = new Edge(v, capacity, cost);
		Edge* rev = new Edge(u, 0, -cost);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	void add_edge_from_source(int v, int capacity, int cost) {
		add_edge(source, v, capacity, cost);
	}
	void add_edge_to_sink(int v, int capacity, int cost) {
		add_edge(v, sink, capacity, cost);
	}
	bool spfa(int& total_flow, int& total_cost) {
		fill(begin(inq), end(inq), false);
		fill(begin(from), end(from), make_pair(-1, -1));
		fill(begin(dist), end(dist), inf);

		queue<int> q;
		q.push(source);
		dist[source] = 0;
		inq[source] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			inq[x] = false;
			for (int i = 0; i < graph[x].size(); i++) {
				auto e = graph[x][i];
				int y = e->to;
				if (e->capacity > 0 && dist[y] > dist[x] + e->cost) {
					dist[y] = dist[x] + e->cost;
					from[y] = make_pair(x, i);
					if (inq[y]) continue;
					q.push(y);
					inq[y] = true;
				}
			}
		}
		if (dist[sink] == inf) return false;

		int flow = inf;
		for (int i = sink; from[i].first != -1; i = from[i].first)
			flow = min(flow, graph[from[i].first][from[i].second]->capacity);
		for (int i = sink; from[i].first != -1; i = from[i].first) {
			auto e = graph[from[i].first][from[i].second];
			e->capacity -= flow;
			e->rev->capacity += flow;
		}
		total_flow += flow;
		total_cost += flow * dist[sink];
		return true;
	}
	pair<int, int> flow() {
		int total_flow = 0, total_cost = 0;
		while (spfa(total_flow, total_cost));
		return make_pair(total_flow, total_cost);
	}
	struct Edge {
		int to, capacity, cost;
		Edge* rev;
		Edge(int to, int capacity, int cost)
			: to(to), capacity(capacity), cost(cost), rev(nullptr) {}
	};
	const static int inf = 0x3f3f3f3f;
	int n;
	int source, sink;
	vector<vector<Edge*>> graph;
	vector<bool> inq;
	vector<pair<int, int>> from;
	vector<int> dist;
};

int main() {
	int n, m, u, v, f, c;
	
	scanf("%d %d", &n, &m);
	MCMF mcmf(n + m + 2, n + m, n + m + 1);
	for (int i = 0; i < n; i++)
		mcmf.add_edge_from_source(i, 1, 0);
	for (int i = 0; i < m; i++)
		mcmf.add_edge_to_sink(i+n, 1, 0);
	for (int u = 0; u < n; u++) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			scanf("%d %d", &v, &c);
			mcmf.add_edge(u, v - 1 + n, 1, -c);
		}
	}
	auto ans = mcmf.flow();
	printf("%d\n%d", ans.first, -ans.second);
	return 0;
}