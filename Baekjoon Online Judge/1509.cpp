#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char str[2502];
int is_pal[2501][2501];
int dp[2501];

int main() {

	str[0] = ' ';
	scanf("%s", str + 1);
	n = strlen(str) - 1;

	for (int i = 1; i <= n; i++) {
		is_pal[i][i] = 1;
		is_pal[i][i + 1] = str[i] == str[i + 1];
	}
	for (int k = 3; k <= n; k++)
		for (int i = 0; i + k - 1 <= n; i++) {
			int j = i + k - 1;
			is_pal[i][j] = is_pal[i + 1][j - 1] && str[i] == str[j];
		}

	memset(dp, 0x3f3f3f3f, sizeof(dp));
	dp[0] = 0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			if (is_pal[j][i]) {
				dp[i] = min(dp[i], dp[j - 1] + 1);
			}
	printf("%d", dp[n]);
	return 0;
}