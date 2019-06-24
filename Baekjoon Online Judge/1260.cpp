#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 1000

int v, e, s;
vector<int> adj[MAX + 1];
int visit[MAX + 1];

void dfs(int start) {

	visit[start] = 1;
	cout << start << " ";

	for (auto i : adj[start]) {
		if (visit[i] == false)
			dfs(i);
	}
}

void bfs(int start) {
	queue<pair<int, int>> q;
	int cnt = 0;

	q.push({ cnt,start });
	while (!q.empty()) {
		int cur = q.front().second;
		q.pop();
		if (visit[cur] == true)
			continue;
		cout << cur << " ";
		visit[cur] = true;
		cnt++;
		for (auto i : adj[cur]) {
			if (visit[i] == false) {
				q.push({ cnt,i });
			}
		}
	}
}

int main() {

	cin >> v >> e >> s;
	for (int i = 0; i < e; i++) {
		int begin, end;
		cin >> begin >> end;
		adj[begin].push_back(end);
		adj[end].push_back(begin);
	}
	for (int i = 0; i < v; i++)
		sort(begin(adj[i]), end(adj[i]));
	memset(visit, 0, sizeof(visit));
	dfs(s);
	cout << endl;
	memset(visit, 0, sizeof(visit));
	bfs(s);
	return 0;
}