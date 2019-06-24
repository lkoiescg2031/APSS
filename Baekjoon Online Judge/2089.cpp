#include <iostream>
using namespace std;
void m_bin(int n) {
	int q,r;
	if (n < 0) {
		n *= -1;
		r = n % 2;
		q = n / 2 + r;
		m_bin(q);
		cout << r;
	}
	else {
		r = n % 2;
		q = -(n / 2);
		if (q != 0 && q != 1)
			m_bin(q);
		cout << r;
	}
}
int main() {

	int n;

	cin >> n;
	m_bin(n);
	
	return 0;
}