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

int n, m;
char map[100][100];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int innode(int i, int j) {
	return i * m + j;
}
int outnode(int i, int j) {
	return n * m + i * m + j;
}

int main() {

	scanf("%d %d\n", &n, &m);
	int s = 0, t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'K') s = outnode(i, j);
			if (map[i][j] == 'H') t = innode(i, j);
		}
		getchar();
	}

	MaximumFlow mf(2 * n * m, s, t);

	for (int x = 0; x < n; x++) for (int y = 0; y < m; y++) {
		if (map[x][y] == '#') continue;
		mf.add_edge(innode(x, y), outnode(x, y), 1);
		for (int k = 0; k < 4; k++) {
			int mx = x + dx[k];
			int my = y + dy[k];
			if (mx>=0 && mx < n && my>=0 && my < m) {
				if (map[mx][my] == '#') continue;
				mf.add_edge(outnode(x, y), innode(mx, my), inf);
			}
		}
	}
	int ans = mf.flow();
	if (ans >= inf) ans = -1;
	printf("%d", ans);

	return 0;
}