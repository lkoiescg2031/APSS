#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

int main() {

	int flag = true;
	int a[9],sum=0;

	for (int i = 0; i < 9; i++) 
		scanf("%d", &a[i]), sum += a[i];

	for (int i = 0; flag && i < 9; i++)
		for (int j = i + 1; flag && j < 9; j++)
		if (sum - a[i] - a[j] == 100) {
			a[i] = a[j] = INF;
			flag = false;
		}

	sort(a, a + 9);
	for (int i = 0; i < 7; i++) 
		printf("%d\n", a[i]);

	return 0;
}