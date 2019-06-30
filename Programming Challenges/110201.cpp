#include <iostream>

#define INPUT_MAX 3000
#define ABS(x) ((x)>0?(x):-1*(x))

using namespace std;

int jolly_jumpers[INPUT_MAX];

int main() {

	int result;
	int i_num;
	int cur, pre,abs;

	while (cin >> i_num) {
		result = 1;
		cin >> cur;
		for (int i = 1;i < i_num;i++) {
			pre = cur;
			cin >> cur;
			abs = ABS(cur - pre);
			if(abs < i_num)
				jolly_jumpers[abs] = 1;
		}

		for (int i = 1;i < i_num;i++) {
			if (jolly_jumpers[i])
				jolly_jumpers[i] = 0;
			else
				result = 0;
		}
		if (result)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}

	return 0;
}