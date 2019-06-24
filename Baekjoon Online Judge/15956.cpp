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
	void merge(int i, int j, function<bool()>cmp = NULL) {//CMP : ���� ���� �� ª�� ��� ��
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
���� ������ �������� �з��Ͽ� Ǯ��

���̸� ���� �� �ִ� ���

== ǥ���� ���
1. ���� ���� �������� n-1���� ������ ǥ�� (���� ���� ������ �׻� �º��� ���)
2. ���� ���� �������� 2���̻��� ����� ���� �� �� ���� (�׻� ����)

!= ǥ���� ���
1. ���� �ٸ� ������ ���� ���� �ٸ� ����� �ϳ��� ������ ��� ������ �� �ִ�. (123 != 456)
2. ���� ������ ���� ��� �׻� ����

** �׻� ���� ��찡 ����
  ���� ������� �ּ�ȭ ���� ��, �ƹ��͵� ��µ��� �ʴ� ��� �׻� ���� �� �ϳ��� ���

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

	//eq�� �ִ� ��� �׿� ���� ������ ����
	for (pairii term : eq_terms) {
		int i_parent = eq_set[term.first];
		int j_parent = eq_set[term.second];
		eq_set.merge(i_parent, j_parent, [&term,&i_parent,&j_parent]() -> bool{
			return dic[i_parent].size() < dic[j_parent].size();
		});
	}
	//�� ���տ� �ִ� ���δٸ� ������ �� �ľ�
	for (int i = 0; i < dic.size(); i++) {
		int parent = eq_set[i];
		if (is_number(dic[i])) {
			chk_num[parent]++;
			if (chk_num[parent] > 1) {//���� ���տ� ���δٸ� ����� 2�� �̻� �ִ� ��� ����
				cout << INCORRECT_SET;
				return 0;
			}
		}
		if (parent == i)
			continue;
		ans.insert_term(dic[i], dic[parent], true);
	}
	//neq�� �ִ� ��� �׿� ����
	for (pairii term : neq_terms) {
		int i_parent = eq_set[term.first];
		int j_parent = eq_set[term.second];

		if (i_parent == j_parent) {//���� ���տ� �ִ� ���� �ٸ��ٰ� �ϴ°��
			cout << INCORRECT_NEQ;
			return 0;
		}
		if (chk_num[i_parent] == 1 && chk_num[j_parent] == 1)//���� ���տ� ���� ���δٸ� ����� �ִ� ��� ����
			continue;

		if (i_parent > j_parent) swap(i_parent, j_parent);

		if(neq_set.find({i_parent,j_parent}) == end(neq_set))//�ߺ��� ���°�� ����
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