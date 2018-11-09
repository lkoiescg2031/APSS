#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,N) for(int (i)=0;(i)<(N);(i)++)
#define MAX 11
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4

int num_size;
int num[MAX + 1];
int op[5];

int ret_min = 1000000000, ret_max = -1000000000;

void solve(int cnt,int cal) {

	if (cnt == num_size) {
		ret_min = min(ret_min, cal);
		ret_max = max(ret_max, cal);
		return;
	}

	for (int i = 1; i < 5; i++) {
		if (op[i] > 0) {
			op[i]--;
			switch (i) {
			case ADD :
				solve(cnt + 1, cal + num[cnt]); break;
			case SUB:
				solve(cnt + 1, cal - num[cnt]); break;
			case MUL:
				solve(cnt + 1, cal * num[cnt]); break;
			case DIV:
				solve(cnt + 1, cal / num[cnt]); break;
			}
			op[i]++;
		}
	}

}

int main() {
	
	ios_base::sync_with_stdio(false);

	cin >> num_size;
	FOR(i, num_size) cin >> num[i];
	cin >> op[ADD] >> op[SUB] >> op[MUL] >> op[DIV];

	solve(1,num[0]);
	
	cout << ret_max << endl << ret_min << endl;

	return 0;
}