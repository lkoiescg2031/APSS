#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 4000;

int a[MAX], b[MAX], c[MAX], d[MAX];
int subsum1[MAX * MAX], subsum2[MAX * MAX];

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			subsum1[i * n + j] = a[i] + b[j],
			subsum2[i * n + j] = c[i] + d[j];

	int last = n * n;
	sort(subsum2, subsum2 + last);

	long long ans = 0;
	for (int i = 0; i < last; i++) {
		auto j = equal_range(subsum2, subsum2 + last, -subsum1[i]);
		ans += j.second - j.first;
	}
	printf("%lld", ans);

	return 0;
}