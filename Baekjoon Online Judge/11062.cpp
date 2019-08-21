#include<cstdio>
#include<cstring>
#include<algorithm>

int tc, n, card[1001], d[1001];

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);

		card[0] = 0;
		for (int i = 1; i <= n; i++) 
			scanf("%d", &card[i]), card[i] += card[i - 1];

		memset(d + 1, 0, sizeof(int) * n);
		for (int i = 1; i <= n; i++)
			for (int j = n; j >= i; j--) 
				d[j] = card[j] - card[j - i] - std::min(d[j], d[j - 1]);

		printf("%d\n", d[n]);
	}

	return 0;
}