#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int n, m;
int arr[41];

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	int mid = n / 2;
	int last1 = 1 << mid;
	vector<int> subsum1(last1);
	for (int i = 0; i < last1; i++) 
		for (int j = 0; j < mid; j++) 
			if ((i & (1 << j)) != 0) subsum1[i] += arr[j+1];

	int last2 = 1 << (n - mid);
	vector<int> subsum2(last2);
	for (int i = 0; i < last2; i++)
		for (int j = 0; j < (n - mid); j++)
			if ((i & (1 << j)) != 0) subsum2[i] += arr[mid + j+1];

	sort(begin(subsum1), end(subsum1));
	sort(begin(subsum2), end(subsum2), greater<>());
	
	int i = 0, j = 0;
	long long ans = 0;
	while (i < last1 && j < last2) {
		if (subsum1[i] + subsum2[j] == m) {
			long long c1 = 1;
			long long c2 = 1;
			i++, j++;
			while (i < last1 && subsum1[i] == subsum1[i - 1]) i++, c1++;
			while (j < last2 && subsum2[j] == subsum2[j - 1]) j++, c2++;
			ans += c1 * c2;
		} else if (subsum1[i] + subsum2[j] > m) j++;
		else i++;
	}
	if (m == 0) ans -=1;//공집합 제거
	printf("%lld", ans);

	return 0;
}