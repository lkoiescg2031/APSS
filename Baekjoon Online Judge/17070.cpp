#include <bits/stdc++.h>
using namespace std;

vector<int> dx[3], dy[3];
#define row 0
#define col 1
#define cross 2
int x, y;

int n;
int bitmap[17][17];
int d[17][17][3];

int main (){
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> bitmap[i][j];
  
  d[0][1][row] = 1;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      if(!bitmap[i][j + 1]) {
        d[i][j+1][row] += d[i][j][row];
        d[i][j+1][row] += d[i][j][cross];
      }
      if(!bitmap[i][j + 1] && !bitmap[i + 1][j + 1] && !bitmap[i + 1][j]){
        d[i + 1][j + 1][cross] += d[i][j][row];
        d[i + 1][j + 1][cross] += d[i][j][col];
        d[i + 1][j + 1][cross] += d[i][j][cross];
      } 
      if(!bitmap[i + 1][j]) {
        d[i + 1][j][col] += d[i][j][col];
        d[i + 1][j][col] += d[i][j][cross];
      }
    }
  cout << d[n - 1][n - 1][row] + d[n - 1][n - 1][col] + d[n - 1][n - 1][cross];
  return 0;
}