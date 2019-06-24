#include <cstdio>

int n;
int arr[500000], temp[500000];
long long ans;

void merge_sort(int s, int m, int e) {
	int i = s;
	int j = m + 1;
	int k = s;
	while (i <= m && j <= e) {
		if (arr[i] <= arr[j]) temp[k++] = arr[i++];
		else {
			ans += m - i + 1;
			temp[k++] = arr[j++];
		}
	}
	while (i <= m)temp[k++] = arr[i++];
	while (j <= e) temp[k++] = arr[j++];
	for (int l = s; l < k; l++)
		arr[l] = temp[l];
}
void merge(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge(start, mid);
		merge(mid + 1, end);
		merge_sort(start, mid, end);
	}
}
/* ans 범위 계산*/
int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	merge(0, n-1);
	printf("%lld", ans);
	return 0;
}