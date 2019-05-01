#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int n, k,m, ans;

int main() {

	cin >> n >> k;

	while (n-- > 0) {
		cin >> m;
		s.push(m);
	}

	while (!s.empty() && k > 0) {
		int p = s.top(); s.pop();
		
		ans += k / p;
		k = k % p;
	}

	cout << ans;

	return 0;
}