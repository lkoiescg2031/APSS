#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int time[501],ans[501];
vector<int> adj[501];
int ind[501];

int main() {

	int b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &time[i]);
		while (scanf("%d", &b) && b != -1) {
			adj[b].push_back(i);
			ind[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) 
		if (ind[i] == 0) {
			q.push(i);
			ans[i] = time[i];
		}
	
	for (int i = 0; i < n; i++) {
		int cur = q.front();
		q.pop();
		for (auto next : adj[cur]) {
			ans[next] = max(ans[next], ans[cur] + time[next]);
			ind[next]--;
			if (ind[next] == 0) q.push(next);
		}
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);

	return 0;
}