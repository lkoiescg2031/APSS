#include <cstdio>

int d[41][2],n,t;

int main (){
  d[0][0] = d[1][1] = 1;
  for(int i=2;i<=40;i++)
    d[i][0] = d[i-1][0] + d[i-2][0], d[i][1] = d[i-1][1] + d[i-2][1];
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    printf("%d %d\n",d[n][0],d[n][1]);
  }  
  return 0;
}