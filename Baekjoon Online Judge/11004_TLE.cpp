#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 5000000

int n, k;
int list[MAX + 1];

int parition(int* arr, int low, int high) {
	int pivot_index = (high + low) / 2;
	int pivot_value = arr[pivot_index];
	swap(arr[high], arr[pivot_index]);
	int cnt = low;

	for (int i = low; i < high; i++)
		if (arr[i] < pivot_value)
			swap(arr[cnt++], arr[i]);
	swap(arr[cnt], arr[high]);
	return cnt;
}

int find_kth(int* arr, int low, int high, int k) {
	if (low <= high) {
		int pivot = parition(arr, low, high);
		if (pivot == k)
			return arr[k];
		else if (pivot > k)
			return find_kth(arr, low, pivot - 1, k);
		return find_kth(arr, pivot + 1, high, k);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> list[i];
	cout << find_kth(list, 0, n - 1, k - 1);
	return 0;
}