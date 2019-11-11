#include <bits/stdc++.h>
using namespace std;

int T,N,a[5000001];

int main (){

  scanf("%d",&T);

  for(int t=1;t<=T;t++){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%1d",&a[i]);

    int len = N / 2 + (N & 1), temp = 0 , ans = 0;
    for(int i=0;i<len;i++) temp += a[i];
    for(int i=0;i+len<=N;i++) ans = max(ans,temp), temp += a[i+len]-a[i];

    printf("Case #%d: %d\n",t,ans);
  }

  return 0;
}