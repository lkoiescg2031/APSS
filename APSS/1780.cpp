#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<vector<int>> map;
int ans[3];

void calcul(int x, int y, int size) {
	int cmp = map[x][y], cnt = 0;
	bool flag = true;
	
	for (int i = 0; i < size && flag; i++)
		for (int j = 0; j < size && flag; j++)
			if (cmp != map[x + i][y + j])
				flag = false;
	
	if (flag) {
		ans[cmp + 1]++;
		return;
	}
	size /= 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			calcul(x + size * i, y + size * j, size);
}

int main() {
	scanf("%d", &n);
	map = vector<vector<int>>(n, vector<int>(n));
	for (auto& arr : map) for (auto& i : arr) scanf("%d", &i);
	calcul(0, 0, n);
	printf("%d\n%d\n%d", ans[0], ans[1], ans[2]);
	return 0;
}