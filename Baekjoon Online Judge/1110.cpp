#include <cstdio>

int main (){
  int a,t1 = -1,t2,cnt=0;
  scanf("%d", &a);
  t1 = a;
  do {
    t2 = t1;
    t1 = (t2 % 10) * 10 + (t2 / 10 + t2 % 10) %  10;
    cnt++;
  } while(a != t1);
  printf("%d",cnt);
  return 0;
}