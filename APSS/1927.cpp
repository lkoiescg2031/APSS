#include <cstdio>
#include <cstdlib>
int n, a[100001], size;

inline void swap(int& a, int& b) {
	int t = a; a = b; b = t;
}

void push(int x) {

	int child;

	if (size + 1 >= 100001) exit(-1);
	a[++size] = x;
	child = size;
	while (child > 1) {
		int parent = child / 2;
		if (a[parent] <= a[child]) break;
		swap(a[parent], a[child]);
		child = parent;
	}
	return;
}

int pop() {
	int parent = 1;
	if (size < 1) return 0;
	swap(a[parent], a[size]);
	size--;
	while (parent * 2 <= size) {
		int left = parent * 2;
		int right = left + 1;
		if (right > size) {
			if (a[parent] > a[left]) swap(a[parent], a[left]);
			break;
		} else {
			if (a[parent] <= a[left] && a[parent] <= a[right])
				break;
			else if (a[left] < a[right]) {
				swap(a[parent], a[left]);
				parent = left;
			} else {
				swap(a[parent], a[right]);
				parent = right;
			}
		}
	}
	return a[size + 1];
}

int main() {

	scanf("%d", &n);
	while (n-- > 0) {
		int x;
		scanf("%d", &x);
		if (x == 0) printf("%d\n", pop());
		else push(x);
	}
	return 0;
}