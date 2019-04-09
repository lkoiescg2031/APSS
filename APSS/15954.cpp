#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, k;
vector<int> list, dp;

int sum;
long double aver, ans;

int main() {
	
	cin >> n >> k;

	list = vector<int>(n);
	dp = vector<int>(n + 1,0);

	for (auto& i : list) cin >> i;

	for (int i = 1; i <= n; i++)
		dp[i] = dp[i - 1] + list[i - 1];

	ans = 1e+100;
	for (int start = 0; start < n; start++) {
		for (int end = start + k; end <= n; end++) {
			sum = dp[end] - dp[start];
			aver = (long double)sum / (end - start);

			long double vunsan = 0;
			for (int i = start; i < end; i++)
				vunsan += (list[i] - aver)*(list[i] - aver);
			vunsan /= (end - start);

			ans = min(ans, vunsan);			
		}
	}
	ans = sqrt(ans);

	cout.setf(ios::fixed);
	cout.precision(11);
	cout << ans << endl;

	return 0;
}
