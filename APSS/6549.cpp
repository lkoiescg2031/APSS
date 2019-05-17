#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

int n, arr[100001];
long long ans;
int main() {
	while (scanf("%d", &n) && n != 0) {
		ans = 0;
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		arr[n++] = 0;
		stack<int> s;
		for (int i = 0; i < n; i++) {
			while (!s.empty() && arr[s.top()] > arr[i]) {
				long long height = arr[s.top()];
				s.pop();
				long long width = s.empty() ? i : i - (s.top() + 1);
				ans = max(ans, width * height);
			}
			s.push(i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}