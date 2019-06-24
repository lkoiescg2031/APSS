#include <cstdio>
using namespace std;

#define MAX 10000

int num[MAX + 1];
int n;

int main() {

	int k;
	scanf("%d",&n);
	while (n-- > 0) scanf("%d",&k), num[k]++;

	for (int i = 1; i <= MAX; i++)
		if (num[i] != 0)
			while (num[i]-- > 0) printf("%d\n", i);

	return 0;
}