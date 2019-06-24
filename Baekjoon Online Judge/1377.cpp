#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

#define MAX 500000

int n, ans;
pair<int,int> a[MAX];

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i].first, a[i].second = i;
	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		ans = max(ans, a[i].second - i);
	}
	cout << ans + 1;
	return 0;
}