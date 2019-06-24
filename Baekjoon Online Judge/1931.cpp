#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, ans = 1;
vector<pair<int,int>> sch;

int main() {

	cin >> n;
	sch = vector<pair<int, int>>(n);
	for (int i = 0; i < n; i++)
		cin >> sch[i].second >> sch[i].first;

	sort(begin(sch) , end(sch));

	int end = sch[0].first;
	for (int i = 1; i < n; i++) {
		if (sch[i].second >= end) {
			ans++;
			end = sch[i].first;
		}
	}
	cout << ans;
	return 0;
}