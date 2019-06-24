#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct s {
	string n;
	int k, e, m;
};
using slist = vector<s>;
int main() {

	int n;
	slist arr;
	string ans;

	cin >> n;
	arr = slist(n);
	for (auto&i : arr)
		cin >> i.n >> i.k >> i.e >> i.m;
	sort(begin(arr), end(arr), [](const s& a,const s& b) {
		if (a.k != b.k)
			return a.k > b.k;
		else if (a.e != b.e)
			return a.e < b.e;
		else if (a.m != b.m)
			return a.m > b.m;
		return a.n < b.n;
	});

	for (auto i : arr)
		ans += i.n  + "\n";
	cout << ans;
	return 0;
}