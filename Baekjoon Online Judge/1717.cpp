#include <cstdio>
using namespace std;
int n, m, a[1000001];
int find(int x) {
	if (x == a[x]) return x;
	return a[x] = find(a[x]);
}
void merge(int x, int y) {
	int px = find(x);
	int py = find(y);
	a[px] = py;
}
int main (){

	scanf("%d %d", &n, &m);	
	for (int i = 0; i <= n; i++) a[i] = i;
	while (m-- > 0) {
		int op, x, y;
		scanf("%d %d %d", &op, &x, &y);
		if (op) 
			if (find(x) == find(y)) printf("YES\n");
			else printf("NO\n");
		else merge(x, y);
	}
	return 0;
}