#include <iostream>
using namespace std;
int ans, n, m, k;
int main() {
	cin >> n >> m >> k;
	while (n > 1 && m > 0 && m + n > k + 2) n -= 2, m -= 1, ans++;
	cout << ans;
	return 0;
}