#include <iostream>
using namespace std;

char mine[102][102];

int main() {

	int i, j, i2, j2;
	int n=0, m=0,cnt=1;

	cin >> n >> m;

	while (n||m) {
		
		for (i = 1;i <= n;i++) {
			for (j = 1;j <= m;j++) {
				cin >> mine[i][j];
				if (mine[i][j] != '*') {
					mine[i][j] = '0';
				}
			}
		}

		for (i = 1;i <= n;i++) {
			for (j = 1;j <= m;j++) {
				if (mine[i][j] == '*') {
					for (i2 = i - 1;i2 <= i + 1;i2++) {
						for (j2 = j - 1; j2 <= j + 1;j2++) {
							if (mine[i2][j2] != '*') {
								mine[i2][j2]++;
							}
						}
					}

					mine[i][j] = '*';
				}
			}
		}
		if (cnt > 1) cout << endl;
		cout << "Field #" << cnt++ <<":"<< endl;
		for (i = 1;i <= n;i++) {
			for (j = 1;j <= m;j++) {
				cout << mine[i][j];
			}
			cout << endl;
		}/*
		cout << endl;*/
		cin >> n >> m;
	}
	return 0;
}