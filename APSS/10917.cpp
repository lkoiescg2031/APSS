#include <cstdio>
#include <algorithm>
using namespace std;

int n, adj[10][10], order[10], ans = 0x3f3f3f3f;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &adj[i][j]);
		order[i] = i;
	}

	do {
		int sum = 0;
		for (int i = 0, pre = n - 1; i < n; pre = i++) {
			int w = adj[order[pre]][order[i]];
			if ( w == 0) {
				sum = 0x3f3f3f3f;
				break;
			}
			sum += w;
		}
		ans = min(ans, sum);
	} while (next_permutation(order, order + n));
	printf("%d", ans);
	return 0;
}