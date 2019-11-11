#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int dx[] = {0,1,0,-1}, x;
int dy[] = {1,0,-1,0}, y;

int N,M, bitmap[300][300], visit[300][300];
queue<pair<int,int>> q;

void initvisit(){
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      visit[i][j]=0;
}

bool isSep(int sx,int sy){
  int cnt = 0, target = q.size();

  initvisit();
  queue<pair<int,int>> subq;  
  visit[x][y] = true, subq.push({sx,sy});

  while(!subq.empty()){
    tie(x,y) = subq.front(), subq.pop();
    cnt++;
    for(int i=0;i<4;i++){
      int mx = x + dx[i], my = y + dy[i];
      if(mx>=0 && my>=0 && mx<N && my<M && 
        !visit[mx][my] && bitmap[mx][my] ) visit[mx][my] = true, subq.push({mx,my});
    }
  }

  return cnt != target;
}

int main(){

  cin >> N >> M;

  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++){
      cin >> bitmap[i][j];
      if(bitmap[i][j]) q.push({i,j});
    }

  int years = 0;
  while(true){    
    //simulate
    initvisit();
    years++;
    int qSize = q.size();
    for(int i = 0; i < qSize; i++){
      tie(x,y) = q.front(),q.pop();
      visit[x][y] = true;
      for(int j=0;j<4;j++){
        int mx = x + dx[j];
        int my = y + dy[j];
        if(mx >= 0 && mx < N && my >= 0 && my < M &&
          !visit[mx][my] && !bitmap[mx][my] && bitmap[x][y] > 0) bitmap[x][y]--;
      }
      if(bitmap[x][y]) q.push({x,y});
    }

    //check
    if(q.size() == 0) break;
    tie(x,y) = q.front();
    if(isSep(x,y)){
      cout << years << endl;
      return 0;
    }
  }

  cout << 0 << endl;
  return 0;
}