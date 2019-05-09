#include <cstdio>
using namespace std;

int n, m;
int na[1000000], ma[1000000], ans[2000000];

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)	scanf("%d", &na[i]);
	for (int i = 0; i < m; i++) scanf("%d", &ma[i]);

	int i = 0, j = 0, k = 0;
	while (i < n && j < m)
		if (ma[j] < na[i]) ans[k++] = ma[j++];
		else ans[k++] = na[i++];
	while (i < n) ans[k++] = na[i++];
	while (j < m) ans[k++] = ma[j++];

	for (int i = 0; i < k; i++)
		printf("%d ", ans[i]);
	return 0;
}