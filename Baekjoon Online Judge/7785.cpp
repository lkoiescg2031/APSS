#include <iostream>
#include <string>
#include <set>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string name, state;
	set<string,greater<string>> s;
	cin >> n;
	while (n-- > 0) {
		cin >> name >> state;
		if (state[0] == 'e') s.insert(name);
		else s.erase(name);
	}
	for (auto name : s) cout << name << '\n';
	return 0;
}