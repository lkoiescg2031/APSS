#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
using pairii = pair<int, int>;
using pairiii = pair<pairii, int>;
using pairiiii = pair<pairiii, int>;

int N, Q;
vector<pairiii> vtx, edge;
vector<pairiiii> qry;
priority_queue<pairiii,vector<pairiii>,greater<pairiii>> pq;
vector<int> ans;


class disjoint_set {
private:
	vector<int> list;
public:
	disjoint_set() = default;
	disjoint_set(int N) { this->init(N); }
	void init(int size) {
		list = vector<int>(size, -1);
	}
	int operator[](int i) {
		return list[i] == -1 ? i : list[i] = this->operator[](list[i]);
	}
	void merge(int i, int j, function<bool()>cmp = NULL) {//CMP : 왼쪽 값이 더 짧은 경우 참
		int i_parent = this->operator[](i);
		int j_parent = this->operator[](j);

		if (i_parent == j_parent)
			return;
		if (cmp != NULL && cmp()) {
			list[j_parent] = i_parent;
			return;
		}
		list[i_parent] = j_parent;
	}
};

int main() {

	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		vtx.push_back({ {x,y},i });
	}

	ans = vector<int>(Q);
	for (int i = 0; i < Q; i++) {
		int a, b, x;
		cin >> a >> b >> x;
		qry.push_back({ {{x,a},b },i });
	}
	
	//x 정렬
	sort(begin(vtx), end(vtx));
	for (int i = 1; i < vtx.size(); i++) {
		int dx = abs(vtx[i - 1].first.first - vtx[i].first.first);
		pq.push({ {dx,vtx[i - 1].second},vtx[i].second });
	}

	//y 정렬
	sort(begin(vtx), end(vtx), [](pairiii x,pairiii y) {
		if (x.first.second != y.first.second)
			return x.first.second < y.first.second;
		return x < y;
	});
	for (int i = 1; i < vtx.size(); i++) {
		int dy = abs(vtx[i - 1].first.second - vtx[i].first.second);
		pq.push({ {dy,vtx[i - 1].second},vtx[i].second });
	}
	
	//qry 정렬
	sort(begin(qry), end(qry));
	disjoint_set set(N + 1);
	for (auto i : qry) {
		while (!pq.empty() && pq.top().first.first <= i.first.first.first) {
			auto j = pq.top(); pq.pop();
			set.merge(j.first.second, j.second);
		}
		ans[i.second] = set[i.first.first.second] == set[i.first.second];
	}

	for (auto i : ans) {
		if (i) cout << "YES\n";
		else cout << "NO\n";
	}
	

	return 0;
}