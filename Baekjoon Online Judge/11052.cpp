#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define MAX 1000

int N;
int price[MAX + 1];
int DP[MAX + 1];

int main() {
	
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, N)cin >> price[i+1];

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= i; j++) 
			DP[i] = max(DP[i], DP[i - j] + price[j]);
		
	cout << DP[N];

	return 0;
}