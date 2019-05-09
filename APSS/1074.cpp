#include <cstdio>

int n, x, y;
bool is_in(int i, int j, int s) {
	return i <= x && x < i + s && j <= y && y < j + s;
}
int sol(int x, int y, int s) {
	int ret = 0;
	if (s == 1)	return 1;
	s /= 2;
	for(int i=0;i<2;i++)
		for (int j = 0; j < 2; j++) {
			if (is_in(x + i * s, y + j * s, s)) {
				return ret + sol(x + i * s, y + j * s, s);
			}
			ret += s * s;
		}
}
int main() {
	scanf("%d %d %d", &n, &x, &y);
	printf("%d", sol(0, 0, 1 << n) - 1);
	return 0;
}