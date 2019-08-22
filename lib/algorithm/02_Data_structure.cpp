//==========================================================================
//uion-find (disjoint set)
#include <vector>
using namespace std;

vector<int> parent;

void init(int size) {
	parent = vector<int>(size);
	for (int i = 0; i < size; i++) parent[i] = i;
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	int xparent = find(x);
	int yparent = find(y);

	if (xparent == yparent) return;
	parent[xparent] = yparent;
}
//============================================================================