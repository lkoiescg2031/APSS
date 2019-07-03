#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

struct MCMF {

	const static int inf = 0x3f3f3f3f;
	
	struct Edge {
		int to, capacity, cost;
		Edge* reverse;
		Edge(int to, int capacity, int cost)
			: to(to), capacity(capacity), cost(cost),reverse(nullptr) {}
	};

	MCMF(int n, int s, int t) : n(n), source(s), sink(t) {
		graph.resize(n);
		inque.resize(n);
		from.resize(n);
		dist.resize(n);
	}
	void add_edge(int u, int v, int cap, int cost) {
		Edge* ori = new Edge(v, cap, cost);
		Edge* rev = new Edge(u, 0, -cost);
		ori->reverse = rev;
		rev->reverse = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	void add_edge_from_source(int v, int cap, int cost) {
		add_edge(source, v, cap, cost);
	}
	void add_edge_to_sink(int v, int cap, int cost) {
		add_edge(v, sink, cap, cost);
	}
	pair<int, int> flow() {
		int total_flow = 0;
		int total_cost = 0;
		while (spfa(total_flow, total_cost));
		return make_pair(total_flow, total_cost);
	}
	bool spfa(int& total_flow, int& total_cost) {
		fill(begin(inque), end(inque), false);
		fill(begin(dist), end(dist), inf);
		fill(begin(from), end(from), make_pair(-1, -1));

		queue<int> q;
		q.push(source);
		dist[source] = 0;
		inque[source] = true;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			inque[cur] = false;
			for (int i = 0; i < graph[cur].size(); i++) {
				auto edge = graph[cur][i];
				int next = edge->to;
				if (edge->capacity > 0 && dist[next] > dist[cur] + edge->cost) {
					dist[next] = dist[cur] + edge->cost;
					from[next] = make_pair(cur, i);
					if (inque[next]) continue;
					inque[next] = true;
					q.push(next);
				}
			}
		}

		if (dist[sink] == inf) return false;

		int f = graph[from[sink].first][from[sink].second]->capacity;
		for (int i = sink; from[i].first != -1; i = from[i].first)
			f = min(f, graph[from[i].first][from[i].second]->capacity);

		for (int i = sink; from[i].first != -1; i = from[i].first) {
			auto edge = graph[from[i].first][from[i].second];
			edge->capacity -= f;
			edge->reverse->capacity += f;
		}

		total_flow += f;
		total_cost += f * dist[sink];
		return true;
	}
	int n;
	int source, sink;
	vector<vector<Edge*>> graph;
	vector<bool> inque;
	vector<int> dist;
	vector<pair<int, int>> from;
};

int main() {

	int n, m, v, u, cost, flow;
	scanf("%d %d", &n, &m);
	MCMF mcmf(n + m + 2, n + m, n + m + 1);

	for (int i = 0; i < n; i++) {
		scanf("%d", &flow);
		mcmf.add_edge_to_sink(m + i, flow, 0);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &flow);
		mcmf.add_edge_from_source(i, flow, 0);
	}

	for(u=0;u<m;u++)
		for (v = 0; v < n; v++) {
			scanf("%d", &cost);
			mcmf.add_edge(u, v + m, mcmf.inf, cost);
		}
	printf("%d", mcmf.flow().second);
	return 0;
}