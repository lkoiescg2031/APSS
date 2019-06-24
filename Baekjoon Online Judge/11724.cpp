#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define MAX 1000

int v, e, ans;
vector<int> adj[MAX + 1];
int visit[MAX + 1];

void dfs(int v) {
	visit[v] = true;
	for (auto i : adj[v])
		if (!visit[i])
			dfs(i);
}
int main() {

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int begin, end;
		cin >> begin >> end;
		adj[begin].push_back(end);
		adj[end].push_back(begin);
	}

	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= v; i++)
		if (visit[i] == false) 
			ans++,dfs(i);
	cout << ans;
	return 0;
}