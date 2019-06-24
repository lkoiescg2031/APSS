#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define FOR(i,n) for(int (i) = 0; (i) < (n);++(i))

int main() {

	ios_base::sync_with_stdio(false);

	int ans = 0;

	string str;
	stack<int> st;

	cin >> str;

	FOR(i, str.size()) {
		if (str[i] == '(') {//막대기 가 생김
			st.push(i);
		} else {
			int top = st.top();
			st.pop();
			ans += top + 1 == i ? st.size() : 1;
		}
	}
	cout << ans << endl;

	return 0;
}