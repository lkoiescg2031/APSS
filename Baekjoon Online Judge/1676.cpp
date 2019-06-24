#include <iostream>
using namespace std;

int n, ans;

int main() {
	cin >> n;
	for (int i = 5; i <= n; i *= 5)
		ans += n / i;
	cout << ans;
	return 0;
}