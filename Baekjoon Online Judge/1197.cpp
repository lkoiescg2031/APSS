#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;

int v, e;
tuple<int, int, int> adj[100000];
int parent[10001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	int xparent = find(x);
	int yparent = find(y);
	if (xparent == yparent) return;
	parent[x] = yparent;
}

int main() {
	int sour, des, cost;

	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &sour, &des, &cost);
		adj[i] = { cost,sour,des };
	}

	int ans = 0;
	for (int i = 1; i <= v; i++)
		parent[i] = i;

	sort(adj, adj + e);

	for (int i = 0; i < e; i++) {
		tie(cost, sour, des) = adj[i];
		sour = find(sour);
		des = find(des);
		if (sour != des) {
			ans += cost;
			merge(sour, des);
		}
	}
	
	printf("%d", ans);
	return 0;
}