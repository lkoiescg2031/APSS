#include <bits/stdc++.h>
using namespace std;

#define parent first
#define val second

int n; string s;

pair<int,int> num[11], temp[11];
char op[11];
bool visit[11];

int calc(int x, int y, char op){
  switch(op){
    case '+': return x + y;
    case '-': return x - y;
    case '*': return x * y;
  }
  cout << "op error\n";
  return -1;
}

int find(int i){
  if( i == temp[i].parent ) return i;
  return temp[i].parent = find( temp[i].parent );
}

int get_ret(){
  for(int i = 1; i <= ( n / 2 ); i++)
    if(visit[i]) {
      int x = find(i - 1), y = find(i);
      int res = calc(temp[x].val, temp[y].val, op[i]);
      temp[x].parent = y;
      temp[y].val = res;
    }
  
  for(int i = 1; i <= ( n / 2 ); i++)
    if(!visit[i]) {
      int x = find(i - 1), y = find(i);
      int res = calc(temp[x].val, temp[y].val, op[i]);
      temp[x].parent = y;
      temp[y].val = res;
    }
  return temp[find(1)].val;
}

inline void numcpy(pair<int,int> *src, pair<int,int> *des, int size){
  for(int i = 0; i <= size; i++) des[i] = src[i];
}

int go(int depth){
  int ret = -0x3f3f3f3f;
  if(depth > n / 2) {
    numcpy(num, temp, n / 2);
    ret = get_ret();
    return ret;
  } 
  if(!visit[depth - 1]){
    visit[depth] = true;
    ret = go(depth + 1);
    visit[depth] = false;
  }
  return max(ret, go(depth + 1));
}

int main (){
  cin >> n >> s;
  num[0] = { 0, s[0] - '0' };
  for(int i = 1; i <= (n / 2); i++){
    num[i] = { i, s[i * 2] - '0' };
    op[i] = s[i * 2 - 1];
  }
  cout << go(1);
  return 0;
}