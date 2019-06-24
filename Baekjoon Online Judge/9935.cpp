#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

char str[1000001], explo[37];
int slen, elen;
deque<int> stack;

int main() {

	scanf("%s %s", str, explo);
	slen = strlen(str);
	elen = strlen(explo);

	for (int i = 0; i < slen; i++) {
		stack.push_back(str[i]);
		int len = stack.size();
		if (len >= elen) {
			int cnt = 0;
			for (; cnt < elen; cnt++)
				if (explo[cnt] != stack[len - elen + cnt])
					break;
			if (cnt == elen)
				for (int i = 0; i < elen; i++)
					stack.pop_back();
		}
	}

	if (stack.size() == 0)
		printf("FRULA");
	for (int i = 0; i < stack.size(); i++)
		printf("%c", stack[i]);

	return 0;
}