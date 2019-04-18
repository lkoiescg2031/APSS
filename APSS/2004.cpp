#include <iostream>
#include <algorithm>
using namespace std;

int n, m, t, f;

int cal(int a, int b) {
	int ret = 0;
	for (long long i = b; i <= a; i *= b)
		ret += a / i;
	return ret;
}

int main() {

	cin >> n >> m;

	t = cal(n, 2) - cal(m, 2) - cal(n - m, 2);
	f = cal(n, 5) - cal(m, 5) - cal(n - m, 5);	
	cout <<min(t,f);

	return 0;
}