#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string n;
int b, ans;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin >> n >> b;
	
	for (auto i : n) {
		ans *= b;
		if (i >= 'A' && i <= 'Z')
			i = i - 'A' + 10;
		else
			i = i - '0';
		ans += i;
	}
	cout << ans;

	return 0;
}