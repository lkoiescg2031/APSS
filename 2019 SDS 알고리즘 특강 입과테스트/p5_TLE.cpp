#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

double harvest(vector<int>& pq, int last, int cur) {

	double k[] = { 1, 1.53,1.97,2.39,2.68,2.94, 3.17,3.21,3.09,2.75,2.43,
					2.02,1.51,1.19,0.76,0.43, 0.21,0.17,0.13,0.11 };
	double ret = 0.0;
	int day = 0;
	for (int i = cur - 1; i >= last; i--) {
		if (day < 19) day++;
		ret += (pq[i] * k[day]);
	}
	return ret;
}

int main() {
	int t, test;
	scanf("%d", &test);
	for (t = 1; t <= test; t++) {
		int n, l, q;
		scanf("%d %d", &n, &l);
		vector<int> pq(n + 20, 0);
		for (int i = 1; i <= n; i++) scanf("%d", &pq[i]);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &q);
			pq[i] *= q;
		}
		vector<vector<double>> d(n + 20, vector<double>(l + 1, 0));
		for (int i = 1; i <= n + 19; i++)
			for (int j = 1; j <= l; j++) {
				for (int k = 1; k < i; k++) {
					d[i][j] = max(d[i][j], d[i - k][j - 1] + harvest(pq, i - k, i));
				}
			}
		printf("#%d %0.2f\n", t, d[n+19][l]);
	}
	return 0;
}