#include <cstdio>
#include <stack>
#include <tuple>
using namespace std;

int n, a[500000];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	stack<pair<int, int>> s;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		while (!s.empty() && a[s.top().first] <= a[i]) {
			ans += s.top().second;
			if (a[s.top().first] == a[i]) break;
			s.pop();
		}
		if (!s.empty() && a[s.top().first] != a[i]) ans++;
		if (!s.empty() && a[s.top().first] == a[i]) s.top().second++;
		else s.push({ i,1 });
	}
	printf("%lld", ans);

	return 0;
}