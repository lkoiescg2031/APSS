#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,N) for(int (i)=0;(i)<(N);(i)++)
#define MAX 1000

int N;
int num[MAX], dp_inc[MAX], dp_dec[MAX];
int ans;

int main() {

	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, N)cin >> num[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++)
			if (num[i] > num[j])
				dp_inc[i] = max(dp_inc[i], dp_inc[j]);
		dp_inc[i]++;
	}

	for (int i = N-1; i >=0; i--) {
		for (int j = N-1; j > i; j--)
			if (num[i] > num[j])
				dp_dec[i] = max(dp_dec[i], dp_dec[j]);
		dp_dec[i]++;
	}

	for(int i=0;i<N;i++)
		ans = max(ans, dp_inc[i] + dp_dec[i] - 1);

	cout << ans;

	return 0;
}