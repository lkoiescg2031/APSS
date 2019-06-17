#include <cstdio>
#include <deque>
#include <tuple>
using namespace std;

int n, l;

int main() {

	int j;
	scanf("%d %d", &n, &l);
	deque<pair<int, int>>q;
	for (int i = 0; i < n; i++) {
		scanf("%d", &j);
		while (!q.empty() && q.front().first <= i - l) q.pop_front();
		while (!q.empty() && q.back().second > j ) q.pop_back();
		q.push_back({ i,j });
		printf("%d ", q.front().second);
	}
	return 0;
}