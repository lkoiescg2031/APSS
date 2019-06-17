#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 4000000;

int np[MAX + 1], n;
vector<int> prime;

int main() {

	scanf("%d", &n);

	for(long long i=2;i<=n; i++)
		if (!np[i]) {
			prime.push_back(i);
			for (long long j = i * i; j <= n; j += i)
				np[j] = true;
		}

	int l = 0, r = 0;
	int sum = prime.empty() ? 0 : prime[0], ans = 0;
	while (l <= r && r < prime.size()) {
		if (sum <= n) {
			if (sum == n) ans++;
			r++;
			if (r < prime.size()) sum += prime[r];
		}else sum -= prime[l++];
	}

	printf("%d", ans);

	return 0;
}