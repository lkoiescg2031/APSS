#include <cstdio>
#include <stack>
using namespace std;

#define MAX 1000

int n,a[MAX+1], d[MAX+1], pre[MAX+1];

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pre[i] = i;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			if (a[j] < a[i] && d[i] < d[j] + 1) 
				d[i] = d[j] + 1, pre[i] = j;

	int i = 0;
	for(int j=1;j<=n;j++)
		if (d[i] < d[j]) i = j;

	stack<int> s;
	while (i != pre[i]) s.push(a[i]),i = pre[i];
	printf("%d\n", s.size());
	while (!s.empty()) printf("%d ", s.top()), s.pop();

	return 0;
}