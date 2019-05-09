#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int arr[10000];
long long l, r = 2000000000LL * 30LL;
int ans;

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &arr[i]);

	while (l <= r) {
		long long mid = (l + r) / 2;
		long long b, e = m + 1;
		for (int i = 0; i < m; i++)
			e += mid / arr[i];
		b = e;
		for (int i = 0; i < m; i++)
			b -= (mid % arr[i] == 0);
		if (n < b)
			r = mid - 1;
		else if (n >= e)
			l = mid + 1;
		else {
			for(int i=0;i<m;i++)
				if (mid % arr[i] == 0) {
					if (b == n) {
						ans = i;
						break;
					}
					b++;
				}
			break;
		}
	}

	printf("%d", ans + 1);

	return 0;
}