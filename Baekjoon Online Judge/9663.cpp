#include <cstdio>
int n;
int visit[15], visit_tl[25], visit_tr[25];
int cnt(int i) {
	int ret = 0;
	if (i == n) return 1;
	for (int j = 0; j < n; j++) {
		if ((!visit[j]) && (!visit_tl[i + j]) && (!visit_tr[i - j + n])) {
			visit[j] = visit_tr[i - j + n] = visit_tl[i + j] = true;
			ret += cnt(i + 1);
			visit_tl[i + j] = visit_tr[i - j + n] = visit[j] = false;
		}
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	printf("%d", cnt(0));
	return 0;
}
