#include<cstdio>
int n;
int map[64][64];

void sol(int x, int y, int s) {
	bool flag = true;
	int bit = map[x][y];
	for (int i = 0; i < s && flag; i++)
		for (int j = 0; j < s && flag; j++)
			if (map[x + i][y + j] != bit)
				flag = false;
	if (flag) {
		printf("%d", bit);
		return;
	}
	printf("(");
	s /= 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			sol(x + i * s, y + j * s, s);
	printf(")");
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]);
	sol(0, 0, n);
	return 0;
}