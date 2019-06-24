#include <cstdio>

void hanoi(int size, int from, int to) {
	if (size == 0) return;
	hanoi(size - 1, from, 6 - from - to);
	printf("%d %d \n", from, to);
	hanoi(size - 1, 6 - from - to, to);
}

int main() {
	int k;
	scanf("%d", &k);
	printf("%d\n", (1 << k) - 1);
	hanoi(k, 1, 3);
	return 0;
}