#include <iostream>
#include <string>
using namespace std;

#define MAX 5000
#define MOD 1000000

string s;
int dp[MAX + 1];

int main() {

	cin >> s;
	
	dp[0] = 1;
	dp[1] = s[0] != '0';
	for (int i = 2; i <= s.size(); i++) {
		int n1 = s[i - 1] - '0';
		dp[i] += n1 > 0 && n1 <= 9 ? dp[i - 1] : 0;

		int n2 = (s[i - 2] - '0') * 10 + n1;
		dp[i] += n2 >= 10 && n2 <= 26 ? dp[i - 2] : 0;	
		dp[i] %= MOD;
	}
	cout << dp[s.size()];
	return 0;
}