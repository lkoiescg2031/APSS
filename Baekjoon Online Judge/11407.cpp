#include <cstdio>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

struct MCMF {
	MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
		graph.resize(n);
		inque.resize(n);
		dist.resize(n);
		from.resize(n);
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
	void add_edge_to_sink(int u, int capacity, int cost) {
		add_edge(u, sink, capacity, cost);
	}
	pair<int, int> flow() {
		int total_flow = 0, total_cost = 0;
		while (spfa(total_flow, total_cost));
		return make_pair(total_flow, total_cost);
	}

	bool spfa(int& total_flow, int& total_cost) {
		fill(begin(inque), end(inque), false);
		fill(begin(dist), end(dist), inf);
		fill(begin(from), end(from), make_pair(-1, -1));

		queue<int> q;
		q.push(source);
		inque[source] = true;
		dist[source] = 0;

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			inque[x] = false;
			for (int i = 0; i < graph[x].size(); i++) {
				auto e = graph[x][i];
				int y = e->to;
				if (e->capacity > 0 && dist[y] > dist[x] + e->cost) {
					dist[y] = dist[x] + e->cost;
					from[y] = make_pair(x, i);
					if (inque[y]) continue;
					inque[y] = true;
					q.push(y);
				}
			}
		}
		if (from[sink].first == -1) return false;

		int f = graph[from[sink].first][from[sink].second]->capacity;
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
	struct Edge {
		int to, capacity, cost;
		Edge* rev;
		Edge(int to, int cap, int cost)
			: to(to), capacity(cap), cost(cost), rev(nullptr) {}
	};

	const static int inf = 0x3f3f3f3f;

	int n;
	int source, sink;
	vector<vector<Edge*>> graph;
	vector<bool> inque;
	vector<int> dist;
	vector<pair<int,int>> from;
};

int flow[100][100];
int cost[100][100];

int main() {
	
	int n, m, f;
	scanf("%d %d", &n, &m);

	MCMF mcmf(n + m + 2, n + m, n + m + 1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &f);
		mcmf.add_edge_to_sink(i+m, f, 0);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &f);
		mcmf.add_edge_from_source(i, f, 0);
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) 
			scanf("%d", &flow[i][j]);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &cost[i][j]);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			mcmf.add_edge(i, j+m, flow[i][j], cost[i][j]);

	auto ans = mcmf.flow();

	printf("%d\n%d", ans.first, ans.second);
			
	return 0;
}