#include <bits/stdc++.h>
using namespace std;

int a[9], ans;
int main (){
  for(int i = 0; i < 9; i++){
    cin >> a[i];
    if(a[ans] < a[i]) ans = i;
  }
  cout << a[ans] << endl << ans + 1;
  return 0;
}