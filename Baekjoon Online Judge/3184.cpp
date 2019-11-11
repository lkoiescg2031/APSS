#include <bits/stdc++.h>
using namespace std;

#define SH first
#define WO second
#define Sh 'o'
#define Wo 'v'

int dx[] = { 0, 1, 0, -1 }, x;
int dy[] = { 1, 0, -1, 0 }, y;

int R,C, visit[250][2500];
string bitmap[250];

pair<int,int> bfs(int sx, int sy){
  pair<int,int> ret;

  queue<pair<int,int>> q;
  q.push({sx, sy}),visit[sx][sy] = true;

  while(!q.empty()){

    tie(x,y) = q.front(), q.pop();
    if(bitmap[x][y] == Wo) ret.WO++;
    else if(bitmap[x][y] == Sh) ret.SH++;

    for(int i=0;i<4;i++){
      int mx = x + dx[i], my = y + dy[i];
      if(mx >= 0 && mx < R && my >= 0 && my < C &&
        !visit[mx][my] && bitmap[mx][my] != '#') visit[mx][my] = true, q.push({mx,my});
    } 
  }
  return ret;
}

int main (){

  cin >> R >> C;
  for(int i = 0; i < R; i++)
    cin >> bitmap[i];

  pair<int,int> ans;
  for(int i = 0; i < R; i++)
    for(int j = 0; j < C; j++){
      if(visit[i][j] || bitmap[i][j] == '#') continue;
      auto ret = bfs(i,j);
      if(ret.SH > ret.WO) ans.SH += ret.SH;
      else ans.WO += ret.WO;
    }
  
  cout << ans.SH << " " << ans.WO;

  return 0;
}