#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<pair<int,int>> a;
set<int> cnt;

int main() {

	scanf("%d %d", &N, &K);
	a.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i].first);
		a[i].second = 1;
		while (a[i].second <= a[i].first) a[i].second *= 10;
	}
	sort(begin(a),end(a));
	do{
		int ans = a[0].first;
		for (int i = 1; i < K; i++) {
			ans *= a[i].second;
			ans += a[i].first;
		}
		cnt.insert(ans);
	} while (next_permutation(begin(a), end(a)));
	printf("%d", cnt.size());
	return 0;
}	