#include <bits/stdc++.h>
using namespace std;

int main (){
  int A,B,V;
  scanf("%d %d %d",&A,&B,&V);
  printf("%d", 1 + (V - B - 1) / (A - B));
  return 0;
}