#include <cstdio>
#include <vector>
#include <tuple>
using namespace std;
using iiiint = tuple<int, int, int, int>;

int n;
iiiint arr[50];
vector<int> adj[50];
vector<int> pre;
vector<bool> visit;

bool operator> (const iiiint& a, const iiiint& b) {
	int a1, a2, a3, a4;
	int b1, b2, b3, b4;
	tie(a1, a2, a3, a4) = a;
	tie(b1, b2, b3, b4) = b;
	if (a1 == b1 && a2 == b2 && a3 == b3) return a4 < b4;
	return a1 >= b1 && a2 >= b2 && a3 >= b3;
}
int dfs(int i) {
	if (i == -1) return true;
	for (auto j : adj[i]) {
		if (visit[j]) continue;
		visit[j] = true;
		if (dfs(pre[j])) {
			pre[j] = i;
			return true;
		}
	}
	return false;
}

int flow() {
	int ret = 0;

	pre = vector<int>(n, -1);
	visit = vector<bool>(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			fill(begin(visit), end(visit), false);
			if (dfs(i)) ret++;
		}
	}
	return ret;
}

int main() {

	int a, b, c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr[i] = { a,b,c,i };
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (i == j) continue;
		if (arr[i] > arr[j]) adj[i].push_back(j);
	}

	printf("%d", n - flow());

	return 0;
}