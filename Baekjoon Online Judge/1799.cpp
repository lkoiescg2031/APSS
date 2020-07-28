#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define Loop(i,j,k) for(int i=(j);i<(k);i++)

inline bool inRange(int k,int i,int j) {
  return k >= i && k < j; 
}

int N,chess[10][10];
bool isNight[10][10];

void next_point(int& i,int& j,int minj,int maxj){
  j++;
  if(maxj == j) i++, j = minj;
}

void prev_point(int& i,int& j,int minj,int maxj){
  j--;
  if(j < minj) i--, j = maxj - 1;
}

bool isCan(int x,int y){
  static const int dx[] = {-1, 1, -1, 1}, dy[] = {-1, -1, 1, 1};

  Loop(i,0,4){
    int nx = x + dx[i], ny = y + dy[i];
    while(inRange(nx,0,N) && inRange(ny,0,N)){
      if(isNight[nx][ny]) return false;
      nx += dx[i], ny += dy[i];
    }
  }
  return true;
}

int go(int night_cnt,int x,int y){
  
  int ret = 0;
  
  // 현제 채스를 놓을 수 있는 최초의 값
  while( x < N && !(chess[x][y] && isCan(x,y))) next_point(x, y, 0, N);
  
  // 종료 조건
  if(x >= N) return night_cnt;
  
  //체스 말을 놓는 경우
  isNight[x][y] = true; next_point(x, y, 0, N);
  ret = go(night_cnt + 1, x, y);
  prev_point(x, y, 0, N); isNight[x][y] = false;
  
  //놓지않는 경우
  next_point(x,y,0,N);
  ret = max(ret,go(night_cnt,x,y));
  
  return ret;
}

int main () {
  //freopen("c:/github/APSS/Baekjoon Online Judge/build/input.txt","r",stdin);
  ios::sync_with_stdio(true);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  Loop(i,0,N) Loop(j,0,N) cin >> chess[i][j];  

  cout << go(0, 0, 0);

  return 0;
}