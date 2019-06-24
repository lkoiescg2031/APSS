#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[100111];
int dep[100111], from[100111];

int main() {

	int a, b;

	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	queue<int> q;
	q.push(1);
	from[1] = -1;
	while (!q.empty()) {
		a = q.front();
		q.pop();
		for(auto i : adj[a])
			if (from[i] == 0) {
				dep[i] = dep[a] + 1;
				from[i] = a;
				q.push(i);
			}		
	}

	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		if (dep[a] < dep[b]) swap(a, b);
		while (dep[a] != dep[b]) a = from[a];
		while (a != b) a = from[a], b = from[b];
		printf("%d\n", a);
	}

	return 0;
}
