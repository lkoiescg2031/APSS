#include <iostream>
#include <vector>
using namespace std;

int testcase, v, e, ans;
vector<vector<int>> adj;
vector<int> visit;

bool dfs(int cur) {

	bool ret = true;

	for (auto next : adj[cur]) {
		if (!ret) break;
		if (visit[next] == 0) {
			visit[next] = visit[cur] == 1 ? 2 : 1;
			ret = dfs(next);
		}
		else if (visit[next] == visit[cur]) {
			ret = false;
			break;
		}
	}
	return ret;
}

int main() {

	cin >> testcase;
	while (testcase-- > 0) {
		cin >> v >> e;
		adj = vector<vector<int>>(v + 1);
		visit = vector<int>(v + 1, 0);
		ans = true;
		for (int i = 0; i < e; i++) {
			int begin, end;
			cin >> begin >> end;
			adj[begin].push_back(end);
			adj[end].push_back(begin);
		}
		for (int i = 1; i <= v; i++)
			if (visit[i] == 0)
				visit[i] = 1, ans &= dfs(i);
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}