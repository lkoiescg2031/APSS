#include <cstdio>
using namespace std;
class Set {
private:
	int s;
public:
	Set(): s(0) {}
	void add(int x) {
		x--;
		s |= (1 << x);
	}
	void remove(int x) {
		x--;
		s &= ~(1 << x);
	}
	int check(int x) {
		x--;
		return s & (1 << x) ? 1 : 0;
	}
	void toggle(int x) {
		x--;
		s^=(1 << x);
	}
	void all(int x) {
		s = (1 << x) - 1;
	}
	void empty() {
		s = 0;
	}
};
int main() {
	int n, k;
	char str[111];
	Set s;
	scanf("%d", &n);
	while (n-- > 0) {
		scanf("%s", str);
		if (str[1] != 'l' && str[1] != 'm')
			scanf("%d", &k);
		switch (str[1]) {
		case 'd':
			s.add(k);
			break;
		case 'e':
			s.remove(k);
			break;
		case 'h':
			printf("%d\n", s.check(k));
			break;
		case 'o':
			s.toggle(k);
			break;
		case 'l':
			s.all(20);
			break;
		case'm':
			s.empty();
			break;
		}
	}
	return 0;
}