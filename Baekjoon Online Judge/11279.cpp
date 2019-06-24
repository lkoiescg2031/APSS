#include <cstdio>
#include <cstdlib>

int n;
int a[100001], size;

inline void swap(int& a, int& b) {
	int t = a;a = b; b = t;
}

void push_heap(int x) {

	if (size + 1 >= 100001) exit(-1);

	a[++size] = x;
	int child = size;
	while (child > 1) {
		int parent = child / 2, t;
		if (a[parent] >= a[child]) break;
		swap(a[parent], a[child]);
		child = parent;
	}
	return;
}

int pop_heap() {
	int parent = 1;
	if (size < 1) return 0;
	swap(a[parent], a[size]);
	size--;
	while (2 * parent <= size) {//자식이 있을 때 까지
		int left = parent * 2;
		int right = left + 1;
		if (right > size) { // 자식이 하나만 있는경우
			if (a[parent] < a[left]) swap(a[parent], a[left]);
			break;
		}else{ //자식이 둘 있는 경우
			if (a[parent] > a[left] && a[parent] > a[right])
				break;
			else if (a[left] > a[right]) {
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
	size = 0;
	
	while (n-- > 0) {
		int x;
		scanf("%d", &x);
		if (x == 0) printf("%d\n", pop_heap());
		else push_heap(x);		
	}
	return 0;
}