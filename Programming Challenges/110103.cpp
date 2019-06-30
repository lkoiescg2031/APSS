#include<iostream>
#include<iomanip>
#include<cstdlib>
#define ABS(x) ((x)<0 ? -1*(x) : (x))
#define MAX 1000
using namespace std;

int stu[MAX];
int pay[MAX];

int cmp(const void *x, const void *y) {	return *(int*)y - *(int*)x;}

int main() {

	int result, mod, sum, aver;
	int n;
	double input;

	while (cin >> n && n != 0) {

		sum = 0;
		result = 0;

		for (int i = 0;i < n;i++) {
			cin >> input;
			stu[i] = (int)(input * 100+0.5);
			sum += stu[i];
		}

		mod = sum % n;
		aver = sum / n;
		qsort(stu, n, sizeof(int), cmp);

		for (int i = 0;i < n;i++) {
			pay[i] = aver;
		}

		for (int i = 0;i < mod;i++) {
			pay[i]++;
		}

		for (int i = 0;i < n;i++) {
			result += ABS(stu[i]-pay[i]);
		}

		cout.precision(2);
		cout << fixed << "$" << result / 200.0 << endl;
	}

	return 0;
}
