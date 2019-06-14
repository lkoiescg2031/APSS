//=======================================================================
//��������
//Topological Sort
#include <queue>
using namespace std;
int n;
vector<int> indegree;
vector<vector<int>> graph;


void Topological_Sort() {
	//�ʱ�ȭ
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (indegree[i] == 0)
			q.push(i);

	//bfs�� ������ ������� Ž��
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
