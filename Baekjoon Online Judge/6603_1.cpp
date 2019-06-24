#include <cstdio>

int k, a[13], choice[13];

void print(int i,int s) {
	if (s == 6) {
		for (int i = 0; i < k; i++)
			if (choice[i]) printf("%d ", a[i]);
		printf("\n");
		return;
	}
	if (i == k) return;
	choice[i] = true;
	print(i + 1, s + 1);
	choice[i] = false;
	print(i + 1, s);
}

int main() {
	
	while (scanf("%d", &k) && k != 0) {
		for (int i = 0; i < k; i++) scanf("%d", &a[i]);
		print(0,0);
		printf("\n");
	}
	return 0;
}