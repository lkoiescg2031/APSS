#include <cstdio>

int main() {
	int a, b, n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}