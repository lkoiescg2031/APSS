#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <io.h>
using namespace std;

int main() {
	
	string solve_list,pn;
	getline(cin, solve_list);

	cout << "MISSING FILE LIST\n";

	stringstream ss(solve_list);
	while (ss >> pn) {
		string path = "C:\\Github\\APSS\\BOJ\\" + pn + ".cpp";
		if (_access(path.c_str(), 00) == -1)
			cout << pn << '\n';
	}
	system("pause");
	return 0;
}