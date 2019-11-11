#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1}, x;
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1}, y;
 
int H,W, visit[1000][1000], high[1000][1000];
string bitmap[1000];
queue<pair<int,int>> q;

int main (){
  cin >> H >> W;
  for(int i=0;i<H;i++) cin >> bitmap[i];
  
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++){
      if(bitmap[i][j] == '.') continue;
      high[i][j] = bitmap[i][j] - '0';
    }
  
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++){
      if(high[i][j] == 9 || high[i][j] == 0) continue;
      visit[i][j] = true;
      for(int k=0;k<8;k++){
        int mx = i + dx[k], my = j + dy[k];
        if( mx >= 0 && my >= 0 && mx < H && my < W && !visit[mx][my] && high[mx][my] == 0) high[i][j]--;
        if(high[i][j] == 0) {
          q.push({ i, j });
          break; 
        }
      }
    }

  int ans = 0;
  while(!q.empty()){
    int qSize = q.size();
    for(int i = 0; i < qSize; i++){
      tie(x,y) = q.front(),q.pop();
      for(int j = 0; j < 8; j++){
        int mx = x + dx[j], my = y + dy[j];
        if( mx >= 0 && my>= 0 && mx < H && my < W && high[mx][my] != 9 && high[mx][my] > 0){
          high[mx][my]--;
          if(high[mx][my] == 0) q.push({ mx, my }); 
        }
      }
    }
    ans++;
  }
  cout << ans;
  return 0;
}