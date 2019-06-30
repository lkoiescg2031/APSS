#include <iostream>
#define MAX_PARTY 100

using namespace std;

int main() {

	int testcase,last_day;
	int party_num, party_hartal[MAX_PARTY];
	int result;

	cin >> testcase;

	while (testcase-- > 0) {
		cin >> last_day >> party_num;
		for (int i = 0;i < party_num;i++)
			cin >> party_hartal[i];
		result = 0;
		for (int i = 1;i <= last_day;i++) {
			if (i % 7 == 6 || i % 7 == 0)
				continue;
			for (int j = 0;j<party_num;j++)
				if (i%party_hartal[j] == 0) {
					result++;
					break;
				}
		}
			
		cout << result << endl;
	}

	return 0;
}