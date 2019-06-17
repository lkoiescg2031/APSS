#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using big_int = vector<int>;
const int base = 10;
big_int operator+ (const big_int& a, const big_int& b) {
	int carry = 0, i = 0;
	int alen = a.size();
	int blen = b.size();
	big_int ret(max(alen,blen) + 1);
	while (i < alen && i < blen) {
		int sum = a[i] + b[i] + carry;
		carry = sum / base;
		sum = sum % base;
		ret[i] = sum;
		i++;
	}
	while (i < alen) {
		int sum = a[i] + carry;
		carry = sum / base;
		sum = sum % base;
		ret[i] = sum;
		i++;
	}
	while (i < blen) {
		int sum = b[i] + carry;
		carry = sum / base;
		sum = sum % base;
		ret[i] = sum;
		i++;
	}
	if (carry != 0) ret[i] = carry;
	while (ret.size()>1 && ret.back() == 0) ret.pop_back();
	return ret;
}
big_int to_big_int(long long i) {
	big_int ret;
	while (i > 0)
		ret.push_back(i % base), i /= base;
	if (ret.empty()) ret.push_back(i);
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	big_int pre, cur, next;
	cur = to_big_int(1);
	next = to_big_int(1);
	if (n == 0) printf("0");
	else if (n == 1 || n == 2) printf("1");
	else {
		for (int i = 3; i <= n; i++) {
			pre = cur;
			cur = next;
			next = pre + cur;
		}
		for (int i = next.size() - 1; i >= 0; i--)
			printf("%d", next[i]);
	}
	return 0;
}