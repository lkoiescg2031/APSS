#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	set<string> s1,s2;
	string name;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name;
		s1.insert(name);
	}
	for (int i = 0; i < m; i++) {
		cin >> name;
		if (s1.find(name) != end(s1))
			s2.insert(name);
	}
	cout << s2.size() << '\n';
	for (auto i : s2) cout << i << '\n';

	return 0;
}