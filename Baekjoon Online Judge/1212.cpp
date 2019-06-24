#include <iostream>
#include <string>
using namespace std;

string n;
string E2B[] = {"000","001","010","011","100","101","110","111" };
string E2B_trim[] = { "","1","10","11","100","101","110","111" };

int main() {
	
	cin >> n;

	if(n[0]=='0'){
		cout << '0';
		return 0;
	}

	cout << E2B_trim[n[0] - '0'];
	for (int i = 1; i < n.size(); i++)
		cout << E2B[n[i] - '0'];

	return 0;
}