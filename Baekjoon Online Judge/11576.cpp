#include <iostream>
#include <string>
using namespace std;

int base_a, base_b;
int i, base10;

void ans(int n,int b) {
	int r = n % b;
	int q = n / b;

	if(q>0)	ans(q, b);
	cout << r << " ";
}

int main() {
	cin >> base_a >> base_b >> i;

	while (i-- > 0) {
		int k;
		cin >> k;
		base10 *= base_a;
		base10 += k;
	}
	
	ans(base10, base_b);

	return 0;
}