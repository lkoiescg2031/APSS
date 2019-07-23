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
	//�ҽ����� ����
	for (int i = 0; i < n; i++) {
		cin >> a[source][i];
		s1 += a[source][i];
	}
	for (int i = 0; i < m; i++) {
		cin >> a[n + i][sink];
		s2 += a[n + i][sink];
	}
	//s1 != s2�� �ٸ���
	if (s1 != s2) {
		printf("-1\n");
		return 0;
	}
	//�߰� ���� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][n + j] = 1;
		}
	}
	//flow
	int ans = flow();
	//flow Ȯ��
	if (s1 != ans) {
		printf("-1\n");
		return 0;
	}
	//��� �����ֿ� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool ans = false;
			if (a[i][n + j] == 0) {//i���� j�� �带 �� ������
				a[source][i] += 1;//������ �÷�
				a[n + j][sink] += 1;
				memset(check, false, sizeof(check));
				if (!dfs(source)) {//�� �带�� �ִ��� Ȯ��
					ans = true;//�带 �� ���ٸ� ������ �ȴ�.
					a[source][i] -= 1;// ���� ������ �����.
					a[n + j][sink] -= 1;// ������ �����.
				}
			}
			a[i][n + j] = 0; // �ش簣���� �����ϰ�
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