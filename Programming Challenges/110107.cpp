#include<iostream>

using namespace std;

char chesmap[8][8];

int isRookCheck(int i, int j,char king) {
	
	int cnt;

	for (cnt = i - 1;cnt >= 0;cnt--)
		if (chesmap[cnt][j] != '.')
			break;

	if (cnt >= 0 && chesmap[cnt][j] == king)
		return 1;

	for (cnt = i + 1;cnt < 8;cnt++)
		if (chesmap[cnt][j] != '.')
			break;

	if (cnt < 8 && chesmap[cnt][j] == king)
		return 1;

	for (cnt = j - 1;cnt >= 0;cnt--)
		if (chesmap[i][cnt] != '.')
			break;

	if (cnt >= 0 && chesmap[i][cnt] == king)
		return 1;

	for (cnt = j + 1;cnt < 8;cnt++)
		if (chesmap[i][cnt] != '.')
			break;

	if (cnt < 8 && chesmap[i][cnt] == king)
		return 1;

	return 0;
}
int isBishopCheck(int i, int j, char king) {
	char temp='\0';
	int cnt;

	for (cnt = 1;i - cnt >= 0 && j - cnt >= 0;cnt++)
		if (chesmap[i - cnt][j - cnt] != '.') {
			temp = chesmap[i - cnt][j - cnt];
			break;
		}
	if (temp == king)
		return 1;
	temp = '\0';

	for (cnt = 1;i - cnt >= 0 && j + cnt <8;cnt++)
		if (chesmap[i - cnt][j + cnt] != '.') {
			temp = chesmap[i - cnt][j + cnt];
			break;
		}
	if (temp == king)
		return 1;
	temp = '\0';

	for (cnt = 1;i + cnt <8 && j + cnt <8;cnt++)
		if (chesmap[i + cnt][j + cnt] != '.') {
			temp = chesmap[i + cnt][j + cnt];
			break;
		}
	if (temp == king)
		return 1;
	temp = '\0';

	for (cnt = 1;i + cnt <8 && j - cnt >=0;cnt++)
		if (chesmap[i + cnt][j - cnt] != '.') {
			temp = chesmap[i + cnt][j - cnt];
			break;
		}
	if (temp == king)
		return 1;

	return 0;
}

int main() {

	int cnt = 1;
	int flag = 1;
	int result = 0;

	while (1) {
		for(int i=0;i<8;i++)
			for (int j = 0;j < 8;j++) {
				cin >> chesmap[i][j];
				if (chesmap[i][j] != '.')
					flag = 0;
			}
		if (flag)
			break;
		for(int i=0;i<8 && result == 0;i++)
			for (int j = 0;j < 8 && result == 0;j++) 
				switch (chesmap[i][j]) {
				case 'p':
					if (i + 1 < 8) {
						if (j + 1 < 8 && chesmap[i + 1][j + 1] == 'K')
							result = 1;
						if (j - 1 >= 0 && chesmap[i + 1][j - 1] == 'K')
							result = 1;
					}
					break;
				case 'r':
					if (isRookCheck(i, j, 'K'))
						result = 1;
					break;
				case 'b':
					if (isBishopCheck(i, j, 'K'))
						result = 1;
					break;
				case 'q':
					if (isBishopCheck(i, j, 'K'))
						result = 1;
					if (isRookCheck(i, j, 'K'))
						result = 1;
					break;
				case 'n':
					if (i - 2 >= 0) {
						if (j + 1 < 8 && chesmap[i - 2][j + 1] == 'K')
							result = 1;
						if (j - 1 >= 0 && chesmap[i - 2][j - 1] == 'K')
							result = 1;
					}
					if (i - 1 >= 0) {
						if (j + 2 < 8 && chesmap[i - 1][j + 2] == 'K')
							result = 1;
						if (j - 2 >= 0 && chesmap[i - 1][j - 2] == 'K')
							result = 1;
					}
					if (i + 1 < 8) {
						if (j + 2 < 8 && chesmap[i + 1][j + 2] == 'K')
							result = 1;
						if (j - 2 >= 0 && chesmap[i + 1][j - 2] == 'K')
							result = 1;
					}
					if (i + 2 < 8) {
						if (j + 1 < 8 && chesmap[i + 2][j + 1] == 'K')
							result = 1;
						if (j - 1 >= 0 && chesmap[i + 2][j - 1] == 'K')
							result = 1;
					}
					break;
				case 'P':
					if (i - 1 >= 0) {
						if (j + 1 < 8 && chesmap[i - 1][j + 1] == 'k')
							result = 2;
						if (j - 1 >= 0 && chesmap[i - 1][j - 1] == 'k')
							result = 2;
					}
					break;
				case 'R':
					if (isRookCheck(i, j, 'k'))
						result = 2;
					break;
				case 'B':
					if (isBishopCheck(i, j, 'k'))
						result = 2;
					break;
				case 'Q':
					if (isRookCheck(i, j, 'k'))
						result = 2;
					if (isBishopCheck(i, j, 'k'))
						result = 2;
					break;
				case 'N':
					if (i - 2 >= 0) {
						if (j + 1 < 8 && chesmap[i - 2][j + 1] == 'k')
							result = 2;
						if (j - 1 >= 0 && chesmap[i - 2][j - 1] == 'k')
							result = 2;
					}
					if (i - 1 >= 0) {
						if (j + 2 < 8 && chesmap[i - 1][j + 2] == 'k')
							result = 2;
						if (j - 2 >= 0 && chesmap[i - 1][j - 2] == 'k')
							result = 2;
					}
					if (i + 1 < 8) {
						if (j + 2 < 8 && chesmap[i + 1][j + 2] == 'k')
							result = 2;
						if (j - 2 >= 0 && chesmap[i + 1][j - 2] == 'k')
							result = 2;
					}
					if (i + 2 < 8) {
						if (j + 1 < 8 && chesmap[i + 2][j + 1] == 'k')
							result = 2;
						if (j - 1 >= 0 && chesmap[i + 2][j - 1] == 'k')
							result = 2;
					}
					break;
				}
		if (result == 1)
			cout << "Game #" << cnt << ": white king is in check." << endl;
		else if (result == 2)
			cout << "Game #" << cnt << ": black king is in check." << endl;
		else if (result == 0)
			cout << "Game #" << cnt << ": no king is in check." << endl;
		cnt++;
		result = 0;
		flag = 1;
	}
	return 0;
}