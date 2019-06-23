#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;

int t;
int C, D, dd;
vector<int> a, b;
int d[200][100][100][2][2];

int go(int day, int i, int j, int ipre, int jpre) {
	if (i == a.size() && j == b.size()) return 0;
	int& ret = d[day][i][j][ipre][jpre];
	if (d[day][i][j][ipre][jpre] != inf) return d[day][i][j][ipre][jpre];

	if (i < a.size() && j < b.size())
		ret = min(ret, go(day + 1, i + 1, j + 1, 0, 0) + (a[i] == b[j] ? C : 2 * C));

	if (i < a.size())
		ret = min(ret, go(day + 1, i + 1, j, 0, 1) + C + dd + (jpre ? 0 : D));

	if (j < b.size())
		ret = min(ret, go(day + 1, i, j + 1, 1, 0) + C + dd + (ipre ? 0 : D));
	return ret;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		a = b = vector<int>();
		memset(d, 0x3f, sizeof(d));
		scanf("%d %d %d", &C, &D, &dd);
		int i;
		while (scanf("%d", &i) && i != 0) a.push_back(i);
		while (scanf("%d", &i) && i != 0) b.push_back(i);

		printf("%d\n", go(0, 0, 0, 0, 0));
	}

	return 0;
}