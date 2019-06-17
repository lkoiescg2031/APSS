//================================================================================
//LCA O(N)
#include <queue>
#include <algorithm>
using namespace std;

int v, root_node_number;
vector<vector<int>> adj;
vector<int> from, depth;
queue<int> q;

int LCA(int x,int y) {

	//선행처리
	v = adj.size();
	from = depth = vector<int>(v + 1);
	q.push(root_node_number);
	from[root_node_number] = -1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto i : adj[u]) 
			if (from[i] == 0) {
				from[i] = u;
				depth[i] = depth[u] + 1;
				q.push(i);
			}
	}
	//LCA 부분
	if (depth[x] < depth[y]) swap(x, y);	
	while (depth[x] != depth[y]) x = from[x];
	while (x != y) x = from[x], y = from[y];
	return x;
}

//================================================================================
//LCA DP O(lgN)
#include <queue>
#include <algorithm>
using namespace std;

const int tree_high_max = 20;

int v, root_node_number;
vector<vector<int>> adj;

vector<int> from, depth;
queue<int> q;

int parent[100001][tree_high_max];//dp[i][j] = i의 2^j번째 조상

int LCA(int x, int y) {

	//선행처리
	v = adj.size();
	from = depth = vector<int>(v + 1);
	q.push(root_node_number);
	from[root_node_number] = -1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto i : adj[u])
			if (from[i] == 0) {
				from[i] = u;
				depth[i] = depth[u] + 1;
				q.push(i);
			}
	}
	//dp 초기화
	for (int i = 1; i <= v; i++)
		parent[i][0] = from[i];

	//dp
	for (int j = 1; (1 << j) < v; j++) 
		for(int i=1;i<=v;i++)
			if (parent[i][j - 1] != 0) 
				parent[i][j] = parent[parent[i][j - 1]][j - 1];

	//LCA 부분
	if (depth[x] < depth[y]) swap(x, y);
	int log = 1; for (; (1 << log) <= x; log++); log--;

	for (int i = log; i >= 0; i--)
		if (depth[x] - (1 << log) >= depth[y])
			x = parent[x][i];

	for (int i = log; i >= 0; i--)
		if (parent[x][i] != 0 && parent[x][i] != parent[y][i])
			x = parent[x][i], y = parent[y][i];

	return parent[x][0];
}
//================================================================================
//LCA DFS + DP
#include <vector>

int v;
vector<vector<int>> adj;
vector<int> tin, tout;
int timer;
vector<vector<int>> dp_parent;
int high;

int dfs(int v, int from) {
	tin[v] = ++timer;

	dp_parent[v][0] = from;
	for (int i = 1; i <= high; i++)
		dp_parent[v][i] = dp_parent[dp_parent[v][i - 1]][i - 1];

	for (auto i : adj[v])
		if (i != from)
			dfs(i, v);

	tout[v] = ++timer;
}

void init() {

	for (high = 1; (1 << high) < v; high++);
	dp_parent = vector<vector<int>>(v + 1, vector<int>(high + 1));
	tin = tout = vector<int>(v + 1, 0);
	dfs(1, 1);
}

int upper(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v) {
	if (upper(u, v)) return u;
	else if (upper(v, u)) return v;

	for (int i = high; i >= 0; i--)
		if (!upper(dp_parent[u][i], v))
			u = dp_parent[u][i];

	return dp_parent[u][0];
}
//===============================================================================
//RMQ(Range Minimum Query)
//segment tree
#include <vector>
#include <algorithm>
using namespace std;

const int null = 0x3f3f3f3f;

int n;
vector<int> num_list;
vector<int> tree(2 * n);

void init(int node, int src, int des) {
	if (src == des) {
		tree[node] = num_list[src];
		return;
	}
	init(node * 2, src, (src + des) / 2);
	init(node * 2 + 1, (src + des) / 2 + 1, des);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int i, int j, //검색한 범위
	int node = 1, int src = 1, int des = n) {//현재 탐색중인 노드의 범위
	if (des < i || j < src) return null;
	if (i <= src && des <= j) return tree[node];
	int left = query(i, j, node * 2, src, (src + des) / 2);
	int right = query(i, j, node * 2 + 1, (src + des) / 2 + 1, des);
	if (left == null) return right;
	if (right == null) return left;
	return min(left, right);
}