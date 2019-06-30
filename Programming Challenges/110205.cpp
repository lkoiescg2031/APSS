#include <iostream>
#include <sstream>
#define CARDNUM 52
#define MAXSHUFFLE 100

using namespace std;

int deck[CARDNUM + 1], oldDeck[CARDNUM + 1];
int shuffleNum, shuffle[MAXSHUFFLE + 1][CARDNUM + 1];
int testcase;

int main(void) {

	char line[100];
	stringstream sstream;
	int color, num;
	int i, j, t,temp;

	cin >> testcase;
	for (t = 0; t < testcase; t++) {

		cin >> shuffleNum;
		for (i = 1; i <= shuffleNum; i++)
			for (j = 1; j <= CARDNUM; j++)
				cin >> shuffle[i][j];
		for (i = 1; i <= CARDNUM; i++)
			deck[i] = i;

		cin.ignore();//clear buffer
		while (cin.getline(line, 100) && *line) {
			sstream.clear();
			sstream.str(line);//save shuffle_number what dealer use
			sstream >> temp;
			//to shuffle
			for (i = 1; i <= CARDNUM; i++)
				oldDeck[i] = deck[i];
			for (i = 1; i <= CARDNUM; i++)
				deck[i] = oldDeck[shuffle[temp][i]];
		}
		//print
		if (t > 0)
			putchar('\n');
		for (i = 1; i <= CARDNUM; i++) {
			color = (deck[i] - 1) / 13;
			num = (deck[i] - 1) % 13;

			switch (num) {
			case 12:
				printf("Ace"); break;
			case 11:
				printf("King"); break;
			case 10:
				printf("Queen"); break;
			case 9:
				printf("Jack"); break;
			default :
				printf("%d",num + 2);
			}
			printf(" of ");
			switch (color) {
			case 0:
				puts("Clubs"); break;
			case 1:
				puts("Diamonds"); break;
			case 2:
				puts("Hearts"); break;
			case 3:
				puts("Spades"); break;
			}
		}
	}
	return 0;
}
