#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

int limit[3];
int visit[201][201];
int ans[201];

int main() {

	scanf("%d %d %d", &limit[0], &limit[1], &limit[2]);

	queue<pair<int, int>> q;
	visit[0][0] = true;
	ans[limit[2]] = true;
	q.push({ 0,0 });

	while (!q.empty()) {
		int bottle[3];
		tie(bottle[0], bottle[1]) = q.front();
		bottle[2] = limit[2] - bottle[0] - bottle[1];
		q.pop();
		for (int from = 0; from < 3; from++)
			for (int to = 0; to < 3; to++)
				if (from != to && bottle[from] > 0 && bottle[to] < limit[to]) {
					int move = min(bottle[from], limit[to] - bottle[to]);
					bottle[from] -= move;
					bottle[to] += move;
					int& check = visit[bottle[0]][bottle[1]];
					if (!check) {
						check = true;
						q.push({ bottle[0],bottle[1] });
						if (bottle[0] == 0) ans[bottle[2]] = true;
					}
					bottle[from] += move;
					bottle[to] -= move;
				}
	}

	for (int i = 0; i <= limit[2]; i++) {
		if (ans[i]) printf("%d ", i);
	}

	return 0;
}