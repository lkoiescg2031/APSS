#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;

#define MAX 1000000

char P[101];
int K, np[MAX + 1];
vector<int> ps;

bool mod(int div) {
	int ret = 0;
	for (int i = 0; P[i]; i++)
		ret = (ret * 10 + P[i] - '0') % div;
	return ret == 0;
}

int main() {

	scanf("%s %d", P, &K);

	for (int i = 2; i < K; i++) {
		if (np[i]) continue;
		ps.push_back(i);
		for (long long j = (long long)i * i; j < K; j += i)
			np[j] = true;
	}

	for (auto p : ps)
		if (mod(p)) { printf("BAD %d\n", p); return 0; }

	printf("GOOD\n");
	return 0;
}