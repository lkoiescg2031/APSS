//=======================================================================
//위상정렬
//Topological Sort
#include <queue>
using namespace std;
int n;
vector<int> indegree;
vector<vector<int>> graph;


void Topological_Sort() {
	//초기화
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (indegree[i] == 0)
			q.push(i);

	//bfs와 유사한 방법으로 탐색
	for (int i = 0; i < n; i++) {
		int cur = q.front();
		q.pop();
		//do here
		printf("%d ", cur);
		//=========
		for (auto next : graph[cur]) {
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}
}
//========================================================================
