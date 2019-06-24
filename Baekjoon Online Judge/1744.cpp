#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,ans;
vector<int> arr;

int main() {

	cin >> n;
	arr = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(begin(arr), end(arr));

	int i,j;
	for (i = 0; i < n-1;) {
		if (arr[i + 1] < 1 && arr[i] < 1) {
			ans += (arr[i + 1] * arr[i]);
			i += 2;
		}else break;
	}
	for (j = n - 1; j > i;) {
		if (arr[j] > 1 && arr[j - 1] > 1) {
			ans += (arr[j] * arr[j - 1]);
			j -= 2;
		}else break;
	}
	while (i <= j) ans += arr[i++];
	cout << ans;
	return 0;
}