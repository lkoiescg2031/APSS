#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, d[1000][1000];

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		getc(stdin);
		for (int j = 0; j < m; j++)
			d[i][j] = getc(stdin) - '0';
	}

	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			d[i][j] = d[i][j] ? min({ d[i - 1][j],d[i][j - 1],d[i - 1][j - 1] }) + 1 : 0;

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans = max(ans, d[i][j]);
	printf("%d", ans * ans);
	return 0;
}