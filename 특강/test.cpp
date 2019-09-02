#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

#define MOD 1000000007

ll query(vector<ll>& tree, int node, int begin, int end, int i, int j) {
	if (j < begin || end < i) return 0;
	else if (i <= begin && end <= j) return tree[node];
	return (query(tree, node * 2, begin, (begin + end) / 2, i, j)
		+ query(tree, node * 2 + 1, (begin + end) / 2 + 1, end, i, j)) % MOD;
}

void update(vector<ll> tree, int node, int begin, int end, int i, ll diff) {
	if (i < end || begin < i) return;
	tree[node] = (tree[node] + diff) % MOD;
	if (begin != end) {
		update(tree, node * 2, begin, (begin + end) / 2, i, diff);
		update(tree, node * 2 + 1, (begin + end) / 2 + 1, end, i, diff);
	}
}

#define MAX 100000000

int main() {

	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		int n;
		scanf("%d", &n);
		vector<pair<int, int>> a(n);
		vector<bool> is_last(n), is_first(n);
		
		int min = MAX;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i].first);
			a[i].second = -i;
			if (min >= a[i].first) {
				min = a[i].first;
				is_first[i] = true;
			}
		}
		int max = -MAX;
		for (int i = n - 1; i >= 0; i--) 
			if (max <= a[i].first) {
				max = a[i].first;
				is_last[i] = true;
			}

		ll ans = 0;
		sort(begin(a), end(a));
		vector<ll> tree(4 * n);
		for (int i = 0; i < n; i++) {
			int qry = -a[i].second;
			ll qry_ans = query(tree, 1, 0, n - 1, 0, qry - 1);
			if (is_first[qry]) qry_ans = 1;
			if (is_last[qry]) ans += qry_ans;
			update(tree, 1, 0, n - 1, qry, qry_ans);
		}
		printf("#%d %lld\n", tc, ans);
	}
	return 0;
}