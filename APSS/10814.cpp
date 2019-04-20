#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
using namespace std;
using idlist = vector<pair<int, string>>;
int main() {

	int n;
	idlist arr;
	string ans;

	cin >> n;
	arr = idlist(n);
	for (auto& i : arr) cin >> i.first >> i.second;

	stable_sort(begin(arr), end(arr), [](const pair<int, string>& a,const pair<int, string>& b) {
		return a.first < b.first;
	});

	for (auto i : arr) ans += to_string(i.first) + " " + i.second + "\n";
	cout << ans;

	return 0;
}