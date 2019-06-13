#include <cstdio>
#include <vector>
using namespace std;
using mat = vector<vector<int>>;

int n;
long long m;
mat a, ret;

mat operator* (const mat &a, const mat &b) {
	int n = a.size();
	mat c(n, vector<int>(n));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
			c[i][j] %= 1000;
		}
	return c;
}

int main() {
	scanf("%d %lld", &n, &m);
	ret = a = mat(n, vector<int>(n));
	for (auto& arr : a) for (auto& i : arr)
		scanf("%d", &i);	


	for (int i = 0; i < n; i++)	ret[i][i] = 1;
	while (m > 0) {
		if (m % 2 == 1) ret = ret * a;
		a = a * a;
		m /= 2;
	}

	for (auto arr : ret) {
		for (auto i : arr)
			printf("%d ", i);
		printf("\n");
	}
	
	return 0;
}
