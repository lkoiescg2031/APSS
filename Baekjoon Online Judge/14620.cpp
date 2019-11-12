#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 1, 0, -1 }, x;
int dy[] = { 1, 0, -1, 0 }, y;

int n, bitmap[10][10], visit[10][10];

bool isCan(int i,int j){
  bool ret = true;
  if(visit[i][j]) ret = false;
  visit[i][j] = !visit[i][j];
  for(int k = 0; k< 4; k++){
    int mx = i + dx[k], my = j + dy[k];
    if(mx < 0 || mx >= n || my < 0 || my >= n) {
      ret = false;
      continue;
    }
    if(visit[mx][my]) ret = false;
    visit[mx][my] = !visit[mx][my];
  }
  return ret;
}
int dfs(int depth){
  int ret = 0x3f3f3f3f;
  if(depth == 3){
    ret = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(visit[i][j]) ret += bitmap[i][j];
      }
    }
    return ret;
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      if(isCan(i,j)) ret = min(ret,dfs(depth+1));
      isCan(i,j);
    }    
 
  return ret;
}

int main (){
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0 ; j < n; j++)
      cin >> bitmap[i][j];

  cout << dfs(0);
  return 0;
}