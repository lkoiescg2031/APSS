#include <iostream>
#include <cstring>

#define MAX_of_s 10
#define MAX_of_n 8
#define SPACE " "
#define null '\0'
#define zero '0'
#define OFF 0
#define ON 1
#define FOR(start,end) for(int start=0;start<end;start++)
#define STRCAT(num,add) strcat(result[num],add)

using namespace std;

int s, stringlen,num;
char n[MAX_of_n+1];
char result[5][(MAX_of_s + 3)*MAX_of_n];
char hor_bar[2][MAX_of_s + 1] = { "          ","----------" };
char ver_bar[2][2] = { " ","|" };
const int hor[10][3] = { {1,0,1},{0,0,0},{1,1,1},{1,1,1},{0,1,0},
						  {1,1,1},{1,1,1},{1,0,0},{1,1,1},{1,1,1} };
const int ver[10][4] = { {1,1,1,1},{0,1,0,1},{0,1,1,0},{0,1,0,1},{1,1,0,1},
						 {1,0,0,1},{1,0,1,1},{0,1,0,1},{1,1,1,1},{1,1,0,1} };

int main() {
	while (cin >> s >> n && s != 0) {
		FOR (i, 5) {
			result[i][0] = null;
		}
		stringlen = strlen(n);
		hor_bar[OFF][s] = null;
		hor_bar[ON][s] = null;
		FOR (i, stringlen) {
			num = n[i] - zero;

			FOR(j, 5 && i>0)
				STRCAT(j, SPACE);

			STRCAT(0, SPACE);
			STRCAT(0, hor_bar[hor[num][0]]);
			STRCAT(0, SPACE);

			STRCAT(1, ver_bar[ver[num][0]]);
			STRCAT(1, hor_bar[OFF]);
			STRCAT(1, ver_bar[ver[num][1]]);

			STRCAT(2, SPACE);
			STRCAT(2, hor_bar[hor[num][1]]);
			STRCAT(2, SPACE);

			STRCAT(3, ver_bar[ver[num][2]]);
			STRCAT(3, hor_bar[OFF]);
			STRCAT(3, ver_bar[ver[num][3]]);

			STRCAT(4, SPACE);
			STRCAT(4, hor_bar[hor[num][2]]);
			STRCAT(4, SPACE);
		}

		cout << result[0]<<endl;
		FOR(i, s) {
			cout << result[1]<<endl;
		}

		cout << result[2]<<endl;

		FOR(i, s) {
			cout << result[3] << endl;
		}

		cout << result[4] << endl<<endl;

		hor_bar[OFF][s] = ' ';
		hor_bar[ON][s] = '-';
	}

	return 0;
}