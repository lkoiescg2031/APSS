#include <cstdio>
#include <algorithm>
using namespace std;

int a,n, mi = 1000001, ma = -1000001;

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		mi = min(mi, a);
		ma = max(ma, a);
	}
	printf("%d %d", mi, ma);
	return 0;
}