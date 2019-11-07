//================================================================================
//LCA O(N)
#include <queue>
#include <algorithm>
using namespace std;
int v, root_node_number;
vector<vector<int>> adj;
vector<int> from, depth;
queue<int> qn;

int LCA(int x,int y) {

	//선행처리
	v = adj.size();
	from = depth = vector<int>(v + 1);
	qn.push(root_node_number);
	from[root_node_number] = -1;
	while (!qn.empty()) {
		int u = qn.front();
		qn.pop();
		for (auto i : adj[u]) 
			if (from[i] == 0) {
				from[i] = u;
				depth[i] = depth[u] + 1;
				qn.push(i);
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
queue<int> qn;

int parent[100001][tree_high_max];//dp[i][j] = i의 2^j번째 조상

int LCA(int x, int y) {

	//선행처리
	v = adj.size();
	from = depth = vector<int>(v + 1);
	qn.push(root_node_number);
	from[root_node_number] = -1;
	while (!qn.empty()) {
		int u = qn.front();
		qn.pop();
		for (auto i : adj[u])
			if (from[i] == 0) {
				from[i] = u;
				depth[i] = depth[u] + 1;
				qn.push(i);
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
vector<int> tree;
//트리의 높이 H = [log N], 노드의 수 tree_size = 2^(H+1);
//int tree_high = ceil(log2(n)); //#include <cmath>
//int tree_size = (1 << (tree_high + 1));

void init(int node = 1, int src =0, int des=n-1) {
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
//=================================================================================
// RSQ
// segment tree - 비재귀로 구현
#include <vector>
using namespace std;

int n, terminal_node_start;
vector<int> tree; // tree배열의 크기 n은 2^k 꼴이어야 함

void terminal_node_cal() {
	terminal_node_start = 1;
	while (terminal_node_start <= n)terminal_node_start *= 2;
	terminal_node_start--;
}
void update(int i,int num) {
	i += terminal_node_start;
	int diff = num - tree[i];
	while (i > 0) tree[i] += diff, i /= 2;
}
int sum(int i, int j) {
	i += terminal_node_start, j += terminal_node_start;
	int ret = 0;
	while (i < j) {
		if (i % 2 == 0) i /= 2;
		else ret += tree[i], i = (i + 1) / 2;
		if (j % 2 == 1) j /= 2;
		else ret += tree[j], j = (j - 1) / 2;
	}
	if (i == j) ret += tree[i];
	return ret;
}
//=================================================================================
//segment tree - lazy propagation
//세그먼트 트리 구간 업데이트를 lazy propagation으로 계산
#include <vector>
using namespace std;

int n;
vector<int> a;
vector<int> tree, lazy;

void seg_init(int node, int start, int end) {
	if (start == end) tree[start] = a[start];
	else {
		init(2*node, start, (start + end) / 2);
		init(2 * node + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}
void lazy_update(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	} 
}
void update_range(int node, int start, int end, int i, int j, int diff) {
	lazy_update(node, start, end);
	if (end < i || j < start) return;
	if (i <= start && end <= j) {
		tree[node] = (end - start + 1) * diff;
		if (start != end) {
			lazy[2 * node] += diff;
			lazy[2 * node + 1] += diff;
		}
		return;
	}
	update_range(2 * node, start, (start + end) / 2, i, j, diff);
	update_range(2 * node + 1, (start + end) / 2 + 1, end, i, j, diff);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int sum(int node, int start, int end, int i, int j) {
	lazy_update(node, start, end);
	if (end < i || j < start) return 0;
	if (i <= start || end <= j) return tree[node];
	return sum(2 * node, start, (start + end) / 2, i, j) +
		sum(2 * node + 1, (start + end) / 2 + 1, end, i, j);
}
//==================================================================================
//RSQ 펜윅트리 (바이너리 인덱스 트리, BIT, Binary index tree, Fenwick tree)
//트리의 크기는 (n+1)만큼 필요
#include <vector>
namespace BIT {
	using namespace std;

	template<typename T = int>
	using BIT = vector<T>;
	
	template<typename T =int>
	void init_tree(BIT<T>& tree, int terminal_node_size, T value) {
		tree = BIT<T>(terminal_node_size + 1, value);
	}

	template<typename T = int>
	void update(BIT<T>& tree, int i, T diff) {
		while (i < tree.size())
			tree[i] += diff, i += (i & -i);
	}

	template<typename T = int>
	T sum(BIT<T>& tree, int i) {
		T ret = 0;
		while (i > 0)
			ret += tree[i], i -= (i & -i);
		return ret;
	}

	template<typename T = int>
	T sum(BIT<T> & tree, int i, int j) {
		if (j < i) return 0;
		return sum(tree, j) - sum(tree, i - 1);
	}
}
//===================================================================================
//2 Demension BIT
//차원을 늘릴경우 for문만 한번씩더 중첩시키면 된다.
#include <vector>
namespace BIT2D {
	using namespace std;
	template<typename T = int>
	using BIT2D = vector<vector<T>>;

	template<typename T = int>
	void init_tree(BIT2D<T> & tree, int i_node_size, int j_node_size, T value = 0) {
		tree = BIT2D<T>(i_node_size, vector<T>(j_node_size, value));
	}

	template<typename T = int>
	void update(BIT2D<T> & tree, int i, int j, T diff) {
		while (i < tree.size()) {
			while (j < tree[i].size())
				tree[i][j] += diff, j += (i & -i);
			i += (i & -i);
		}
	}

	template<typename T = int>
	T sum(BIT2D<T> & tree, int i, int j) {
		T ret = 0;
		while (i > 0) {
			while (j < tree[i].size())
				ret += tree[i][j], j -= (j & -j);
			i -= (i & -i);
		}
	}

	template<typename T = int>
	T sum(BIT2D<T> & tree, int x1, int y1, int x2, int y2) {
		if (x2 < x1 || y2 < y1) return 0;
		return sum(tree, x2, y2) - sum(tree, x2, y1 - 1) - sum(tree, x1 - 1, y2) + sum(tree, x1 - 1, y1 - 1);
	}
}
