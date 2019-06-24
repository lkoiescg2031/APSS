#include <cstdio>
#include <algorithm>
using namespace std;

int n, arr[10000];

bool prev_permutation(int b, int e) {
	int i = e, j = e;
	while (i > b && arr[i - 1] <= arr[i]) i--;
	if (i <= b) return false;
	while (j >= i && arr[j] >= arr[i - 1]) j--;
	swap(arr[i - 1], arr[j]);
	reverse(arr + i, arr + e + 1);
	return true;
}

int main() {
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	if (prev_permutation(0, n - 1)) {
		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}else
		printf("-1");
	////STL
	//if (prev_permutation(arr, arr + n)) {
	//	for (int i = 0; i < n; i++)
	//		printf("%d ", arr[i]);
	//	printf("\n");
	//}
	//else
	//	printf("-1");
	return 0;
}