#include <cstdio>
using namespace std;

int n;
int tree[2][100000];
int find[100001];

void sol(int from, int to, int post) {
	if (from <= to) {
		int in = find[tree[1][post]];
		int split = to - in;
		printf("%d ", tree[1][post]);
		sol(from, in - 1, post - split - 1);
		sol(in + 1, to, post - 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &tree[i][j]);
	for (int i = 0; i < n; i++)
		find[tree[0][i]] = i;
	sol(0, n - 1, n - 1);
	return 0;
}