#include <iostream>
#include <math.h>
using namespace std;

int a, p, d[236197];

int main() {

	cin >> a >> p;

	d[a] = 1;
	while (1) {
		int next = 0;
		for (int i = a; i > 0; i /= 10)
			next += pow(i % 10, p);
		if (d[next] != 0) {
			cout << d[next] -1;
			break;
		}
		d[next] = d[a] + 1;
		a = next;
	}

	return 0;
}