#include <cstdio>
#include <tuple>
using namespace std;

using point = pair<int, int>;
#define _x first
#define _y second

#define abs(a) ((a)<0? (-(a)) : (a))

inline int dist(point& a, point& b) {
	return abs(a._x - b._x) + (a._y - b._y);
}

int n, w;
point loc[1001], p[1001][1001]; //loc �� ��ġ , p.first�� �̵��� ���� p.second�� �̵����� �ذ��� ���
int d[1001][1001];

int main() {

	scanf("%d %d", &n, &w);
	for (int i = 1; i <= w; i++) 
		scanf("%d %d", &loc[i]._x, &loc[i]._y);

	memset(d, 0x3f, sizeof(d));
	for (int k = 1; k <= w; k++) {
		for (int pre = 2; pre < k; pre++) {

		}
	}



	return 0;
}