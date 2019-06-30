#include <iostream>
#include <cstdlib>
using namespace std;

struct Player {
	int card[5];
	unsigned long long point;
};

int cmp(const void* x, const void* y) {
	return *(int*)x - *(int*)y;
}
int encode_card(char color, char num) {
	int result;
	switch (num) {
	case'T':result = 80;break;
	case'J':result = 90;break;
	case'Q':result = 100;break;
	case'K':result = 110;break;
	case'A':result = 120;break;
	default:result = (num - 50)*10;break;
	}
	switch (color) {
	case 'C':result += 1;break;
	case 'D':result += 2;break;
	case 'H':result += 3;break;
	case 'S':result += 4;break;
	}
	return result;
}
int getNum(Player x, int i) {
	return x.card[i] / 10;
}
int getColor(Player x, int i) {
	return x.card[i] % 10;
}
unsigned long long players_score(Player &x) {
	
	int i;
	int color, num;

	qsort(x.card, 5, sizeof(int), cmp);

	color = getColor(x,0);
	num = getNum(x, 0);
	//straight flush
	for (i = 1;i < 5;i++)
		if (!(getColor(x,i) == color && getNum(x,i) == num + i))
			break;
	if (i == 5)
		return 90000000000+ getNum(x,4);

	//fourcard
	if (getNum(x,0) == getNum(x,3))
		return 80000000000 + getNum(x,0);
	if (getNum(x,1) == getNum(x,4))
		return 80000000000 + getNum(x,1);

	//full house
	if (getNum(x,0) == getNum(x,2) && getNum(x,3) == getNum(x,4))
		return 70000000000 + getNum(x,0);
	if (getNum(x,0) == getNum(x,1) && getNum(x,2) == getNum(x,4))
		return 70000000000 + getNum(x,4);

	//flush
	for (i = 1;i < 5;i++)
		if (!(getColor(x,i) == color))
			break;
	if (i == 5)
		return 60000000000 + getNum(x,4) * 100000000 + getNum(x,3) * 1000000 + getNum(x,2) * 10000 + getNum(x,1) * 100 + getNum(x,0);

	//straight
	for (i = 1;i < 5;i++)
		if (!(getNum(x,i) == num + i))
			break;
	if (i == 5)
		return 50000000000 + getNum(x,4);

	//three card
	if (getNum(x,0) == getNum(x,2))
		return 40000000000 + getNum(x,0);
	if (getNum(x,1) == getNum(x,3))
		return 40000000000 + getNum(x,1);
	if (getNum(x,2) == getNum(x,4))
		return 40000000000 + getNum(x,2);

	//two pair
	if (getNum(x,0) == getNum(x,1) && getNum(x,2) == getNum(x,3))
		return 30000000000 + getNum(x,2) * 10000 + getNum(x,0) * 100 + getNum(x,4);
	if (getNum(x,0) == getNum(x,1) && getNum(x,3) == getNum(x,4))
		return 30000000000 + getNum(x,3) * 10000 + getNum(x,0) * 100 + getNum(x,2);
	if (getNum(x,1) == getNum(x,2) && getNum(x,3) == getNum(x,4))
		return 30000000000 + getNum(x,3) * 10000 + getNum(x,1) * 100 + getNum(x,0);

	//one pair
	if (getNum(x,0) == getNum(x,1))
		return 20000000000 + getNum(x,0) * 1000000 + getNum(x,4) * 10000 + getNum(x,3) * 100 + getNum(x,2);
	if (getNum(x,1) == getNum(x,2))
		return 20000000000 + getNum(x,1) * 1000000 + getNum(x,4) * 10000 + getNum(x,3) * 100 + getNum(x,0);
	if (getNum(x,2) == getNum(x,3))
		return 20000000000 + getNum(x,2) * 1000000 + getNum(x,4) * 10000 + getNum(x,1) * 100 + getNum(x,0);
	if (getNum(x,3) == getNum(x,4))
		return 20000000000 + getNum(x,3) * 1000000 + getNum(x,2) * 10000 + getNum(x,1) * 100 + getNum(x,0);

	//non
	return 10000000000 + getNum(x,4) * 100000000 + getNum(x,3) * 1000000 + getNum(x,2) * 10000 + getNum(x,1) * 100 + getNum(x,0);
}
int main() {
	
	char color, num;
	Player white,black;

	for (int i = 0;cin >> num >> color;i++) {
		if (i < 5) {
			black.card[i] = encode_card(color, num);
		}
		else if (i < 9) {
			white.card[i - 5] = encode_card(color, num);
		}
		else {
			white.card[i - 5] = encode_card(color, num);

			black.point = players_score(black);
			white.point = players_score(white);

			if (black.point > white.point)
				cout << "Black wins." << endl;
			else if (black.point < white.point)
				cout << "White wins." << endl;
			else
				cout << "Tie." << endl;

			i = -1;
		}
	}

	return 0;
}