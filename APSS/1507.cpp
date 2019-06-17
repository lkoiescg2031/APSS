#include <cstdio>
using namespace std;

int n;
int adj[20][20];
int del[20][20];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &adj[i][j]);

	for(int k=0;k<n;k++)
		for (int i = 0; i < n; i++) {
			if (k == i) continue;
			for (int j = 0; j < n; j++) {
				if (k == j || i == j) continue;
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					printf("-1");
					return 0;
				}
				else if (adj[i][j] == adj[i][k] + adj[k][j]) {
					del[i][j] = true;
				}
			}

		}

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (!del[i][j]) ans += adj[i][j];
	printf("%d", ans);

	return 0;
}