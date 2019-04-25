#include <iostream>
#include <string>
using namespace std;

int n;
char t['Z' + 1][2];

void preorder(char r) {
	if (r == '.')
		return;
	cout << r;
	preorder(t[r][0]);
	preorder(t[r][1]);
}

void inorder(char r) {
	if (r == '.')
		return;
	inorder(t[r][0]);
	cout << r;
	inorder(t[r][1]);
}

void postorder(char r) {
	if (r == '.')
		return;
	postorder(t[r][0]);
	postorder(t[r][1]);
	cout << r;
}
int main() {

	char c;
	cin >> n;
	while (n-- > 0) {
		cin >> c;
		cin >> t[c][0] >> t[c][1];
	}
	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	return 0;
}