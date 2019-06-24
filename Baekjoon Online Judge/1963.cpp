#include <cstdio>
#include <queue>
#include <memory.h>
#include <string>
using namespace std;

int t, a, b, np[10000], d[10000], flag, u, v;
char temp;

int main() {

	for (int i = 2; i < 10000; i++)
		if (np[i] == 0)
			for (int j = i * i; j < 10000; j += i)
				np[j] = true;

	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d %d", &a, &b);
		queue<int> q;
		bool flag = a != b;
		if (flag) q.push(a), memset(d, -1, sizeof(d));
		d[a] = 0;
		while (!q.empty() && flag) {
			u = q.front();
			string str = to_string(u);
			q.pop();
			for (int loc = 0; loc < 4 && flag; loc++) {
				temp = str[loc];
				for (char i = '0'; i <= '9' && flag; i++)
					if (i == '0' && loc == 0) continue;
					else if (i != temp) {
						str[loc] = i;
						v = stoi(str);
						if (!np[v] && d[v] == -1) {
							d[v] = d[u] + 1;
							q.push(v);
							if (v == b) flag = false;
						}
					}
				str[loc] = temp;
			}
		}
		if (flag) printf("Impossible\n");
		else printf("%d\n", d[b]);
	}

	return 0;
}