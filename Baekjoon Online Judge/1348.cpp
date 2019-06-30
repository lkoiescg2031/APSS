#include <cstdio>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

struct biparite_matching {
	int n;
	vector<vector<int>> adj;
	vector<bool> visit;
	vector<int> pre;

	biparite_matching(int n) : n(n) {
		adj.resize(n);
		visit.resize(n);
		pre.resize(n, -1);
	}

	void add_edge(int i, int j) {
		adj[i].push_back(j);
	}

	int flow() {
		int ret = 0;
		for (int i = 0; i < n; i++) {
			fill(begin(visit), end(visit), false);
			if (dfs(i)) ret++;
		}
		return ret;
	}

	bool dfs(int i) {
		if (i == -1) return true;
		for (auto j : adj[i]) {
			if (visit[j]) continue;
			visit[j] = true;
			if (dfs(pre[j])) {
				pre[j] = i;
				return true;
			}
		}
		return false;
	}
};

const int inf = 0x3f3f3f3f;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int n, m;
char map[50][50];

vector<pair<int, int>> car, park;

int main() {

	scanf("%d %d\n", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'C') car.push_back({ i,j });
			else if (map[i][j] == 'P') park.push_back({ i,j });
		}
		getchar();
	}

	if (car.size() > park.size()) {
		printf("-1");
		return 0;
	}
	if (car.size() == 0) {
		printf("0");
		return 0;
	}

	vector<vector<pair<int, int>>> adj(car.size());
	for (int k = 0; k < car.size(); k++) {
		vector<vector<int>> cost(n, vector<int>(m, -1));
		queue<pair<int, int>> q;

		auto c = car[k];
		q.push(c);
		cost[c.first][c.second] = 0;

		int x, y;
		while (!q.empty()) {
			tie(x, y) = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int mx = x + dx[i];
				int my = y + dy[i];
				if (mx >= 0 && my >= 0 && mx < n && my < m &&
					map[mx][my] != 'X' && cost[mx][my] == -1) {
					cost[mx][my] = cost[x][y] + 1;
					q.push({ mx,my });
				}
			}
		}

		for (int i = 0; i < park.size(); i++) {
			auto& p = park[i];
			tie(x, y) = p;
			if (cost[x][y] != -1)
				adj[k].push_back({ i,cost[x][y] });
		}
	}

	int ans = inf;
	int l = 0, r = n * m + 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		biparite_matching nf(max(car.size(), park.size()));
		for (int i = 0; i < car.size(); i++) for (auto p : adj[i]) {
			if (p.second <= mid) nf.add_edge(i, p.first);
		}

		if (nf.flow() == car.size()) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}

	if (ans == inf) ans = -1;
	printf("%d", ans);

	return 0;
}