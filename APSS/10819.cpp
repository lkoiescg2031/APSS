#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[8], order[8], s, ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), order[i] = i;

	do {
		s = 0;
		for (int i = 1; i < n; i++)
			s += abs(a[order[i - 1]] - a[order[i]]);
		ans = max(ans, s);
	} while (next_permutation(order, order + n));
	
	printf("%d", ans);
	return 0;
}