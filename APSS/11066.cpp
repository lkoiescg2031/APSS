#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int t;
int k;
vector<int> arr,subsum;
vector<vector<long long>> dp;

long long go(int b, int e) {
	if (dp[b][e] != 0x3f3f3f3f) return dp[b][e];
	else if (b == e) return dp[b][e] = 0;
	else if (b + 1 == e) return dp[b][e] = arr[b] + arr[e];

	for (int i = b; i < e; i++) 
		dp[b][e] = min(dp[b][e], go(b, i) + go(i + 1, e));
	dp[b][e] += subsum[e] - subsum[b] + arr[b];
	return dp[b][e];
}

int main() {

	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &k);
		subsum = arr = vector<int>(k);
		dp = vector<vector<long long>>(k, vector<long long>(k, 0x3f3f3f3f));
		for (auto& i : arr) scanf("%d", &i);
		subsum[0] = arr[0];
		for (int i = 1; i < k; i++) subsum[i] = subsum[i - 1] + arr[i];
		printf("%d\n", go(0, k - 1));
	}
	return 0;
}