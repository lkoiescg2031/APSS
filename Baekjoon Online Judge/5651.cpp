#include <cstdio>
#include <queue>
using namespace std;

struct MaximumFlow {
	struct Edge {
		int from;
		int to;
		int capacity;
		Edge* rev;
		Edge(int from, int to, int capacity) : from(from), to(to), capacity(capacity),rev(nullptr) {}
	};
	int n;
	int source, sink;
	vector<int> check;
	int step;
	vector<vector<Edge*>> graph;
	vector<Edge*> edge;
	MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
		graph.resize(n);
		check.resize(n);
	};
	void add_edge(int u, int v, int cap) {
		Edge* ori = new Edge(u,v, cap);
		Edge* rev = new Edge(v,u, 0);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
		edge.push_back(ori);
	}
	int bfs() {
		step++;
		vector<pair<int, int>> from(n, make_pair(-1, -1));
		queue<int> q;
		q.push(source);
		check[source] = step;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < graph[x].size(); i++) {
				if (graph[x][i]->capacity > 0 && check[graph[x][i]->to] != step) {
					q.push(graph[x][i]->to);
					check[graph[x][i]->to] = step;
					from[graph[x][i]->to] = make_pair(x, i);
				}
			}
		}
		if (check[sink] != step) {
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
	int dfs(int x,int goal) {
		if (x == goal) return true;
		check[x] = step;
		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i]->to;
			if (check[next] != step && graph[x][i]->capacity > 0
				&& dfs(next,goal))
				return true;
		}
		return false;
	}
	int crucial() {
		flow();
		int ret = 0;
		for (auto e : edge) {
			step++;
			if (!dfs(e->from, e->to)) ret++;
		}
		return ret;
	}
};
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		MaximumFlow mf(n, 0, n - 1);
		for (int i = 0; i < m; i++) {
			int u, v, f;
			scanf("%d %d %d", &u, &v, &f);
			mf.add_edge(u - 1, v - 1, f);
		}
		printf("%d\n", mf.crucial());
	}
	return 0;
}