#include <cstdio>

int N, H,t;
int h[2][500001];

int main() {

	scanf("%d %d", &N, &H);
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		if (i & 1) h[i & 1][H + 1 - t]++;
		else h[i & 1][t]++;
	}
	for (int i = H; i > 0; i--) h[0][i - 1] += h[0][i]; 
	for (int i = 0; i < H; i++) h[1][i + 1] += h[1][i];

	int min = 0x3f3f3f3f, cnt = 0;
	for (int i = 0; i < H; i++) 
		if (min > h[0][i] + h[1][i]) {
			min = h[0][i] + h[1][i];
			cnt = 1;
		}
		else if (min == h[0][i] + h[1][i]) cnt++;
	
	printf("%d %d", min, cnt);
	return 0;
}