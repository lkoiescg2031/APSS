#include<iostream>
#include<string>
using namespace std;

string n, ans;

int main() {

	cin >> n;
	
	int cnt = 3 - (n.size() % 3);
	cnt %= 3;
	for (int i = 0; i < n.size();) {
		int temp = 0;
		while (cnt < 3) {
			temp *= 2;
			temp += n[i] == '1';
			i++;
			cnt++;
		}
		ans += char('0' + temp);
		cnt = 0;
	}
	cout << ans;
	return 0;
}