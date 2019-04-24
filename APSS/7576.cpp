#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define MAX 1000

int m, n;
int bitmap[MAX][MAX];
int cnt_tmt;
int curi, curj, day;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

queue<tuple<int, int, int>> q;


int main() {

	cin >> m >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> bitmap[i][j];
			if (bitmap[i][j] == -1)
				cnt_tmt++;
			else if (bitmap[i][j] == 1)
				q.push({ 0,i,j }),bitmap[i][j] = 0;
		}

	while (!q.empty()) {
		tie(day, curi, curj) = q.front();
		q.pop();
		if (bitmap[curi][curj] == 1)
			continue;
		cnt_tmt++;
		if (cnt_tmt == n * m)
			break;
		bitmap[curi][curj] = 1;
		for (int i = 0; i < 4; i++) {
			int movei = curi + dx[i];
			int movej = curj + dy[i];
			if (0 <= movei && movei < n && 0 <= movej && movej < m &&
				bitmap[movei][movej] == 0) {
				q.push({ day + 1,movei,movej });
			}
		}
	}

	if (cnt_tmt == n * m)
		cout << day;
	else
		cout << "-1";

	return 0;
}