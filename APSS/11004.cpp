#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 5000000

int n, k;
int list[MAX + 1];

int parition(int* arr, int low, int high) {
	int pivot_index = low + (high - low) / 2;
	int pivot_value = arr[pivot_index];
	swap(arr[high], arr[pivot_index]);
	int cnt = low;

	for(int i= low;i<high;i++)
		if (arr[i] < pivot_value) 
			swap(arr[cnt++], arr[i]);
	swap(arr[cnt], arr[high]);
	return cnt;
}

int find_kth(int *arr, int low, int high, int k) {
	if (low == high) {
		return arr[low];
	}else if (low < high) {
		int pivot = parition(arr, low, high);
		if (pivot == k) 
			return arr[k];	
		else if(pivot > k)
			return find_kth(arr, low, pivot - 1, k);
		else if(pivot < k)
			return find_kth(arr, pivot + 1, high, k);
	}
}

int main() {

	scanf("%d %d",&n,&k);
	for (int i = 0; i < n; i++) scanf("%d",&list[i]);
	printf("%d",find_kth(list, 0, n - 1, k - 1));
	return 0;
}