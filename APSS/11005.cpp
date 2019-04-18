#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, B;
vector<int> ans;

int main() {

	cin >> N >> B;

	while (N > 0) {
		ans.push_back(N%B);
		N /= B;
	}

	reverse(begin(ans), end(ans));

	for (auto i : ans)
		if (i >= 10)
			cout << char('A' + i - 10);
		else
			cout << i;

	return 0;
}