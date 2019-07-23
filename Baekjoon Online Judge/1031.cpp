#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;
int a[102][102];
int n;
int source = 100, sink = 101;
bool check[102];
int dfs(int x) {
	if (check[x]) return 0;
	check[x] = true;
	if (x == sink) {
		return true;
	}
	for (int i = 0; i <= sink; i++) {
		if (a[x][i] > 0) {
			if (dfs(i)) {
				a[x][i] -= 1;
				a[i][x] += 1;
				return true;
			}
		}
	}
	return false;
}
int flow() {
	int ans = 0;
	while (true) {
		memset(check, false, sizeof(check));
		if (!dfs(source)) {
			break;
		}
		ans += 1;
	}
	return ans;
}
int main() {
	int n, m;
	cin >> n >> m;
	int s1 = 0, s2 = 0;
	//소스간선 연결
	for (int i = 0; i < n; i++) {
		cin >> a[source][i];
		s1 += a[source][i];
	}
	for (int i = 0; i < m; i++) {
		cin >> a[n + i][sink];
		s2 += a[n + i][sink];
	}
	//s1 != s2가 다르면
	if (s1 != s2) {
		printf("-1\n");
		return 0;
	}
	//중간 간선 연결
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][n + j] = 1;
		}
	}
	//flow
	int ans = flow();
	//flow 확인
	if (s1 != ans) {
		printf("-1\n");
		return 0;
	}
	//모든 엣지쌍에 대해
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool ans = false;
			if (a[i][n + j] == 0) {//i에서 j로 흐를 수 있으면
				a[source][i] += 1;//유량을 늘려
				a[n + j][sink] += 1;
				memset(check, false, sizeof(check));
				if (!dfs(source)) {//더 흐를수 있는지 확인
					ans = true;//흐를 수 없다면 정답이 된다.
					a[source][i] -= 1;// 이후 간선을 지운다.
					a[n + j][sink] -= 1;// 간선을 지운다.
				}
			}
			a[i][n + j] = 0; // 해당간선을 삭제하고
			if (ans) {
				cout << '1';
			}
			else {
				cout << '0';
			}
		}
		cout << '\n';
	}
	return 0;
}