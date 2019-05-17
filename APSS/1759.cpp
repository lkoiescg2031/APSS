#include <cstdio>
#include <algorithm>
using namespace std;

int l, c, visit[15];
char ch[15];

void print(int recur,int start, int mo, int za) {
	if (recur == l) {
		if (mo > 0 && za > 1) {
			for (int i = 0; i < c; i++)
				if (visit[i] != 0) printf("%c", ch[i]);
			printf("\n");
		}
		return;
	}

	int last = c - l + recur;
	for (int i = start ; i <= last; i++) {
		visit[i] = true;
		if (ch[i] == 'a' || ch[i] == 'i' || ch[i] == 'e' || ch[i] == 'o' || ch[i] == 'u') print(recur + 1, i + 1, mo + 1, za);
		else print(recur + 1, i + 1, mo, za + 1);
		visit[i] = false;
	}
}

int main() {
	
	scanf("%d %d\n", &l, &c);
	for (int i = 0; i < c; i++) scanf(" %c", &ch[i]);
	sort(ch, ch + c);
	print(0, 0, 0, 0);
	return 0;
}