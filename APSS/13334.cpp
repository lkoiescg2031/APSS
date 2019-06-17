#include <cstdio>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n, l;
pair<int, int> a[200000];
int line[100000];

int main() {

	int u, v;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &u, &v);
		if (u > v)swap(u, v);
		a[i] = { u, i };
		a[n+i] = { v, i };
	}
	scanf("%d", &l);
	
	sort(a, a + 2 * n);

	queue<pair<int, int>> q;
	int cnt=0,ans = 0;
	for (int i = 0; i < 2 * n; i++) {
		while (!q.empty() && q.front().first < a[i].first - l) {	
			if (line[q.front().second]-- == 2) cnt--;
			q.pop();
		}
		q.push(a[i]);
		if (++line[a[i].second] == 2) cnt++;
		ans = max(ans, cnt);
	}
	printf("%d", ans);

	return 0;
}