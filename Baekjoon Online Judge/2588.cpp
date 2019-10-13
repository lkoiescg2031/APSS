#include <cstdio>
#include <stack>;
using namespace std;

int main() {
	int a, b, ans = 0;
	stack<int> s;
	scanf("%d", &a);
	for (int i = 0; i < 3; i++) {
		scanf("%1d", &b);
		s.push(a * b);
	}
	for (int i = 1; i < 1000; i*=10) {
		printf("%d\n", s.top());
		ans += s.top() * i;
		s.pop();
	}
	printf("%d", ans);
	return 0;
}