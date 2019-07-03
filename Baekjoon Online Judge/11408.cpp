#include <cstdio>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

struct MCMF {

	MCMF(int n, int s, int t) : n(n), source(s), sink(t) {
		graph.resize(n);
		dist.resize(n);
		from.resize(n);
		inq.resize(n);
	}
	void add_edge(int u, int v, int capacity, int cost) {
		Edge* ori = new Edge(v, capacity, cost);
		Edge* rev = new Edge(u, 0, -cost);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	void add_edge_from_source(int u, int capacity, int cost) {
		add_edge(source, u, capacity, cost);
	}
	void add_edge_to_sink(int v, int capacity, int cost) {
		add_edge(v, sink, capacity, cost);
	}
	bool spfa(int& total_flow, int& total_cost) {
		fill(begin(dist), end(dist), inf);
		fill(begin(from), end(from), make_pair(-1, -1));
		fill(begin(inq), end(inq), false);

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
					inq[y] = true;
					q.push(y);
				}
			}
		}

		if (dist[sink] == inf) return false;

		int f = inf;
		for (int i = sink; from[i].first != -1; i = from[i].first)
			f = min(f, graph[from[i].first][from[i].second]->capacity);
		for (int i = sink; from[i].first != -1; i = from[i].first) {
			auto e = graph[from[i].first][from[i].second];
			e->capacity -= f;
			e->rev->capacity += f;
		}
		total_flow += f;
		total_cost += f * dist[sink];
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
		Edge(int to, int cap, int cost) 
			: to(to), capacity(cap), cost(cost), rev (nullptr) {}
	};

	const static int inf = 0x3f3f3f3f;

	int n;
	int source, sink;
	vector<vector<Edge*>> graph;
	vector<int> dist;
	vector<pair<int,int>> from;
	vector<bool> inq;
};

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	MCMF mcmf(n + m + 2, n + m, n + m + 1);

	for (int i = 0; i < n; i++)
		mcmf.add_edge_from_source(i, 1, 0);
	for (int i = 0; i < m; i++)
		mcmf.add_edge_to_sink(i + n, 1, 0);

	for (int i = 0; i < n; i++) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			int work, cost;
			scanf("%d %d", &work, &cost);
			mcmf.add_edge(i, work - 1 + n, 1, cost);
		}
	}

	auto ans = mcmf.flow();
	printf("%d\n%d", ans.first, ans.second);

	return 0;
}