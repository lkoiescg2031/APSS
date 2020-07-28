#include <bits/stdc++.h>
using namespace std;

int A,B,C;
long ans[10];

int main (){
  scanf("%d %d %d",&A,&B,&C);

  long temp = A*B*C;

  while(temp > 0){
    ans[temp % 10]++;
    temp/=10;
  }

  for(int i = 0; i < 10; i++){
    printf("%d\n",ans[i]);
  }
  return 0;
}