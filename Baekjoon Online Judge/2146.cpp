#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

#define MAX 100

int n, bitmap[MAX][MAX];
int x, y, dist[MAX][MAX], ans;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
queue<pair<int, int>> q;

void dfs(int i, int j,int paint) {
	bitmap[i][j] = paint;
	dist[i][j] = 0;
	
	for (int k = 0; k < 4; k++) {
		int movei = i + dx[k];
		int movej = j + dy[k];
		if (movei >= 0 && movej >= 0 && movei < n && movej < n) {
			if (bitmap[movei][movej] == 1)
				dfs(movei, movej, paint);
			else if (bitmap[movei][movej] == 0) {
				q.push({ movei,movej });
				bitmap[movei][movej] = paint;
				dist[movei][movej] = 1;
			}
		}			
	}
}

int main() {

	int paint = 2;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> bitmap[i][j];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if (bitmap[i][j] == 1) 
				dfs(i, j, paint++);

	ans = 0x3f3f3f3f;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int movex = x + dx[i];
			int movey = y + dy[i];
			if (movex >= 0 && movey >= 0 && movex < n && movey < n) {
				if (bitmap[movex][movey] == 0) {
					bitmap[movex][movey] = bitmap[x][y];
					dist[movex][movey] = dist[x][y] + 1;
					q.push({ movex,movey });
				} else if(bitmap[movex][movey] != bitmap[x][y]){
					ans = min(ans, dist[movex][movey] + dist[x][y]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}