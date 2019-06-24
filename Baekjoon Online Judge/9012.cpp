#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int testcase;
	string str;
	char c;

	cin >> testcase;
	cin.ignore();//cin 버퍼 비우기
	while (testcase--) {
		getline(cin, str);
		stringstream ss(str);
		int stack = 0;
		while (ss >> c) {
			stack += c == '(' ? 1:-1;
			if (stack < 0)
				break;
		}
		if (stack) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}