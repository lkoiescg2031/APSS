#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 1000000
int n;
int memo[MAX + 1];
vector<int> prime;
string ans;
int main() {

	ios_base::sync_with_stdio(false);

	for (long long i = 2; i <= MAX; i++) {
		if (memo[i] == 0) {
			prime.push_back(i);
			for (long long j = i * i; j <= MAX; j += i)
				memo[j] = 1;
		}
	}
	for (cin >> n; n != 0; cin >> n) 
		for (int i = 2; i < n ; i++) 
			if (memo[i] == 0 && memo[n - i] == 0) {
				ans += to_string(n) + " = " + to_string(i) + " + " + to_string(n - i) + "\n";
				break;
			}

	cout << ans;
	return 0;
}
