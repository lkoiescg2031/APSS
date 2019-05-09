#include <cstdio>
#include <cmath>
int n;
char map[6561][6561];

void sol(int x, int y, int s,char c) {
	if (c == ' ') {
		for (int i = 0; i < s; i++)
			for (int j = 0; j < s; j++)
				map[x + i][y + j] = c;
	} else if (s == 1) {
		map[x][y] = '*';
	} else {
		s /= 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (j * i != 1)
					sol(x + i * s, y + j * s, s, '*');
				else
					sol(x + i * s, y + j * s, s, ' ');
	}
}

int main() {

	scanf("%d", &n);
	sol(0, 0, n, '*');
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
	return 0;
}