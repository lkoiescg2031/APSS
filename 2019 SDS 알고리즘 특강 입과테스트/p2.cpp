#include <cstdio>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;
using Plate = vector<string>;
using Check = vector<vector<bool>>;

int t, test;
int n, qn;

vector<Plate> p;

Plate q;
bool incolor['Z'];

void scanp(Plate& p) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) scanf("%c", &p[i][j]);
		getchar();
	}
}
Plate rotate(const Plate& p, int degree) {
	Plate ret(8, string(8, '.'));
	switch (degree) {
	case 0:
		ret = p;
		break;
	case 90:
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				ret[i][j] = p[8 - j - 1][i];
		break;
	case 180:
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				ret[i][j] = p[8 - i - 1][8 - j - 1];
		break;
	case 270:
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				ret[i][j] = p[j][8 - i - 1];
		break;
	}
	return ret;
}
bool is_selected(int select, int x) {
	while (select > 1) {
		if (select % 10 == x) return 1;
		select /= 10;
	}
	return false;
}
bool check_plate(Check& check, const Plate& p) {
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			if (!check[i][j] && p[i][j] != '.') {
				if (p[i][j] == q[i][j]) check[i][j] = true;
				else return false;
			}
	return true;
}
bool check_ans(const Check& check) {
	for(int i=0;i<8;i++)
		for (int j = 0; j < 8; j++) {
			if (check[i][j]) continue;
			if (q[i][j] == 'W') continue;
			return false;
		}
	return true;
}
int cmp(int a, int b) {
	int reta = a, retb = b;
	int alen = 0, blen = 0;

	//길이 비교
	while (a > 1) alen++, a /= 10;
	while (b > 1) blen++, b /= 10;
	if (alen < blen) return reta;
	else if (alen > blen) return blen;

	//길이가 같을 경우
	a = reta, b = retb;
	while (a > 1) {
		if (a % 10 > b % 10) return retb;
		else if (a % 10 < b % 10) return reta;
		a /= 10;
		b /= 10;
	}
	//동일할 경우
	return reta;
}
int bfs() {

	Check cur_map;
	int cur_select, ret = 1;
	queue<pair<Check, int>> que;
	
	que.push({ Check(8,vector<bool>(8,false)),1 });

	while (!que.empty()) {
		tie(cur_map, cur_select) = que.front();
		que.pop();
		if (cur_select >= 10000) continue;
		for (int i = n-1; i >= 0; i--) 
			if (!is_selected(cur_select, i)) {
				for (int j = 0; j < 4; j++) {
					Check tmp = cur_map;
					Plate plate = rotate(p[i], j * 90);
					if (check_plate(tmp, plate)) {
						int next_select = cur_select * 10 + i;
						if (check_ans(tmp)) {
							if (ret == 1) ret = next_select;
							else ret = cmp(ret, next_select);
							continue;
						}
						que.push({ tmp,next_select });
					}
				}
			}
	}
	return ret;
}

int main() {

	q = Plate(8, string(8, '.'));

	scanf("%d\n", &test);
	for (t = 1; t <= test; t++) {

		scanf("%d\n", &n);

		p = vector<Plate>();
		for (int i = 1; i <= n; i++) {
			scanp(q);
			p.push_back(q);
		}

		scanf("%d\n", &qn);

		printf("#%d ", t);
		while (qn--) {
			scanp(q);
			int selected = bfs();
			//결과
			vector<int> ans;
			while (selected > 1) {
				ans.push_back((selected % 10) + 1);
				selected /= 10;
			}
			printf("%d ", (int)ans.size());
			for (auto i : ans) printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}