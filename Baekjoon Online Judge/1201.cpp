#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;
vector<int> arr;
int main() {
	cin >> n >> m >> k;
	if (m + k - 1 > n || n > m * k) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i++) arr.push_back(i);
	
	vector<int> g;
	g.push_back(0);
	g.push_back(k);
	n -= k;
	m -= 1;
	//divide by zero
	int gs = m == 0 ? 1 : n / m;
	int r = m == 0 ? 0 : n % m;
	for (int i = 0; i < m; i++) g.push_back(g.back() + gs + (r-- > 0));
	for (int i = 1; i < g.size(); i++) reverse(begin(arr) + g[i - 1], begin(arr) + g[i]);
	for (auto i : arr) cout << i << ' ';
	return 0;
}