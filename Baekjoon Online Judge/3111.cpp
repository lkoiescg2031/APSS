#include <cstdio>
#include <cstring>
#include <string>
#include <deque>
using namespace std;

char target[300001], cmp[26];
int targetlen, cmplen;
deque<char> left, right;

int main(void){

	scanf("%s %s", cmp, target);
	targetlen = strlen(target);
	cmplen = strlen(cmp);

	int low = 0, high = targetlen - 1;
	while (low <= high) {
		//left
		while (low <= high) {
			bool flag = false;
			left.push_back(target[low++]);
			int len = left.size();
			if (len >= cmplen) {
				int i = 0;
				for (; i < cmplen; i++) 
					if (cmp[i] != left[len - cmplen + i])
						break;
				flag = i == cmplen;
			}
			if (flag) {
				for (int i = 0; i < cmplen; i++)
					left.pop_back();
				break;
			}
		}
		//right
		while(low<=high){
			bool flag = false;
			right.push_front(target[high--]);
			int len = right.size();
			if (len >= cmplen) {
				int i = 0;
				for (; i < cmplen; i++)
					if (cmp[i] != right[i])
						break;
				flag = i == cmplen;
			}
			if (flag) {
				for (int i = 0; i < cmplen; i++)
					right.pop_front();
				break;
			}
		}
	}
	string ans(begin(left), end(left));
	ans.append(begin(right), end(right));
	auto loc = ans.find(cmp);
	while (loc != string::npos) {
		ans.erase(loc, cmplen);
		loc = ans.find(cmp);
	}
	printf("%s", ans.c_str());
	return 0;
}