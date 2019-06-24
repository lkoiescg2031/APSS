#include<iostream>
using namespace std;

#define MAX 1000

int N, K,ans;
int np[MAX + 1];

int main() {

	np[0] = np[1] = 1;
	for (int i = 2; i <= MAX; i++) {
		if (np[i] == 0) {
			for (int j = i * i; j <= MAX; j += i)
				np[j] = 1;
		}
	}

	cin >> N;
	while (N-- > 0) {
		cin >> K;
		ans += np[K] == 0;
	}
	cout << ans;
	return 0;
}