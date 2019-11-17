#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main (){

  freopen("C:/github/apss/google kick start/build/input.txt", "r", stdin);

  int T, n;
  cin >> T;
  for(int tc = 1; tc <= T; tc++){
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int hIndex = 0;
    priority_queue<int> pq;
    cout << "Case #" << tc << ":";
    for(int i = 0; i < n; i++) {
      if(a[i] > hIndex) pq.push(-a[i]);
      while(!pq.empty() && -pq.top() <= hIndex) pq.pop();
      if(pq.size() > hIndex) hIndex++;
      cout << " " << hIndex;
    }
    cout << endl;
  }
  return 0;
}