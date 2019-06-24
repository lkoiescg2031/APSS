#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;


int main() {

	ios_base::sync_with_stdio(false);

	int cmd_num;
	char cmd,ch;
	string str;
	stack<char> left, right;

	cin >> str >> cmd_num;
	stringstream ss(str);
	while (ss >> ch) left.push(ch);
	
	while (cmd_num--) {
		cin >> cmd;
		switch (cmd) {
		case 'P':
			cin >> ch;
			left.push(ch);
			break;
		case 'L':
			if (left.empty()) break;
			right.push(left.top());
			left.pop();
			break;
		case 'D':
			if (right.empty()) break;
			left.push(right.top());
			right.pop();
			break;
		case 'B':
			if (left.empty()) break;
			left.pop();
			break;
		}
	}
	
	while (!left.empty()) right.push(left.top()), left.pop();

	while (!right.empty()) {
		ch = right.top();
		cout << ch;
		right.pop();
	}

	return 0;
}