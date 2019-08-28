#include <iostream>
#include <string>
#include <tuple>
#include <stack>
#include <algorithm>
using namespace std;

int dx[] = {-1,0,-1};
int dy[] = {0,-1,-1};
#define UP 0 
#define LEFT 1
#define UP_LEFT 2

string a, b;
int d[1001][1001];
int p[1001][1001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	a = 'a' + a;b = 'b' + b;
	int alen = a.size(), blen = b.size();
	for (int i = 1; i < alen; i++) for (int j = 1; j < blen; j++) {
		if (d[i - 1][j] > d[i][j - 1]) d[i][j] = d[i - 1][j], p[i][j] = UP;
		else d[i][j] = d[i][j - 1], p[i][j] = LEFT;
		if (a[i] == b[j] && d[i-1][j-1]+1 > d[i][j]) d[i][j] = d[i - 1][j - 1] + 1, p[i][j] = UP_LEFT;
	}

	stack<int> ans;
	int i = alen - 1, j = blen - 1;
	while (i > 0 && j > 0) {
		int state = p[i][j];
		if (state == UP_LEFT) ans.push(a[i]);
		i = i + dx[state], j = j + dy[state];
	}
	printf("%d\n", ans.size());
	while (!ans.empty()) printf("%c", ans.top()), ans.pop();

	return 0;
}