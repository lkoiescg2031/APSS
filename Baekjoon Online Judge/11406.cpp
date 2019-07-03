#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

struct networkflow {
	
	networkflow(int n, int s, int t) : n(n), source(s), sink(t) {
		graph.resize(n);
	}
	void add_edge(int u, int v, int cap) {
		Edge* ori = new Edge(v, cap);
		Edge* rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	void add_edge_from_source(int v, int cap) {
		add_edge(source, v, cap);
	}
	void add_edge_to_sink(int v, int cap) {
		add_edge(v, sink, cap);
	}
	int bfs() {
		vector<bool> visit(n,false);
		vector<pair<int, int>> from(n,make_pair(-1,-1));
		queue<int> q;
		q.push(source);
		visit[source] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < graph[x].size(); i++) {
				auto e = graph[x][i];
				if (e->capacity > 0 && !visit[e->to]) {
					visit[e->to] = true;
					from[e->to] = make_pair(x, i);
					q.push(e->to);
				}
			}
		}
		
		if (from[sink].first == -1) return 0;

		int f = graph[from[sink].first][from[sink].second]->capacity;

		for (int i = sink; from[i].first != -1; i = from[i].first)
			f = min(f, graph[from[i].first][from[i].second]->capacity);

		for (int i = sink; from[i].first != -1; i = from[i].first) {
			auto e = graph[from[i].first][from[i].second];
			e->capacity -= f;
			e->rev->capacity += f;
		}
		return f;
	}
	int flow() {
		int ret = 0;
		while (true) {
			int f = bfs();
			if (f == 0) break;
			ret += f;
		}
		return ret;
	}

	struct Edge {
		int to, capacity;
		Edge* rev;
		Edge(int to, int cap) : to(to), capacity(cap), rev(nullptr) {}
	};

	int n;
	int source, sink;
	vector<vector<Edge*>> graph;
};

int main() {

	int n, m, u, v, f;
	scanf("%d %d", &n, &m);
	networkflow mf(n + m + 2, n + m, n + m + 1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &f);
		mf.add_edge_to_sink(i, f);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &f);
		mf.add_edge_from_source(n + i, f);
	}

	for(u=0;u<m;u++)
		for (v = 0; v < n; v++) {
			scanf("%d", &f);
			if (f == 0) continue;
			mf.add_edge(u + n, v, f);
		}

	printf("%d", mf.flow());

	return 0;
}