#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int v, e, s;
vector<int> adj[MAX + 1];
int visit[MAX + 1];

void dfs(int start) {

  stack<pair<int,int>> s;
  s.push({start,0});

  while(!s.empty()){

    int cur = s.top().first;

		if( visit[cur] && adj[cur].size() == s.top().second){ 
			s.pop(); 
			continue;
		}

		if(s.top().second == 0){
    	cout << cur << " ";
			visit[cur] = true;
		}

		for(int& i = s.top().second;i<adj[cur].size();i++){
			int next = adj[cur][i];
			if(!visit[next]){
				s.top().second++;
				s.push({next,0});
				break;
			}
		}
  }
}

void bfs(int start) {
	
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (visit[cur] == true) continue;

		cout << cur << " ";
		visit[cur] = true;

		for (auto i : adj[cur]) 
			if (!visit[i]) 
				q.push(i);
	}
}

int main() {

	cin >> v >> e >> s;
	for (int i = 0; i < e; i++) {
		int begin, end;
		cin >> begin >> end;
		adj[begin].push_back(end);
		adj[end].push_back(begin);
	}
	for (int i = 0; i < v; i++)
		sort(begin(adj[i]), end(adj[i]));
	memset(visit, 0, sizeof(visit));
	dfs(s);
	cout << endl;
	memset(visit, 0, sizeof(visit));
	bfs(s);
	return 0;
}