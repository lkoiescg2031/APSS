#include <cstdio>
#include <string>
#include <queue>
#include <tuple>
#include <map>
#include <algorithm>
using namespace std;

string cur_map;
int cur, x, y;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int main() {

	int start = 0, end = 123456789;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
		int num;
		scanf("%d", &num);
		if (num == 0) {
			num = 9;
			x = i;
			y = j;
		}
		start *= 10, start += num;
	}

	queue<tuple<int, int, int>> q;
	map<int, int> ans;
	bool flag = true;
	q.push({ start,x,y });
	ans.insert({ start,0 });
	while (!q.empty() && flag) {
		tie(cur, x, y) = q.front();
		cur_map = to_string(cur);
		q.pop();
		for (int i = 0; i < 4 && flag; i++) {
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx >= 0 && mx < 3 && my >= 0 && my < 3) {
				swap(cur_map[x * 3 + y], cur_map[mx * 3 + my]);
				int next = stoi(cur_map);
				if (ans.insert({ next,ans[cur] + 1 }).second) {
					q.push({ next,mx,my });
					flag = next != end;
				}
				swap(cur_map[x * 3 + y], cur_map[mx * 3 + my]);
			}
		}
	}

	ans.insert({ end,-1 });
	printf("%d", ans[end]);

	return 0;
}