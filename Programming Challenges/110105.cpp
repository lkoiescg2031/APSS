#include <iostream>

#define MAX 250

using namespace std;

char bitmap[MAX+1][MAX+1];
int m, n;

void bitmapf(const int x,const int y,const char temp,const char c) {

	int x1 = x - 1, x2 = x+1;
	int y1 = y - 1, y2 = y+1;
	bitmap[y][x] = c;

	if (y1 > 0 && bitmap[y1][x] == temp)
		bitmapf(x, y1, temp, c);
	if (x1 > 0 && bitmap[y][x1] == temp)
		bitmapf(x1, y, temp, c);
	if (x2 <= m && bitmap[y][x2] == temp)
		bitmapf(x2, y, temp, c);
	if (y2 <= n && bitmap[y2][x] == temp)
		bitmapf(x, y2, temp, c);
}
int main() {

	int x1, y1, x2, y2;
	char command='\0',c;
	char filename[13];

	while (	cin >> command&& command != 'X') {
		switch (command) {
		case'I':
			cin >> m >> n;
		case'C':
			for (int i = 1;i <= n;i++) {
				for (int j = 1;j <= m;j++) {
					bitmap[i][j] = 'O';
				}
			}
			break;
		case'L':
			cin >> x1 >> y1 >> c;
			bitmap[y1][x1] = c;
			break;
		case'V':
			cin >> x1 >> y1 >> y2 >> c;
			if (y1 > y2) {
				int temp = y1;
				y1 = y2;
				y2 = temp;
			}
			for (int i = y1;i <= y2;i++) {
				bitmap[i][x1] = c;
			}
			break;
		case'H':
			cin >> x1 >> x2 >> y1 >> c;
			if (x1 > x2) {
				int temp =x1;
				x1 = x2;
				x2 = temp;
			}
			for (int i = x1;i <=x2;i++) {
				bitmap[y1][i] = c;
			}
			break;
		case'K':
			cin >> x1 >> y1 >> x2 >> y2 >> c;
			for (int i = y1;i <=y2;i++) {
				for (int j = x1;j <=x2;j++) {
					bitmap[i][j] = c;
				}
			}
			break;
		case'F':
			cin >> x1 >> y1 >> c;
			if(c!=bitmap[y1][x1])
				bitmapf(x1,y1,bitmap[y1][x1],c);
			break;
		case'S':
			cin >> filename;
			cout << filename << endl;
			for (int i = 1;i <= n;i++) {
				for (int j = 1;j <= m;j++) {
					cout << bitmap[i][j];
				}
				cout << endl;
			}
			break;
		}
	}

	return 0;
}