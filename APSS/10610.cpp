#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n,sum;
vector<int> num;

int main() {

	while (scanf("%1d", &n) != EOF) sum += n, num.push_back(n);
	sort(begin(num), end(num),greater<int>());
	if (sum % 3 == 0 && num[num.size() - 1] == 0)
		for (auto i : num) printf("%d", i);
	else
		printf("-1");
	
	return 0;
}