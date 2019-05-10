#include <cstdio>

int esm[19][29][20];

int main() {
	for (int i = 1,e=1,s=1,m=1; i <= 7980;i++) {
		esm[e][s][m] = i;
		e = (e + 1) == 16 ? 1 : (e + 1);
		s = (s + 1) == 29 ? 1 : (s + 1);
		m = (m + 1) == 20 ? 1 : (m + 1);
	}

	int e, s, m;
	scanf("%d %d %d", &e, &s, &m);
	printf("%d", esm[e][s][m]);
	return 0;
}