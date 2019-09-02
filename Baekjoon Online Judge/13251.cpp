#include <cstdio>
#include <vector>
using namespace std;

int n, m, k;
vector<int> a;

int main() {
	
	scanf("%d", &m);
	a.resize(m);
	for (auto& i : a) scanf("%d", &i), n += i;
	scanf("%d", &k);

	double ans = 0;
	for (int i = 0; i < m; i++) {
		if (a[i] < k) continue;

		double t = 1.0;
		for (int j = 0; j < k; j++) {
			int a0 = a[i] - j;
			int n0 = n - j;
			t *= (double)a0 / n0;
		}
		ans += t;
	}
	printf("%0.10lf", ans);
	return 0;
}