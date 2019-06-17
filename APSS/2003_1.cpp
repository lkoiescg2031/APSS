#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, arr[10000];

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);

	int l=0 ,r = 0;
	long long sum = arr[0], ans = 0;
	while (l <= r && r < n) {
		if (sum == m) ans++;
		if (sum <= m) sum += arr[++r];//������� �⺻ ������ l<=r �̹Ƿ�  r�� ����
		else {
			sum -= arr[l++];
			if (l > r && l < n) {//�Ѽ��ڸ� �ִµ� m���� ū��� l>r�� ��
				r = l;
				sum = arr[l];
			}
		}
	}

	printf("%lld", ans);
	return 0;
}