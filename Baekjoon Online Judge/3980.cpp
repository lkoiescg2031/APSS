#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
struct MCMF {
	struct Edge {
		int to;
		int capacity;
		int cost;
		Edge* rev;
		Edge(int to, int capacity, int cost) : to(to), capacity(capacity), cost(cost) {
		}
	};
	int n;
	int source, sink;
	vector<vector<Edge*>> graph;
	vector<bool> check;
	vector<int> distance;
	vector<pair<int, int>> from;
	int inf = 10000000;
	MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
		graph.resize(n);
		check.resize(n);
		from.resize(n, make_pair(-1, -1));
		distance.resize(n);
	};
	void add_edge(int u, int v, int cap, int cost) {
		Edge* ori = new Edge(v, cap, cost);
		Edge* rev = new Edge(u, 0, -cost);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	void add_edge_from_source(int v, int cap, int cost) {
		add_edge(source, v, cap, cost);
	}
	void add_edge_to_sink(int u, int cap, int cost) {
		add_edge(u, sink, cap, cost);
	}
	bool spfa(int& total_flow, int& total_cost) {
		fill(check.begin(), check.end(), false);
		fill(distance.begin(), distance.end(), inf);
		fill(from.begin(), from.end(), make_pair(-1, -1));
		distance[source] = 0;
		queue<int> q;
		q.push(source);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			check[x] = false;
			for (int i = 0; i < graph[x].size(); i++) {
				auto e = graph[x][i];
				int y = e->to;
				if (e->capacity > 0 && distance[x] + e->cost < distance[y]) {
					distance[y] = distance[x] + e->cost;
					from[y] = make_pair(x, i);
					if (!check[y]) {
						check[y] = true;
						q.push(y);
					}
				}
			}
		}
		if (distance[sink] == inf) {
			return false;
		}
		int x = sink;
		int c = graph[from[x].first][from[x].second]->capacity;
		while (from[x].first != -1) {
			if (c > graph[from[x].first][from[x].second]->capacity) {
				c = graph[from[x].first][from[x].second]->capacity;
			}
			x = from[x].first;
		}
		x = sink;
		while (from[x].first != -1) {
			Edge* e = graph[from[x].first][from[x].second];
			e->capacity -= c;
			e->rev->capacity += c;
			x = from[x].first;
		}
		total_flow += c;
		total_cost += c * distance[sink];
		return true;
	}
	pair<int, int> flow() {
		int total_flow = 0;
		int total_cost = 0;
		while (spfa(total_flow, total_cost));
		return make_pair(total_flow, total_cost);
	}
};

const int n = 11, m = 11;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		MCMF mcmf(n + m + 2, n + m, n + m + 1);
		for (int i = 0; i < n; i++)
			mcmf.add_edge_from_source(i, 1, 0);
		for (int i = 0; i < m; i++)
			mcmf.add_edge_to_sink(i + n, 1, 0);
		for (int u=0;u<n;u++)
			for (int v = 0; v < m; v++) {
				int cost;
				scanf("%d", &cost);
				if (cost == 0) continue;
				mcmf.add_edge(u, n + v, 1, -cost);
			}
		printf("%d\n", -mcmf.flow().second);
	}
	return 0;
}