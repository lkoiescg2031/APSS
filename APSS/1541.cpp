#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int n, ans;
bool flag;

int main() {
	string str;
	cin >> str;
	stringstream ss(str);
	while (ss >> n) {
		if (!flag) {
			ans += n;
			flag = n < 0;
			continue;
		}
		if (n < 0) ans += n;
		else ans -= n;
	}
	cout << ans;
	return 0;
}