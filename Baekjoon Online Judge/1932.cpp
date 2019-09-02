#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

#define K_MAX (int)1e9+1
#define MAX 200

int a, z, k;
int d[MAX + 1][MAX + 1];

int main() {

	scanf("%d %d %d", &a, &z, &k);
	for (int i = 1; i <= a + z; i++) {
		d[i][0] = d[i][i] = 1;
		for (int j = 1; j < i; j++) d[i][j] = min(d[i - 1][j - 1] + d[i - 1][j], K_MAX);
	}

	if (d[a + z][a] < k) { printf("-1"); return 0; }

	string ans = "";
	int len = a + z;
	while (len--) {
		if (!a) ans += 'z', z--;
		else if (!z) ans += 'a', a--;
		else if (k <= d[a - 1 + z][a - 1]) ans += 'a', a--;
		else k -= d[a + z - 1][a - 1], ans += 'z', z--;
	}
	printf("%s", ans.c_str());
	return 0;
}