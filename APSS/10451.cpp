#include <iostream>
#include <vector>
using namespace std;

int testcase, v, ans;
vector<int> adj, visit;

void dfs(int cur) {
	int next = adj[cur];
	visit[cur] = true;
	if (visit[next]) ans++;
	else dfs(next);
}

int main() {
	cin >> testcase;
	while (testcase-- > 0) {
		cin >> v;
		ans = 0;
		adj = visit = vector<int>(v + 1);
		for (int i = 1; i <= v; i++) cin >> adj[i];
		for (int i = 1; i <= v; i++)
			if (!visit[i])
				dfs(i);
		cout << ans << endl;
	}
	return 0;
}