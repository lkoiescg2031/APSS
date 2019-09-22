#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 100000

int n,k,d[MAX+1];

int main() {

	memset(d, 0x3f, sizeof(d));
	scanf("%d %d", &n, &k);

	queue<int> q;
	q.push(n), d[n] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int cost = d[cur];

		if (cur + 1 <= MAX && d[cur + 1] > cost + 1) 
			d[cur + 1] = cost + 1, q.push(cur + 1);
		if (cur - 1 >= 0 && d[cur - 1] > cost + 1)
			d[cur - 1] = cost + 1, q.push(cur - 1);
		if (cur * 2 <= MAX && d[cur * 2] > cost)
			d[cur * 2] = cost, q.push(cur * 2);
	}
	
	printf("%d", d[k]);
	return 0;
}