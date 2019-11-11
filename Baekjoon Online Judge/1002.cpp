#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using point = pair<int,int>;
#define X first
#define Y second

inline LL sq(LL s){
  return s*s;
}

inline LL dist(point& a, point& b){
  return sq(b.X - a.X) + sq(b.Y - a.Y);
}

int t,r1,r2;
point a,b;

int main (){
  scanf("%d",&t);
  while(t--){
    scanf("%d %d %d %d %d %d",&a.X,&a.Y,&r1,&b.X,&b.Y,&r2);
    LL d = dist(a,b);
    LL r1r2 = sq(r1+r2);
    LL r1r2sub = sq(r2-r1);
    if(a.X == b.X && a.Y == b.Y && r1==r2) printf("-1\n");
    else if(r1r2 < d) printf("0\n");
    else if(r1r2 == d) printf("1\n");
    else if(d == r1r2sub) printf("1\n");
    else if(d < r1r2sub) printf("0\n");
    else printf("2\n");
  }
  return 0;
}