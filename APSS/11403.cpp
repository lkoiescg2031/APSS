#include <cstdio>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;

int n;
int adj[100][100];

int main() {

	scanf("%d", &n);

	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &adj[i][j]);
			if (adj[i][j] == 0)
				adj[i][j] = inf;
		}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (adj[i][j] >= inf) printf("0 ");
			else printf("1 ");
		printf("\n");
	}

	return 0;
}