#include <cstdio>
int n, ans[46];

int main() {
	ans[1] = ans[2] = 1;
	for (int i = 3; i <= 45; i++)
		ans[i] = ans[i - 1] + ans[i - 2];
	
	scanf("%d", &n);
	printf("%d", ans[n]);
	return 0;
}