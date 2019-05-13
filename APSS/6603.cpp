#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[13], choice[13];

int main() {
	while (scanf("%d", &n) && n != 0) {

		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]), choice[i] = 0;
		for (int i = 0; i < 6 ;i++) choice[i] = 1;

		do {
			for (int i = 0; i < n; i++)
				if (choice[i])
					printf("%d ", a[i]);
			printf("\n");
		} while (prev_permutation(choice, choice + n));
		printf("\n");
	}
	return 0;
}