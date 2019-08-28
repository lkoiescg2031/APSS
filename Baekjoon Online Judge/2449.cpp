#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int a[200],d[200][200];

int go(int i, int j) {
	if (d[i][j] != -1) return d[i][j];
	int& ret = d[i][j] = 0x3f3f3f3f;
	if (i == j) return ret = 0;
	else if (i + 1 == j) return ret = !(a[i] == a[j]);
	for (int k = i; k < j; k++) 
		ret = min(ret, go(i, k) + go(k + 1, j) + (a[i] == a[k+1] ? 0 : 1));
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
	memset(d, 0xff, sizeof(d));
	printf("%d", go(0, n - 1));
	return 0;
}