#include <cstdio>
#include <algorithm>
using namespace std;
int n, k, arr[20], visit[21];
long long per[21], cnt;

int main() {
	scanf("%d %d", &n, &k);

	per[0] = per[1] = 1;
	for (int i = 2; i <= n; i++)
		per[i] = per[i - 1] * i;

	if (k == 1) {
		scanf("%lld", &cnt);

		for (int i = 0; i < n; i++) {
			int j = 1;
			while (cnt > per[n-(i+1)] || visit[j]) {
				if (visit[j] == false)
					cnt -= per[n - (i+1)];
				j++;
			}
			arr[i] = j;
			visit[j] = true;
		}

		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
	} else {
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		for(int i=0;i<n;i++){
			int j = 1;
			while (j < arr[i]) {
				if (visit[j] == false)
					cnt += per[n - (i + 1)];
				j++;
			}
			visit[j] = true;
		}
		cnt++;

		printf("%lld", cnt);
	}
	return 0;
}