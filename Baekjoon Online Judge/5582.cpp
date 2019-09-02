#include <iostream>
#include <string>
#include <tuple>
#include <stack>
#include <algorithm>
using namespace std;

string a, b;
int d[4001][4001];
bool p[4001][4001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	a = 'a' + a; b = 'b' + b;
	int ans = 0;
	int alen = a.size(), blen = b.size();
	for (int i = 1; i < alen; i++) for (int j = 1; j < blen; j++) {
		if (a[i] == b[j] && d[i - 1][j - 1] + 1 > d[i][j]) {
			p[i][j] = d[i][j] = 1;
			if (p[i - 1][j - 1]) d[i][j] += d[i - 1][j - 1];
			ans = max(ans, d[i][j]);
		}
	}
	printf("%d", ans);
	return 0;
}