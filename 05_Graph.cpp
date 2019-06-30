 //=======================================================================
//위상정렬
//Topological Sort
#include <queue>
using namespace std;

int n;
vector<int> ind;
vector<vector<int>> graph;

void Topological_Sort() {
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (ind[i] == 0)
			q.push(i);

	for (int i = 0; i < n; i++) {
		int cur = q.front();
		q.pop();

		for (auto next : graph[cur]) {
			ind[next]--;
			if (ind[next] == 0) q.push(next);
		}
	}
}
//========================================================================
//MST - Prim
#include <queue>
#include <tuple>
using namespace std;

int n,start;
vector<vector<pair<int, int>>> graph2;
vector<bool> isvisit;

void prim() {
	int cur, next, cost;
	priority_queue <tuple<int, int>, vector<tuple<int, int>>, 
		greater<tuple<int, int>>> q;

	isvisit[start] = true;
	for (auto i : graph2[start]) {
		tie(next, cost) = i;
		q.push({ cost,next });
	}

	while (!q.empty()) {
		tie(cost, cur) = q.top();
		q.pop();
		if (isvisit[cur]) continue;
		isvisit[cur] = true;
		for (auto i : graph2[cur]) {
			tie(next, cost) = i;
			if(!isvisit[next])	q.push({ cost,next });
		}		
	}
}
//==========================================================================
//MST - kruskal (need disjoint set)
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int v, e;
vector<tuple<int, int, int>> graph3;
vector<int> parent;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	int xparent = find(x);
	int yparent = find(y);

	if (xparent == yparent) return;
	parent[xparent] = yparent;
}

void kruskal() {
	int sour, des, w;

	parent = vector<int>(v+1);
	for (int i = 0; i <= v; i++) parent[i] = i;

	sort(begin(graph3), end(graph3));

	for (int i = 0; i < e; i++) {
		tie(w, sour, des);
		sour = find(sour);
		des = find(des);
		if (sour != des) merge(sour, des);
	}
}
//===========================================================================
//최단경로 (Bellman-Ford) 
//음수 가중치가 존재할 경우에도 계산
//음수 사이클 확인 가능
#include <tuple>
#include <vector>
using namespace std;

const int inf = 0x3f3f3f3f;

int v, e;
int start;
vector<tuple<int,int,int>> graph4;
vector<int> dist;
bool negtive_cycle = false;

void Bellman_Ford() {

	int from, to, cost;
	dist = vector<int>(v + 1, inf);
	dist[start] = 0;
	for(int i=1;i<=v;i++)
		for (int j = 0; j < e; j++) {
			tie(from, to, cost) = graph4[i];
			if (dist[from] != inf && dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
				if (i == n) negtive_cycle = true;
			}
		}
}
//===========================================================================
//최단경로 (dijkstra) O(v^2)
//음수 경로가 존재할 경우 불가능
#include <tuple>
#include <queue>
using namespace std;

const int inf = 0x3f3f3f3f;

int v, e;
vector<vector<pair<int, int>>> graph5;
vector<int> dist;
vector<bool> d;
int st;

void dijkstra() {
	int from, to, cost;

	d = vector<bool>(v + 1, false);
	dist = vector<int>(v + 1, inf);
	dist[st] = 0;
	
	priority_queue<pair<int, int>> pq;
	pq.push({ -dist[st],st });
	while (!pq.empty()) {
		from = pq.top().second;
		pq.pop();
		if (d[from]) continue;
		d[from] = true;
		for (auto j : graph5[from]) {
			tie(to, cost) = j;
			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
				pq.push({ -dist[to],to });
			}
		}
	}
}
//===========================================================================
//최단경로 (Floyd) O(v^3)
//모든 최단경로 검색
#include <vector>
using namespace std;

int v, e;
vector<vector<int>> graph6, dist_floyd;

void Floyd_Warshal() {
	dist_floyd = graph6;
	//추적을 위한 배열
	vector<vector<int>> from(v + 1, vector<int>(v + 1, 0));
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			from[i][j] = j;

	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				if (dist_floyd[i][j] > dist_floyd[i][k] + dist_floyd[k][j]) {
					dist_floyd[i][j] = dist_floyd[i][k] + dist_floyd[k][j];
					from[i][j] = from[i][k];
				}
}
//=============================================================================
//SPFA 평균 O(E)
#include <queue>
using namespace std;

const int inf = 0x3f3f3f3f;

int v, e;
vector < vector< pair<int, int> > > graph7;
bool negtive_cycle = false;
int start;

void SPFA() {
	int from, to, cost;
	vector<int> dist(v + 1, inf);
	vector<int> qcnt(v + 1, 0);
	vector<bool> inq(v + 1, false);

	dist[start] = 0;
	queue<int> q;
	q.push(start); inq[start] = true; qcnt[start]++;
	while (!q.empty()) {
		from = q.front();
		q.pop(); inq[from] = false;

		for (auto i : graph7[from]) {
			tie(to, cost) = i;
			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
				if (!inq[to]) {
					if (qcnt[to] == v) 	negtive_cycle = true;
					else q.push(to), inq[to] = true, qcnt[to]++;
				}
			}
		}
	}
}
//=============================================================================
//Ford-Pulkerson (네트워크 플로우) O(Ef)
#include <vector>
#include <algorithm>
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
	vector<bool> check;
	MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
		graph.resize(n);
		check.resize(n);
	};
	void add_edge(int u, int v, int cap) {
		Edge* ori = new Edge(v, cap);
		Edge* rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	int dfs(int x, int c) {
		if (check[x]) return 0;
		check[x] = true;
		if (x == sink) {
			return c;
		}
		for (int i = 0; i < graph[x].size(); i++) {
			if (graph[x][i]->capacity > 0) {
				int nc = graph[x][i]->capacity;
				if (c != 0 && c < nc) {
					nc = c;
				}
				int f = dfs(graph[x][i]->to, nc);
				if (f) {
					graph[x][i]->capacity -= f;
					graph[x][i]->rev->capacity += f;
					return f;
				}
			}
		}
		return 0;
	}
	int flow() {
		int ans = 0;
		while (true) {
			fill(check.begin(), check.end(), false);
			int f = dfs(source, 0);
			if (f == 0) break;
			ans += f;
		}
		return ans;
	}
};
//=============================================================================
//Edmond-karp (네트워크 플로우) O(VE^2)
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
//=============================================================================
//이분 매칭(source와 sink 삭제)
#include <vector>

struct MaximumFlow {
	int n;
	int source, sink;
	vector<vector<int>> graph;
	vector<bool> check;
	vector<int> pred;
	MaximumFlow(int n) : n(n) {
		graph.resize(n);
		check.resize(n);
		pred.resize(n, -1);
	};
	void add_edge(int u, int v) {
		graph[u].push_back(v);
	}
	bool dfs(int x) {
		if (x == -1) return true;
		for (int next : graph[x]) {
			if (check[next]) continue;
			check[next] = true;
			if (dfs(pred[next])) {
				pred[next] = x;
				return true;
			}
		}
		return false;
	}
	int flow() {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			fill(check.begin(), check.end(), false);
			if (dfs(i)) {
				ans += 1;
			}
		}
		return ans;
	}
};