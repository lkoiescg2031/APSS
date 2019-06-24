#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int i, j, x = 0, y = 1;
int r, c;
int map[1000][1000];
string ans;

int main() {

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];

	if (r % 2 == 1) {
		for (int i = 0; i < r; i++)
			if (i % 2) ans += string(c - 1, 'L') + 'D';
			else ans += string(c - 1, 'R') + (i == r - 1 ? "" : "D");

	} else if (c % 2 == 1) {
		for (int i = 0; i < c; i++)
			if (i % 2) ans += string(r - 1, 'U') + 'R';
			else ans += string(r - 1, 'D') + (i == c - 1 ? "" : "R");

	} else {

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if ((i + j) % 2 && map[x][y] > map[i][j]) {
					x = i;
					y = j;
				}

		for (i = 0; i < x / 2; i++)	ans += string(c - 1, 'R') + 'D' + string(c - 1, 'L') + 'D';
		for (j = 0; j < y / 2; j++) ans += "DRUR";
		if (y % 2 == 0) ans += "RD";
		else ans += "DR";
		for (j = y / 2; j < c / 2 - 1; j++) ans += "RURD";
		for (i = x / 2; i < r / 2 - 1; i++) ans += 'D' + string(c - 1, 'L') + 'D' + string(c - 1, 'R');
	}

	cout << ans;

	return 0;
}