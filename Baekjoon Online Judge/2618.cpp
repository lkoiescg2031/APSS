#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

using Point = pair<int, int>;
#define x first
#define y second

inline int dst(const Point& a, const Point& b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int N, W;
Point loc[1002];
int d[1002][1002], whoWork[1002][1002];

int go(int aw, int bw) { 
	int nextW = max(aw, bw) + 1;
	if (nextW == W + 2) return 0;

	int& ret = d[aw][bw];
	if (ret != INF) return ret;
	//1번이 일하는 경우
	ret = go(nextW, bw) + dst(loc[aw], loc[nextW]), whoWork[aw][bw] = 1;
	//2번이 일하는 경우
	int cmp = go(aw, nextW) + dst(loc[bw], loc[nextW]);
	if (ret > cmp) ret = cmp, whoWork[aw][bw] = 2;
	return ret;
}

int main() {

	scanf("%d %d", &N, &W);

	loc[0] = { 1,1 }; loc[1] = { N,N };
	for (int i = 2; i < W + 2; i++) scanf("%d %d", &loc[i].x, &loc[i].y);

	memset(d, 0x3f, sizeof(d));	
	printf("%d\n", go(0, 1));

	int i = 0, j = 1;
	while (max(i,j) != W + 1) {
		printf("%d\n", whoWork[i][j]);
		if (whoWork[i][j] == 1) i = max(i, j) + 1;
		else j = max(i, j) + 1;
	}
	return 0;
}