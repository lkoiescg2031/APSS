#include <cstdio>
#include <queue>
using namespace std;

struct MaximumFlow {
	struct Edge {
		int to;
		int capacity;
		Edge* rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {
		}
	};
	int n;
	int source, sink;
	vector<vector<Edge*>> graph;
	MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
		graph.resize(n);
	};
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
		vector<bool> check(n, false);
		vector<pair<int, int>> from(n, make_pair(-1, -1));
		queue<int> q;
		q.push(source);
		check[source] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < graph[x].size(); i++) {
				if (graph[x][i]->capacity > 0 && !check[graph[x][i]->to]) {
					q.push(graph[x][i]->to);
					check[graph[x][i]->to] = true;
					from[graph[x][i]->to] = make_pair(x, i);
				}
			}
		}
		if (!check[sink]) {
			return 0;
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
		return c;
	}
	int flow() {
		int ans = 0;
		while (true) {
			int f = bfs();
			if (f == 0) break;
			ans += f;
		}
		return ans;
	}
};
const int inf = 0x3f3f3f3f;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int start, people,s;
		scanf("%d %d %d", &start, &people, &s);
		MaximumFlow mf(n * (s + 1) + 2, n * (s + 1), n * (s + 1) + 1);
		start -= 1;
		int m;
		scanf("%d", &m);
		vector<int> hospital(m);
		for (auto& i : hospital) scanf("%d", &i), i--;
		int r;
		scanf("%d", &r);
		while (r--) {
			int u, v, p, t;
			scanf("%d %d %d %d", &u, &v, &p, &t);
			u--, v--;
			for (int i = 0; i < s - t + 1; i++) 
				mf.add_edge(u + n * i, v + n * (i + t), p);
		}
		mf.add_edge_from_source(start,people);
		for (int h : hospital) mf.add_edge_to_sink(h + n * s, inf);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < s; j++)
				mf.add_edge(i + n * j, i + n * (j + 1), inf);
		printf("%d\n", mf.flow());
	}
	return 0;
}