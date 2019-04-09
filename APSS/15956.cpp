#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <functional>
using namespace std;
using pairii = pair<int, int>;

class disjoint_set {
private:
	vector<int> list;
public:
	void init(int size) {
		list = vector<int>(size , -1);
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

class dictionary {
private:
	vector<string> int2str;
	map<string, int> str2int;
public:
	bool is_in(string i) {
		return str2int.find(i) != end(str2int);
	}
	bool is_in(int i) {
		return i < int2str.size();
	}
	int size() {
		return int2str.size();
	}
	int get(string i) {
		int key = int2str.size();

		if (is_in(i))
			return str2int[i];

		int2str.push_back(i);
		str2int.insert(make_pair(i, key));
		return key;
	}
	string operator[](int i) {
		return int2str[i];
	}
	int operator[](string i) {
		return str2int[i];
	}
};

struct term {
	bool eq;
	string l, r;
};
class EXP {
protected:
	string exp;
public:
	string get_exp() {
		return exp;
	}
	void set_exp(string exp) {
		this->exp = exp;
	}
};
class EXP_OUT : public EXP {
private:
	int cur;
public:
	EXP_OUT() = default;
	EXP_OUT(string exp) :cur(0) { this->exp = exp; }
	term get_next() {
		int pre = cur;
		term ret = { false,"","" };
		
		if (cur >= exp.size())
			return ret;

		while (exp[cur] != '!' && exp[cur] != '=') cur++;
		ret.l = exp.substr(pre, cur - pre);
		ret.eq = exp[cur] == '=';
		cur += 2;

		pre = cur;
		while (cur < exp.size() && exp[cur] != '&') cur++;
		ret.r = exp.substr(pre, cur - pre);
		cur += 2;

		return ret;
	}
};
class EXP_IN : public EXP {
public:
	void insert_term(string i, string j, bool eq) {
		if (exp.size() != 0)
			exp.append("&&");
		exp.append(i).append(eq ? "==" : "!=").append(j);
	}
};

bool is_number(string str) {
	return str[0] == '-' || (str[0] >= '0' && str[0] <= '9');
}
/*
같은 값들을 집합으로 분류하여 풀이

길이를 줄일 수 있는 경우

== 표시의 경우
1. 같은 집합 내에서는 n-1개의 식으로 표현 (가장 작은 변수를 항상 좌변에 사용)
2. 같은 집합 내에서는 2개이상의 상수가 존재 할 수 없음 (항상 거짓)

!= 표시의 경우
1. 서로 다른 집합이 각각 서로 다른 상수를 하나씩 포함한 경우 생략할 수 있다. (123 != 456)
2. 같은 집합을 비교한 경우 항상 거짓

** 항상 참인 경우가 존재
  위의 방법으로 최소화 했을 때, 아무것도 출력되지 않는 경우 항상 참인 식 하나를 출력

*/

#define INCORRECT_SET "1==2"
#define INCORRECT_NEQ "1!=1"
#define EQ "1==1"

EXP_OUT inp;
EXP_IN ans;
dictionary dic;
vector<pairii> neq_terms, eq_terms;
disjoint_set eq_set;
map < pairii, bool > neq_set;
vector<int> chk_num;

int main() {

	string temp;
	cin >> temp;
	inp.set_exp(temp);

	for (term t = inp.get_next(); t.r != ""; t = inp.get_next()) {
		int l_key = dic.get(t.l);
		int r_key = dic.get(t.r);
		if (t.eq) {
			eq_terms.push_back({ l_key,r_key });
		} else {
			neq_terms.push_back({ l_key,r_key });
		}
	}

	eq_set.init(dic.size());
	chk_num = vector<int>(dic.size());

	//eq에 있는 모든 항에 대해 집합을 구성
	for (pairii term : eq_terms) {
		int i_parent = eq_set[term.first];
		int j_parent = eq_set[term.second];
		eq_set.merge(i_parent, j_parent, [&term,&i_parent,&j_parent]() -> bool{
			return dic[i_parent].size() < dic[j_parent].size();
		});
	}
	//각 집합에 있는 서로다른 숫자의 수 파악
	for (int i = 0; i < dic.size(); i++) {
		int parent = eq_set[i];
		if (is_number(dic[i])) {
			chk_num[parent]++;
			if (chk_num[parent] > 1) {//같은 집합에 서로다른 상수가 2개 이상 있는 경우 거짓
				cout << INCORRECT_SET;
				return 0;
			}
		}
		if (parent == i)
			continue;
		ans.insert_term(dic[i], dic[parent], true);
	}
	//neq에 있는 모든 항에 대해
	for (pairii term : neq_terms) {
		int i_parent = eq_set[term.first];
		int j_parent = eq_set[term.second];

		if (i_parent == j_parent) {//같은 집합에 있는 수를 다르다고 하는경우
			cout << INCORRECT_NEQ;
			return 0;
		}
		if (chk_num[i_parent] == 1 && chk_num[j_parent] == 1)//양쪽 집합에 각각 서로다른 상수가 있는 경우 생략
			continue;

		if (i_parent > j_parent) swap(i_parent, j_parent);

		if(neq_set.find({i_parent,j_parent}) == end(neq_set))//중복이 없는경우 삽입
			neq_set.insert({ { i_parent, j_parent }, true });
	}

	for (auto term : neq_set) 
		ans.insert_term(dic[term.first.second], dic[term.first.first], false);
	
	if (ans.get_exp().size() == 0) {
		cout << EQ;
		return 0;
	}

	cout << ans.get_exp();
	return 0;
}