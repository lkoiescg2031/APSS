#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
using iint = pair<int, int>;

int n;
vector<int> a;
vector<iint> a1;
vector<iint> tree;

iint query(int node, int b, int e, int i, int j) {
	if (e < i || j < b) return { 0 , -1 };
	if (i <= b && e <= j) return tree[node];
	return max(query(node * 2, b, (b + e) / 2, i, j),
		query(node * 2 + 1, (b + e) / 2 + 1, e, i, j));
}

void update(int node, int b, int e, int i, iint v) {
	if (e < i || i < b) return;
	tree[node] = max(tree[node], v);
	if (b != e) {
		update(node * 2, b, (b + e) / 2, i, v);
		update(node * 2 + 1, (b + e) / 2 + 1, e, i, v);
	}
}

int main() {

	scanf("%d", &n);
	a.resize(n);
	for (auto& i : a) scanf("%d", &i);

	//��ǥ ����
	map<int, int> c;
	vector<int> b = a;//������ ���� ����
	sort(begin(b), end(b));//����
	b.erase(unique(begin(b), end(b)), end(b));//�ߺ� ����
	int terminal_node_size = b.size();
	for (int i = 0; i < terminal_node_size; i++) c[b[i]] = i + 1;//��ǥ ����
	a1.resize(n);
	for (int i = 0; i < n; i++) a1[i] = { c[a[i]],a[i] };//������ ���� �迭 first : ����Ȱ�, second : ���� ��

	int h = ceil(log2(terminal_node_size));
	int tree_size = 1 << (h + 1);
	tree.resize(tree_size, { 0,-1 });

	int ans_index = -1;
	vector<iint> d(n, { 0,-1 });
	for (int i = 0; i < n; i++) {
		d[i] = query(1, 1, terminal_node_size, 1, a1[i].first - 1); d[i].first++;
		if (ans_index == -1 || d[ans_index].first < d[i].first) ans_index = i;
		update(1, 1, terminal_node_size, a1[i].first, { d[i].first,i });
	}
	stack<int> s;
	for (int i = ans_index; i != -1; i = d[i].second)
		s.push(a1[i].second);

	printf("%d\n", s.size());
	while (!s.empty()) printf("%d ", s.top()), s.pop();

	return 0;
}