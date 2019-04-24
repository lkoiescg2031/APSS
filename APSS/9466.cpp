#include <iostream>
#include <vector>
using namespace std;

int testcase,n,ans;
vector<int> adj, visit;

void dfs(int cur) {

	int next = adj[cur];

	if (visit[next] > 0) {
		ans += visit[cur] - visit[next] + 1;
	} else if (visit[next] == 0)
		visit[next] = visit[cur] + 1, dfs(next);

	visit[cur] = -1;
}

int main() {

	cin >> testcase;
	while (testcase-- > 0) {
		cin >> n;
		ans = 0;
		adj = visit = vector<int>(n + 1,0);
		for (int i = 1; i <= n; i++)
			cin >> adj[i];
		for (int i = 1; i <= n; i++)
			if (visit[i] == 0) {
				visit[i] = 1;
				dfs(i);
			}
		cout << n - ans << endl;
	}
	return 0;
}