#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

struct MCMF {
public:
	const static int INF = 0x3f3f3f3f;
	MCMF(int n, int s, int t) : n(n), source(s), sink(t) {
		graph.resize(n);
		inq.resize(n);
		dist.resize(n);
		pre.resize(n);
	};
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
	void add_edge_to_sink(int u, int capacity, int cost) {
		add_edge(u, sink, capacity, cost);
	}
	pair<int, int> flow() {
		int total_flow = 0, total_cost = 0;
		while (spfa(total_flow, total_cost));
		return make_pair(total_flow, total_cost);
	}
private:
	struct Edge {
		int to, capacity, cost;
		Edge* rev;
		Edge(int to, int capacity, int cost)
			: to(to), cost(cost), capacity(capacity), rev(nullptr) {}
	};
	using Vertex = pair<int, int>;
	int n;
	int source, sink;
	vector<vector<Edge*>> graph;
	vector<bool> inq;
	vector<int> dist;
	vector<Vertex> pre;
	bool spfa(int& total_flow, int& total_cost) {

		fill(begin(inq), end(inq), false);
		fill(begin(pre), end(pre), make_pair(-1, -1));
		fill(begin(dist), end(dist), INF);

		queue<int> q;
		q.push(source);
		inq[source] = true;
		dist[source] = 0;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			inq[cur] = false;
			for (int i = 0; i < graph[cur].size(); i++) {
				auto e = graph[cur][i];
				int next = e->to;
				if (e->capacity > 0 && dist[next] > dist[cur] + e->cost) {
					dist[next] = dist[cur] + e->cost;
					pre[next] = make_pair(cur, i);
					if (inq[next]) continue;
					q.push(next);
					inq[next] = true;
				}
			}
		}

		if (dist[sink] == INF) return false;

		int min_flow = INF;
		for (int i = sink; pre[i].first != -1; i = pre[i].first)
			min_flow = min(min_flow, graph[pre[i].first][pre[i].second]->capacity);
		for (int i = sink; pre[i].first != -1; i = pre[i].first) {
			auto e = graph[pre[i].first][pre[i].second];
			e->capacity -= min_flow;
			e->rev->capacity += min_flow;
		}
		total_flow += min_flow;
		total_cost += dist[sink] * min_flow;
		return true;
	}
};

int ticket(int x, int y, int n) {
	return n + (n - 1) * n / 2 - (n - x - 1) * (n - x) / 2 + (y - x - 1);
}
int a[100][100];
int b[100][100];
int o[100][100];
int arrived[100];
int officer[100];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, p;
		cin >> n >> p;
		for (int i = 0; i < n - 1; i++) 
			for (int j = i + 1; j < n; j++) 
				cin >> b[i][j];
		for (int i = 0; i < n - 1; i++) 
			for (int j = i + 1; j < n; j++) 
				cin >> a[i][j];
		for (int i = 0; i < n; i++) officer[i] = 0;
		for (int i = 0; i < n - 1; i++) 
			for (int j = i + 1; j < n; j++) {
				cin >> o[i][j];
				for (int k = i; k < j; k++) 
					officer[k] += o[i][j];
			}
		int total = n + (n - 1) * n / 2 + 2;
		MCMF mcmf(total, total - 2, total - 1);
		for (int i = 0; i < n - 1; i++) 
			mcmf.add_edge(i, i + 1, p - officer[i], 0);
		for (int i = 0; i < n; i++) arrived[i] = 0;
		for (int i = 0; i < n - 1; i++) 
			for (int j = i + 1; j < n; j++) {
				mcmf.add_edge_from_source(ticket(i, j, n), a[i][j], 0);
				mcmf.add_edge(ticket(i, j, n), i, a[i][j], -b[i][j]);
				mcmf.add_edge(ticket(i, j, n), j, a[i][j], 0);
				arrived[j] += a[i][j];
			}
		for (int i = 1; i < n; i++) 
			mcmf.add_edge_to_sink(i, arrived[i], 0);
		cout << -mcmf.flow().second << '\n';
	}
	return 0;
}