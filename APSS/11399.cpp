#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
vector<int> p;
int ans;


int main() {

	cin >> n;
	p = vector<int>(n);
	for (int i = 0; i < n; i++) 
		cin >> p[i];
	sort(begin(p), end(p));

	int time = 0;
	for (int i = 0; i < n; i++) {
		ans += time + p[i];
		time += p[i];
	}
	cout << ans;
	return 0;
}