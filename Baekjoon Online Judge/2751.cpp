#include <iostream>
#include <string>
using namespace std;
#define MAX 1000000

int arr[MAX];

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition(int * arr, int low, int high) {
	int mid = low + (high - low) / 2;
	int pivot = arr[mid];
	int cnt = low;

	swap(arr[mid], arr[high]);
	for (int i = low; i < high; i++) 
		if (arr[i] < pivot) 
			swap(arr[i], arr[cnt++]);

	swap(arr[cnt], arr[high]);

	return cnt;
}

void quick_sort(int *arr, int low, int high) {
	if(low < high){
		int pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	int n;
	string ans;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	quick_sort(arr, 0, n-1);
	
	for (int i = 0; i < n; i++)
		ans += to_string(arr[i]) + "\n";

	cout << ans;
	return 0;
}