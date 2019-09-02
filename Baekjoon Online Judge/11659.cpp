#include <cstdio>

int d[100001];
int main() {

	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &d[i]);
		d[i] += d[i - 1];
	}
	int i, j;
	while (M--) {
		scanf("%d %d", &i, &j);
		printf("%d\n", d[j] - d[i - 1]);
	}
	return 0;
}