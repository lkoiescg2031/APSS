#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[10000];

bool next_permutation(int b, int e) {
	int i, j;
	
	for (i = e; i > b; i--)
		if (arr[i] > arr[i - 1])
			break;
	if (i <= b) return false;

	for (j = e; j >= i; j--)
		if (arr[i - 1] < arr[j])
			break;
	swap(arr[i - 1], arr[j]);
	reverse(arr + i, arr + e + 1);
	return true;
}
int main() {

	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	if (next_permutation(0, n - 1))
		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
	else
		printf("-1");
	////STL
	//if (next_permutation(arr, arr + n))
	//	for (int i = 0; i < n; i++)
	//		printf("%d ", arr[i]);
	//else
	//	printf("-1");

	return 0;
}