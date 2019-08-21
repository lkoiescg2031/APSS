#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

int d[100000][5][5], a, n;
int cost[5][5] = {
	{INF,2,2,2,2},//0
	{INF,1,3,4,3},//1
	{INF,3,1,3,4},//2
	{INF,4,3,1,3},//3
	{INF,3,4,3,1}};//4

int main() {

	memset(d, 0x3f, sizeof(d));
	scanf("%d", &a);
	d[n][a][0] = d[n][0][a] = 2;
	while (scanf("%d", &a) && a != 0) {
		n++;
		for (int i = 0; i < 5; i++) {
			if (i == a) continue;
			for (int j = 0; j < 5; j++) {
				if (i == j) continue;
				d[n][a][i] = min(d[n][a][i], d[n - 1][j][i] + cost[j][a]);
				d[n][i][a] = min(d[n][i][a], d[n - 1][i][j] + cost[j][a]);
			}
		}
	}

	int ans = 0x3f3f3f3f;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			ans = min(ans, d[n][i][j]);
	printf("%d", ans);

	return 0;
}