#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, arr[500000], k;

int find(int start, int end, int key) {
	if (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == key)
			return 1;
		else if (arr[mid] > key)
			return find(start, mid - 1, key);
		else
			return find(mid + 1, end, key);
	}
	return 0;
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		printf("%d ", find(0, n, k));
	}

	return 0;
}