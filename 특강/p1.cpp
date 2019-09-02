#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int t;
int n, k;
int a[10000];

int main() {
	scanf("%d", &t);
	for (int testcase = 1; testcase <= t; testcase++) {
		scanf("%d %d", &n, &k);

		int cnt = 1;
		vector<pair<int, int>> arr;
		scanf("%d", &a[0]);
		for (int i = 1; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i - 1] == a[i]) cnt++;
			else {
				arr.push_back({ a[i - 1],cnt });
				cnt = 1;
			}
		}
		arr.push_back({ a[n - 1],cnt });

		int ans = 0;
		int len = arr.size();
		for (int i = 0; i < len; i++) {
			if (arr[i].first == 0) continue;

			int cnt = arr[i].second;

			//앞쪽 수를 샘
			int j = i - 1;
			while (j >= 0 &&
				(arr[j].first == 0 || arr[j].first == arr[i].first)) {
				cnt += arr[j].second;
				j--;
			}
			if (j != -1) {//앞에 0과 arr[i].first 가 아닌 수가 있는 경우
				cnt -= (arr[i].first - arr[j].first - 1);
			} else {//앞에 수가 없는 경우 없는 수를 채워넣어야 함
				cnt -= (arr[i].first - 1);
			}

			//뒤쪽 수를 샘
			j = i + 1;
			while (j < len &&
				(arr[j].first == 0 || arr[j].first == arr[i].first)) {
				cnt += arr[j].second;
				j++;
			}
			if (j != len) {//앞에 0과 arr[i].first 가 아닌 수가 있는 경우
				cnt -= (arr[j].first - arr[i].first - 1);
			} else {//앞에 수가 없는 경우 없는 수를 채워넣어야 함
				cnt -= (k - arr[i].first);
			}
			ans = max(ans, cnt);
		}
		if (ans == 0) ans = n - k + 1;
		printf("#%d %d\n",testcase, ans);
	}

	return 0;
}
