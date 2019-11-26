#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(i,j,k) for(int i = (j); i < (k); i++)

bool inRange(int a,int i,int j){
  return a >= 0 && a < j;
}

using point = pair<int,int>;
#define X first
#define Y second

int R, C;
int bitmap[50][50];

#define INF 0x3f3f3f3f

int dx[] = { 0, 1, 0, -1 }, x, mx;
int dy[] = { 1, 0, -1, 0 }, y, my;

queue<pair<int,int>> q;
point dst, src;

int main (){

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  char t;
  cin >> R >> C;
  FOR(i,0,R) FOR(j,0,C){
    cin >> t;
    if( t == '*' ) q.push({ i, j }), bitmap[i][j] = -1;
    else if( t == 'X' ) bitmap[i][j] = INF;
    else if( t == 'S' ) src = { i, j };
    else if( t == 'D' ) dst = {i,j};
  }

  q.push(src); bitmap[src.X][src.Y] = 1;
  
  while(!q.empty()){
    tie(x,y) = q.front();
    q.pop();
    FOR(i, 0, 4){
      mx = x + dx[i], my = y + dy[i];
      if( inRange(mx, 0, R) && inRange(my, 0, C) && bitmap[mx][my] == 0){
        if(bitmap[x][y] < 0) {
          if(mx == dst.X && my == dst.Y) continue;
          bitmap[mx][my] = bitmap[x][y] - 1;
        }else bitmap[mx][my] = bitmap[x][y] + 1;
        q.push({ mx, my });
      }
    }
  }
  if(bitmap[dst.X][dst.Y] == 0) cout << "KAKTUS" << endl;
  else cout << bitmap[dst.X][dst.Y] - 1 << endl;

  return 0;
}