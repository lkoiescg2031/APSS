#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[50];
vector<vector<int>> adj;

int np[2001];

int m;
vector<int> odd;
vector<int> even;

vector<int> pre;
vector<bool> visit;

vector<int> ans;


bool dfs(int i) {
	if (i == -1) return true;
	for (auto j : adj[i])
		if (!visit[j]) {
			visit[j] = true;
			if (dfs(pre[j])) {
				pre[j] = i;
				return true;
			}
		}
	return false;
}

bool flow() {
	int cnt = 0;
	pre = vector<int>(m, -1);
	visit = vector<bool>(m);
	for (int i = 0; i < m; i++) {
		fill(begin(visit), end(visit), false);
		if (dfs(i)) cnt++;
	}
	return cnt == m;
}

int main() {

	for (int i = 2; i <= 2000; i++)
		if (!np[i])
			for (int j = i * i; j <= 2000; j += i)
				np[j] = true;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);

	for (int i = 1; i < n; i++) {
		if (np[a[0] + a[i]]) continue;

		odd = even = vector<int>();
		for (int j = 1; j < n; j++) {
			if (j == i) continue;
			if (a[j] % 2 == 1) odd.push_back(a[j]);
			else even.push_back(a[j]);
		}

		if (odd.size() != even.size()) continue;
		m = odd.size();
		adj = vector<vector<int>>(m);
		for (int j = 0; j < m; j++) for (int k = 0; k < m; k++)
			if (!np[odd[j] + even[k]]) adj[j].push_back(k);

		if (flow()) ans.push_back(a[i]);
	}
	if (ans.empty()) printf("-1");
	else {
		sort(begin(ans), end(ans));
		for (auto i : ans) printf("%d ", i);
	}
	return 0;
}