#include <bits/stdc++.h>
using namespace std;

int T,n;
int x, y,x2,y2;
int rx,ry,rr;
int ans;

int main (){

  scanf("%d",&T);

  while(T-- > 0){
    ans = 0;
    scanf("%d %d %d %d",&x,&y,&x2,&y2);
    scanf("%d",&n);
    while(n-- > 0){
      scanf("%d %d %d",&rx,&ry,&rr);
      int tempR = rr*rr;
      int lineR1 = (rx - x)*(rx - x) + (ry - y)*(ry - y);
      int lineR2 = (rx - x2)*(rx - x2) + (ry - y2)*(ry - y2);
      if(lineR1 < tempR && lineR2 < tempR){
        continue;
      }else if(lineR1 < tempR || lineR2 < tempR){
        ans++;
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}