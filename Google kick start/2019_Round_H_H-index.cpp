#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T, n;

void insert(vector<int>& arr,int index){
  while(index > 0){
    if(arr[index] <= arr[index - 1]) break;
    swap(arr[index], arr[index - 1]);
    index--;
  }
}

int main (){

  freopen("C:/github/apss/google kick start/build/input.txt", "r", stdin);

  cin >> T;
  for(int tc = 1; tc <= T; tc++){
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
      cin >> a[i];

    cout << "Case #" << tc << ":";
    for(int i = 0; i < n; i++) {
      int ans = i + 1;
      insert(a,i);
      
      for(int j = 0; j <= i; j++)
        if(j >= a[j]){ ans = j; break; }
      cout << " " << ans;
    }
    cout << endl;
  }
  return 0;
}