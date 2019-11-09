#include <bits/stdc++.h>
using namespace std;

struct Trie {
	bool islast;
	Trie *R,*B;
	Trie() : islast(false),R(nullptr),B(nullptr) {}
	~Trie() { if(!R) delete R; if(!B) delete B; }
	void insert(string& key,int i = 0) {
		if(key.size() == i)	return;

		Trie *temp = nullptr;
		if(key[i] == 'R'){
			if(!this->R) this->R = new Trie();
			this->R->islast |= key.size() == i+1;
			this->R->insert(key,i+1);
		}else if(key[i] == 'B'){
			if(!this->B) this->B = new Trie();
			this->B->islast |= key.size() == i+1;
			this->B->insert(key,i+1);
		}
	}
};

long long retrive(Trie* root, int len, int h = 0){
	long long ret = 0ll;
	if(root->islast) return 1ll << (len - h);

	if(root->R) ret += retrive(root->R, len, h + 1);
	if(root->B) ret += retrive(root->B, len, h + 1);
	return ret;
}

#define endl '\n'
int T, N, P;

int main (){
	cin>>T;

	for(int t=0;t<T;t++){
		Trie root;
		string temp;

		cin>>N>>P;		
		for(int i=0;i<P;i++)
			cin >> temp, root.insert(temp);

		long long ans = retrive(&root, N);
		cout << "Case #" << t+1 << ": " << (1ll << N) - ans << endl;
	}
	
	return 0;
}