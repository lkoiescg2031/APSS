#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;

int n, k, time[100001];

int main() {

	queue<int> q;
	scanf("%d %d", &n, &k);

	memset(time, -1, sizeof(time));
	q.push(n);
	time[n] = 0;
	while (!q.empty()) {
		int pos = q.front();
		int t = time[pos];
		q.pop();
		if (pos * 2 <= 100000 && time[pos * 2] == -1) 
			time[pos * 2] = t + 1, q.push(2 * pos);
		if (pos - 1 >= 0 && time[pos - 1] == -1) 
			time[pos - 1] = t + 1, q.push(pos - 1);
		if (pos + 1 <= 100000 && time[pos + 1] == -1) 
			time[pos + 1] = t + 1, q.push(pos + 1);
	}
	printf("%d", time[k]);
	return 0;
}