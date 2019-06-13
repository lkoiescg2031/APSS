#include <cstdio>
#include <vector>
using namespace std;

long long n, k, m;
int d[2001][2001];

int main() {

	scanf("%lld %lld %lld", &n, &k, &m);

	for (int i = 0; i <= m; i++) {
		d[i][0] = d[i][i] = 1;
		for (int j = 1; j < i; j++) {
			d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
			d[i][j] %= m;
		}
	}

	vector<int> a, b;
	while (n > 0 || k > 0) {
		a.push_back(n % m);
		b.push_back(k % m);
		n /= m;
		k /= m;
	}
	long long ans = 1;
	for (int i = 0; i < a.size(); i++) {
		ans *= d[a[i]][b[i]];
		ans %= m;
	}

	printf("%lld", ans);

	return 0;
}