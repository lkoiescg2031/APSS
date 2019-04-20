#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;
using lllist = vector<long long>;

int n,cnt;
ll ans;
lllist arr;

int main() {
	
	cin >> n;
	arr = lllist(n);
	for (auto& i : arr) cin >> i;
	sort(begin(arr), end(arr));

	int pre = 0;
	ans = arr[0];
	cnt = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] != arr[pre]) {
			if (cnt < i - pre){
				ans = arr[pre]; 
				cnt = i - pre;
			}
			pre = i;
		}
	}
	if (cnt < n - pre) 
		ans = arr[pre];
	cout << ans;
	return 0;
}