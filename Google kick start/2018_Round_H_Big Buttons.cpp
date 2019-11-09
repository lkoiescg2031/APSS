#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T, N, P;
struct A{
	string s;
	bool isCnt;
}arr[100];

int main() {

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> P;
		for (int i = 0; i < P; i++) 
			cin >> arr[i].s,arr[i].isCnt = true;

		unsigned long long ans = 1ll << N;
			
		for (int i = 0; i < P; i++) {
			auto& is = arr[i].s;
			if (!arr[i].isCnt) continue;
			for (int j = 0; j < P; j++) {
				auto& js = arr[j].s;
				if (!arr[j].isCnt || i == j || is.size() >= js.size()) continue;
				bool isSame = true;
				for (int k = 0; k < is.size(); k++)
					if (is[k] != js[k]) {
						isSame = false;break;
					}
				if(isSame) arr[j].isCnt = false;
			}
		}

		for (int i = 0; i < P; i++) 
			if(arr[i].isCnt) ans -= 1ll << (N - arr[i].s.size());
			
		cout << "Case #" << t << ": " << max(ans,0ull) << endl;
	}
	return 0;
}