#include <cstdio>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;

int t, a, b, pre[10000], choice[10000];

int itoc[] = { 'D','S','L','R' };
int cal(int n, int op) {
	switch (itoc[op]) {
	case 'D':
		return (2 * n) % 10000;
	case 'S':
		return n == 0 ? 9999 : n - 1;
	case 'L':
		return (n * 10) % 10000 + n / 1000;
	case 'R':
		return n / 10 + (n % 10) * 1000;
	}
}
void printop(int n) {
	if (pre[n] == n) return;

	printop(pre[n]);
	printf("%c", choice[n], n);
}

int main() {

	scanf("%d", &t);
	while (t-- > 0) {
		queue<int> q;
		bool flag = true;
		scanf("%d %d", &a, &b);
		
		memset(pre, -1, sizeof(pre));
		pre[a] = a;
		q.push(a);
		while (!q.empty() && flag) {
			int cur = q.front();
			q.pop();
			for (int op = 0; op < 4 && flag; op++) {
				int next = cal(cur, op);
				if (pre[next] == -1) {
					pre[next] = cur;
					choice[next] = itoc[op];
					q.push(next);
					flag = next != b;
				}
			}
		}
		printop(b);
		printf("\n");
	}

	return 0;
}