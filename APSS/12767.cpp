#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

struct node {
	int key;
	node* left;
	node* right;
	node(int key) :left(nullptr), right(nullptr),key(key) {}
};

bool is_same_tree(node* t1, node* t2) {
	bool nt1 = t1 == nullptr;
	bool nt2 = t2 == nullptr;
	if (!nt1 && !nt2) {
		bool ret = true;
		ret &= is_same_tree(t1->left, t2->left);
		ret &= is_same_tree(t1->right, t2->right);
		return ret;
	} else if (!nt1 || !nt2) return false;
	else return true;
}
int n, k;
node* root[50];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int key;
		scanf("%d", &key);
		root[i] = new node(key);
		for (int j = 1; j < k; j++) {
			node* cur = root[i];
			scanf("%d", &key);
			while (true) {
				if (cur->key > key) {
					if (cur->left == NULL) {
						cur->left = new node(key);
						break;
					}else cur = cur->left;
				} else if(cur->key < key){
					if (cur->right == NULL) {
						cur->right = new node(key);
						break;
					} else cur = cur->right;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < i; j++) 
			if (is_same_tree(root[i], root[j])) {
				flag = false;
				break;
			}
		ans += flag;
	}
	printf("%d", ans);
	return 0;
}