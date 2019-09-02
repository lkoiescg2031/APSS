#include <cstdio>
bool np[1001];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);	
	for (int i = 2; i <= n; i++) {
		if (np[i]) continue;
		np[i] = true, k--;
		if (k == 0) {printf("%d", i);return 0;}
		for (int j = i*i; j <= n; j += i) {
			if (np[j]) continue; // 중복수 제거
			np[j] = true, k--;
			if (k == 0) { printf("%d", j); return 0;}
		}
	}
	return 0;
}