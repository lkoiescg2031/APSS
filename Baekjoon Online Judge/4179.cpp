#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 1, 0, -1 }, x;
int dy[] = { 1, 0, -1, 0 }, y;

#define WALL -1
#define EMPTY 0
#define HUN 1
#define FIRE -2

int R, C;
int bitmap[1000][1000];
vector<pair<int,int>> fire;
pair<int,int> hun;
queue<pair<int,int>> q;

int main (){
  char t;
  cin >> R >> C;
  for(int i = 0; i < R; i++)
    for(int j = 0; j < C; j++){
      cin >> t;
      if(t == '#') bitmap[i][j] = WALL;
      else if(t == 'F') bitmap[i][j] = FIRE, fire.emplace_back(i, j);
      else if(t == 'J') bitmap[i][j] = HUN, hun = {i, j};
    }

  for(auto i : fire) q.push({ i.first, i.second });
  q.push(hun);

  while(!q.empty()){
    tie(x,y) = q.front(), q.pop();
    if(bitmap[x][y] > 0 && (x == 0 || x == R - 1 || y == 0 || y == C - 1)){
      cout << bitmap[x][y];
      return 0;
    }
    for(int i = 0; i < 4; i++){
      int mx = x + dx[i], my = y + dy[i];
      if( mx >= 0 && mx < R && my >= 0 && my < C && bitmap[mx][my] == EMPTY){
        bitmap[mx][my] = bitmap[x][y] == FIRE ? FIRE : bitmap[x][y] + 1;
        q.push({ mx, my });
      }
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}