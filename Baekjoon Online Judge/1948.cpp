#include <cstdio>
#include <tuple>
#include <queue>
using namespace std;

int v, e;;
vector<pair<int, int>> adj[10001], rev_adj[10001];
int ind[10001],rev_ind[10001];
int dist[10001];
int is_path[10001];

int main() {

	int sour,des,w;
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &sour, &des, &w);
		adj[sour].push_back({ des,w });
		rev_adj[des].push_back({sour,w});
		ind[des]++;
		rev_ind[sour]++;
	}
	scanf("%d %d", &sour, &des);

	queue<int> q;
	q.push(sour);

	int cur, next, weight;
	for (int i = 0; i < v; i++) {
		cur = q.front();
		q.pop();
		for (auto i : adj[cur]) {
			tie(next, weight) = i;
			ind[next]--;
			dist[next] = max(dist[next], dist[cur] + weight);
			if (ind[next] == 0) q.push(next);
		}
	}

	int road = 0;
	q.push(des);
	is_path[des] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto i : rev_adj[cur]) {
			tie(next, weight) = i;
			if (is_path[cur] && dist[cur] - dist[next] == weight) 
				is_path[next] = true, road++;
			rev_ind[next]--;
			if (rev_ind[next] == 0) q.push(next);
		}
	}

	printf("%d\n%d", dist[des], road);
	return 0;
}