#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, m, number;
int main() {

	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &a[i]);

	sort(a.begin(), a.end());

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &number);
		auto p = equal_range(a.begin(), a.end(), number);
		printf("%d ", p.second - p.first);

		//auto l = lower_bound(a.begin(), a.end(), number);
		//auto r = upper_bound(a.begin(), a.end(), number);
		//printf("%d ", r - l);

	}
	return 0;
}