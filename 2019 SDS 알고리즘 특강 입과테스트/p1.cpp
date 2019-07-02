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

			//���� ���� ��
			int j = i - 1;
			while (j >= 0 &&
				(arr[j].first == 0 || arr[j].first == arr[i].first)) {
				cnt += arr[j].second;
				j--;
			}
			if (j != -1) {//�տ� 0�� arr[i].first �� �ƴ� ���� �ִ� ���
				cnt -= (arr[i].first - arr[j].first - 1);
			} else {//�տ� ���� ���� ��� ���� ���� ä���־�� ��
				cnt -= (arr[i].first - 1);
			}

			//���� ���� ��
			j = i + 1;
			while (j < len &&
				(arr[j].first == 0 || arr[j].first == arr[i].first)) {
				cnt += arr[j].second;
				j++;
			}
			if (j != len) {//�տ� 0�� arr[i].first �� �ƴ� ���� �ִ� ���
				cnt -= (arr[j].first - arr[i].first - 1);
			} else {//�տ� ���� ���� ��� ���� ���� ä���־�� ��
				cnt -= (k - arr[i].first);
			}
			ans = max(ans, cnt);
		}
		if (ans == 0) ans = n - k + 1;
		printf("#%d %d\n",testcase, ans);
	}

	return 0;
}
