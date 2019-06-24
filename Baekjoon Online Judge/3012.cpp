#include <cstdio>
#include <cstring>

const char open[] = "([{";
const char close[] = ")]}";
const int mod = 100000;

int n;
char str[201];
long long dp[201][201];

long long go(int i, int j){
	if (i > j) return 1;

	long long& ret = dp[i][j];	
	if (ret != -1) return ret;

	ret = 0;
	for(int k =i+1;k<=j;k++)
		for(int l =0;l<3;l++)
			if ((str[i] == open[l] || str[i] == '?') &&
				(str[k] == close[l] || str[k] == '?')) {
				ret += go(i + 1, k - 1) * go(k + 1, j);
				if (ret >= mod)
					ret = mod + ret % mod;
			}
	return ret;
}

int main() {

	scanf("%d %s", &n, str);
	memset(dp, -1, sizeof(dp));
	long long ans = go(0, n - 1);
	if (ans >= mod) printf("%05lld", ans % mod); //출력 유의
	else printf("%lld", ans);
	return 0;
}