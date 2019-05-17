#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int l, c;
char ch[15];

bool check(const string& str) {
	int mo = 0, za = 0;
	for (auto i : str)
		if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') mo++;
		else za++;
	return mo > 0 && za > 1;
}
void print(int i, string str) {
	if (str.length() == l) {
		if (check(str)) printf("%s\n", str.c_str());
		return;
	}
	if (i >= c) return;
	print(i + 1, str + ch[i]);
	print(i + 1, str);
}
int main() {
	scanf("%d %d\n", &l, &c);
	for (int i = 0; i < c; i++)scanf(" %c", &ch[i]);
	sort(ch, ch + c);
	print(0, string());
	return 0;
}