#include <iostream>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int main() {
	long n, m, result;
	long temp, ntemp, mtemp;

	while (cin >> n >> m) {
		ntemp = n;
		mtemp = m;
		if (ntemp > mtemp) {
			temp = ntemp;
			ntemp = mtemp;
			mtemp = temp;
		}
		result = 0;
		for (long i = ntemp;i <= mtemp;i++) {
			long j = i,cnt = 1;
			while (j != 1) {
				if (j % 2) {
					j = j * 3 + 1;
					cnt++;
				}
				while (j % 2 == 0) {
					j /= 2;
					cnt++;
				}
			}
			result = max(result,cnt);
		}
		cout << n <<" "<< m << " "<< result << endl;
	}
	return 0;
}