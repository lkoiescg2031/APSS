#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <utility>
/*
######################################################################
#######################   THE   BIG   INT   ##########################
*/

const int base = 10;
const int base_digits = 1;
class bigint {
private:
	std::vector<int> digits;//���ڿ�
	int sign;//��ȣ
public:
	//constructor
	bigint() :
		sign(1) {
	}//0���� �ʱ�ȭ
	bigint(long long v) {
		*this = v;
	}//longlong Ÿ���� �̿��� �ʱ�ȭ
	bigint(const std::string &s) {
		read(s);
	}//���ڿ��� �ʱ�ȭ
	 //logical operator
	bool operator<(const bigint &v) const {
		if (sign != v.sign)//��ȣ �켱��
			return sign < v.sign;
		if (digits.size() != v.digits.size())//��ȣ ���� ���� ���� ��
			return digits.size() * sign < v.digits.size() * v.sign;
		for (int i = digits.size() - 1; i >= 0; i--)//���ڸ� �� ��
			if (digits[i] != v.digits[i])//�����������
				return digits[i] * sign < v.digits[i] * sign;//������� ��
		return false;//�ƴ� ��� ��ġ�ϹǷ� ����
	}
	bool operator>(const bigint &v) const {
		return v < *this;
	}
	bool operator<=(const bigint &v) const {
		return !(v < *this);
	}
	bool operator>=(const bigint &v) const {
		return !(*this < v);
	}
	bool operator==(const bigint &v) const {
		return !(*this < v) && !(v < *this);
	}
	bool operator!=(const bigint &v) const {
		return *this < v || v < *this;
	}
	//arithmetic operator
	bigint operator-() const {
		bigint res = *this;
		res.sign = -sign;//��ȣ�� ������Ŵ
		return res;
	}
	bigint operator+(const bigint &v) const {
		if (sign == v.sign) {//��ȣ�� ���� ���
			bigint res = v;//res�� v�� ���� ����
			int max = std::max(digits.size(), v.digits.size());

			for (int i = 0, carry = 0; i < max || carry; ++i) {//this�� v�� ��ū������ �Ǵ� �ø����� �߻��ϴ� ����
				if (i == (int)res.digits.size())//std::vector�� ������� ������
					res.digits.push_back(0);//�߰�
				res.digits[i] += carry + (i < (int)digits.size() ? digits[i] : 0);//digits�� �ڸ��� �����ϸ� digits �ƴϸ� 0�� ����
				carry = res.digits[i] >= base;//�ø��� �߻��ϴ°�
				if (carry)//�ø����� �߻��ϸ�
					res.digits[i] -= base;//i��°���� �ø��� ����
			}
			return res;//��� ��ȯ
		}
		return *this - (-v);// ��ȣ�� �ٸ���� ��ȣ�� ����
	}
	bigint operator-(const bigint &v) const {
		if (sign == v.sign) {//��ȣ�� �������
			if (abs(*this) >= abs(v)) {//���밪�� �� ū ���
				bigint res = *this;//���� ���� ����� ����
				for (int i = 0, carry = 0; i < (int)v.digits.size() || carry; ++i) {//v�� �ڸ����� �� ����?carry�� �ִ� ���
					res.digits[i] -= carry + (i < (int)v.digits.size() ? v.digits[i] : 0);//carry�� v�� i��° ���� �� (i��° ���� ���� ��� 0)
					carry = res.digits[i] < 0;//����� �����ΰ� ������ 1
					if (carry)//ĳ���� �߻��ϸ�
						res.digits[i] += base;//base ��ŭ ����
				}
				res.trim();//0�� ����
				return res;
			}
			return -(v - *this);//�ƴѰ�� ��ȣ�� �ٲ�Ƿ� ��ȣ�� ��ȯ�Ͽ� ��
		}
		return *this + (-v);//�ٸ���� ��ȣ�� ��ȯ �Ͽ� ����
	}
	bigint operator*(int v) const {
		bigint res = *this;
		res *= v;// ���Ͽ� ����
		return res;
	}
	bigint operator*(long long v) const {
		bigint res = *this;
		res *= v;
		return res;
	}
	bigint operator*(const bigint &v) const {
		std::vector<int> a6 = convert_base(this->digits, base_digits, 6);
		std::vector<int> b6 = convert_base(v.digits, base_digits, 6);
		std::vector<long long> a(a6.begin(), a6.end());
		std::vector<long long> b(b6.begin(), b6.end());
		while (a.size() < b.size())
			a.push_back(0);
		while (b.size() < a.size())
			b.push_back(0);
		while (a.size() & (a.size() - 1))
			a.push_back(0), b.push_back(0);
		std::vector<long long> c = karatsubaMultiply(a, b);
		bigint res;
		res.sign = sign * v.sign;
		for (int i = 0, carry = 0; i < (int)c.size(); i++) {
			long long cur = c[i] + carry;
			res.digits.push_back((int)(cur % 1000000));
			carry = (int)(cur / 1000000);
		}
		res.digits = convert_base(res.digits, 6, base_digits);
		res.trim();
		return res;
	}
	bigint operator/(int v) const {
		bigint res = *this;
		res /= v;
		return res;
	}
	bigint operator/(const bigint &v) const {
		return divmod(*this, v).first;//������ �� ����
	}
	bigint operator^(const bigint &v) {
		bigint ans = 1, a = *this, b = v;
		while (!b.isZero()) {//������ 0�̾ƴҋ�����
			if (b % 2)
				ans *= a;//a^(b/2)*a^(b/2)*a^(b%2)
			a *= a, b /= 2;
		}
		return ans;
	}
	int operator%(int v) const {
		if (v < 0)
			v = -v;//������ ���� �����ΰ�� ����� ��ȯ
		int m = 0;
		for (int i = digits.size() - 1; i >= 0; --i)
			m = (digits[i] % v + m%v * (long long)base%v) % v;//���׽� ���� �̿� �Ͽ� ������ ���
		return m * sign;//�������� ��ȣ�� ��ȯ
	}
	bigint operator%(const bigint &v) const {
		return divmod(*this, v).second;//v�� ���� �������� ��ȯ
	}
	//assignment operator
	void operator=(const bigint &v) {//�������
		sign = v.sign;
		digits = v.digits;
	}
	void operator=(long long v) {
		sign = 1;//��ȣ ����� ��ȯ
		digits.clear();//���ڿ� �ʱ�ȭ
		if (v < 0)
			sign = -1, v = -v;//�����ΰ�� ��ȣ ���� ���
		for (; v > 0; v = v / base)
			digits.push_back(v % base);//���� �ڸ����� ����
	}
	//arithmetic assignment operator
	void operator*=(int v) {
		*this *= (long long)v;//long long ���� ��ȯ�Ͽ� ����
	}
	void operator*=(long long v) {
		if (v < 0)
			sign = -sign, v = -v;//v�� �����ΰ�� ��ȣ���� ����
		for (int i = 0, carry = 0; i < (int)digits.size() || carry; ++i) {//digit�� ��� �ڸ������� �Ǵ� carry �� �����Ҷ�
			if (i == (int)digits.size())
				digits.push_back(0);//�ɸ������� ������ �ڸ��� �������� ���� �� �ڸ��� �ø�
			long long cur = digits[i] * (long long)v + carry;//���� �ڸ����� ���� ���
			carry = (int)(cur / base);//carry�� ���
			digits[i] = (int)(cur % base);//�������� ����
		}
		trim();//0�� ����
	}
	void operator/=(int v) {
		if (v < 0)
			sign = -sign, v = -v;//��ȣ�� �������
		for (int i = (int)digits.size() - 1, rem = 0; i >= 0; --i) {
			long long cur = digits[i] + rem * (long long)base;//���� ���������� base�� ���� �� ���� �ڸ����� ����
			digits[i] = (int)(cur / v);//���� i�ڸ��� ����
			rem = (int)(cur % v);//�������� �ѱ�
		}
		trim();//���ڸ� 0�� ����
	}
	void operator+=(const bigint &v) {
		*this = *this + v;//v�� ������ ����
	}
	void operator-=(const bigint &v) {
		*this = *this - v;//v�� �A �� ����
	}
	void operator*=(const bigint &v) {
		*this = *this * v;//v�� ���� �� ����
	}
	void operator/=(const bigint &v) {
		*this = *this / v;//v�� ���� �� ����
	}
	//casting method
	operator long long() const {//long long ���� Ÿ�� ��ȯ
		long long res = 0;
		for (int i = digits.size() - 1; i >= 0; i--)//�������ڸ����� ���� ���� (�����÷ο�� �Ű� ���� �ʴ´�)
			res = res * base + digits[i];
		return res * sign;
	}
	operator std::string() const {
		std::stringstream ss;
		ss << *this;//��Ʈ�� ��Ʈ���� �־�
		std::string s;
		ss >> s;//��Ʈ���� ��ȯ
		return s;
	}

	//method
	void trim() {
		while (!digits.empty() && !digits.back())//������ �ڸ��� 0�̰� digits�� ��� ���� ��������
			digits.pop_back();//0�� ����
		if (digits.empty())//����ִٸ�
			sign = 1;//��ȣ�� �ʱ�ȭ
	}
	bool isZero() const {
		return digits.empty() || (digits.size() == 1 && !digits[0]);//digits�� ����ְų� 0 �ϳ��� ����ִ� ���
	}
	int size() {
		if (digits.empty()) return 0;//digitdl ��� �ִٸ� 0�ڸ�
		int ans = (digits.size() - 1)*base_digits;//�������ڸ��� ������ ��簪�� base�� �ڸ��� ��ŭ ����
		int ca = digits.back();//�������ڸ��� ����
		while (ca)//�ڸ�����ŭ ī��Ʈ
			ans++, ca /= 10;
		return ans;
	}
	std::string to_string() {
		std::stringstream ss;
		ss << *this;//��Ʈ�� ��Ʈ���� �־�
		std::string s;
		ss >> s;//��Ʈ���� ��ȯ
		return s;
	}
	void read(const std::string &s) {
		//init
		sign = 1;
		digits.clear();

		int pos = 0;
		for (; pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+'); ++pos)//��ȣ�� ã�� ������
			if (s[pos] == '-')//-�� ������
				sign = -sign;//��ȣ ��ȯ

		for (int i = s.size() - 1; i >= pos; i -= base_digits) {//���� ���� �ڸ����� ��ȣ �޺κб���
			int x = 0;
			for (int j = std::max(pos, i - base_digits + 1); j <= i; j++)//��ĭ �������� �ڸ����� ������� ����
				x = x * 10 + s[j] - '0';//�� �ڸ����� ���
			digits.push_back(x);//���� �ڿ� ����
		}
		trim();//���� 0�� ����
	}
	static std::vector<int> convert_base(const std::vector<int> &a, int old_digits, int new_digits) {
		std::vector<long long> p(std::max(old_digits, new_digits) + 1);
		p[0] = 1;
		for (int i = 1; i < (int)p.size(); i++)
			p[i] = p[i - 1] * 10;
		std::vector<int> res;
		long long cur = 0;
		int cur_digits = 0;
		for (int i = 0; i < (int)a.size(); i++) {
			cur += a[i] * p[cur_digits];
			cur_digits += old_digits;
			while (cur_digits >= new_digits) {
				res.push_back(int(cur % p[new_digits]));
				cur /= p[new_digits];
				cur_digits -= new_digits;
			}
		}
		res.push_back((int)cur);
		while (!res.empty() && !res.back())
			res.pop_back();
		return res;
	}
	static std::vector<long long> karatsubaMultiply(const std::vector<long long> &a, const std::vector<long long> &b) {
		int n = a.size();
		std::vector<long long> res(n + n);
		if (n <= 32) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					res[i + j] += a[i] * b[j];
			return res;
		}

		int k = n >> 1;
		std::vector<long long> a1(a.begin(), a.begin() + k);
		std::vector<long long> a2(a.begin() + k, a.end());
		std::vector<long long> b1(b.begin(), b.begin() + k);
		std::vector<long long> b2(b.begin() + k, b.end());

		std::vector<long long> a1b1 = karatsubaMultiply(a1, b1);
		std::vector<long long> a2b2 = karatsubaMultiply(a2, b2);

		for (int i = 0; i < k; i++)
			a2[i] += a1[i];
		for (int i = 0; i < k; i++)
			b2[i] += b1[i];

		std::vector<long long> r = karatsubaMultiply(a2, b2);
		for (int i = 0; i < (int)a1b1.size(); i++)
			r[i] -= a1b1[i];
		for (int i = 0; i < (int)a2b2.size(); i++)
			r[i] -= a2b2[i];

		for (int i = 0; i < (int)r.size(); i++)
			res[i + k] += r[i];
		for (int i = 0; i < (int)a1b1.size(); i++)
			res[i] += a1b1[i];
		for (int i = 0; i < (int)a2b2.size(); i++)
			res[i + n] += a2b2[i];
		return res;
	}
	//friend function
	friend bigint abs(const bigint &v);
	friend std::pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1);
	friend bigint gcd(const bigint &a, const bigint &b);
	friend bigint lcm(const bigint &a, const bigint &b);
	friend std::istream& operator>>(std::istream &stream, bigint &v);
	friend std::ostream& operator<<(std::ostream &stream, const bigint &v);
};
bigint abs(const bigint &v) {//���밪 ���ϴ� �Լ�
	bigint res = v;
	res.sign *= res.sign;
	return res;
}
std::pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
	int norm = base / (b1.digits.back() + 1);
	bigint a = abs(a1) * norm;
	bigint b = abs(b1) * norm;
	bigint q, r;
	q.digits.resize(a.digits.size());

	for (int i = a.digits.size() - 1; i >= 0; i--) {
		r *= base;
		r += a.digits[i];
		int s1 = r.digits.size() <= b.digits.size() ? 0 : r.digits[b.digits.size()];
		int s2 = r.digits.size() <= b.digits.size() - 1 ? 0 : r.digits[b.digits.size() - 1];
		int d = ((long long)base * s1 + s2) / b.digits.back();
		r -= b * d;
		while (r.operator<(0))
			r += b, --d;
		q.digits[i] = d;
	}

	q.sign = a1.sign * b1.sign;
	r.sign = a1.sign;
	q.trim();
	r.trim();
	return std::make_pair(q, r / norm);
}
bigint gcd(const bigint &a, const bigint &b) {//�ִ�����
	return b.isZero() ? a : gcd(b, a % b);//recur
}
bigint lcm(const bigint &a, const bigint &b) {//�ּҰ����
	return a / gcd(a, b) * b;
}
std::istream& operator>>(std::istream &stream, bigint &v) {//�Է� ��Ʈ�� ������ ����
	std::string s;
	stream >> s;
	v.read(s);
	return stream;
}
std::ostream& operator<<(std::ostream &stream, const bigint &v) {//��� ��Ʈ�� ������ ����
	if (v.sign == -1)
		stream << '-';//��ȣ ���
	stream << (v.digits.empty() ? 0 : v.digits.back());//��� ���������� ���� ������ �ڸ� ��� �ƴѰ�� 0 ���
	for (int i = (int)v.digits.size() - 2; i >= 0; --i)//������ �ڸ� ���
		stream << std::setw(base_digits) << std::setfill('0') << v.digits[i];//base�ڸ�����ŭ 0���� ĭ�� Ȯ���Ͽ� ���
	return stream;
}
/*
#######################   THE   BIG   INT   ##########################
######################################################################
*/