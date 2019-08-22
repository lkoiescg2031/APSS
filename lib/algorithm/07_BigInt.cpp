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
	std::vector<int> digits;//숫자열
	int sign;//부호
public:
	//constructor
	bigint() :
		sign(1) {
	}//0으로 초기화
	bigint(long long v) {
		*this = v;
	}//longlong 타입을 이용한 초기화
	bigint(const std::string &s) {
		read(s);
	}//문자열로 초기화
	 //logical operator
	bool operator<(const bigint &v) const {
		if (sign != v.sign)//부호 우선비교
			return sign < v.sign;
		if (digits.size() != v.digits.size())//부호 포함 숫자 길이 비교
			return digits.size() * sign < v.digits.size() * v.sign;
		for (int i = digits.size() - 1; i >= 0; i--)//각자리 수 비교
			if (digits[i] != v.digits[i])//같지않은경우
				return digits[i] * sign < v.digits[i] * sign;//결과값을 비교
		return false;//아닌 경우 일치하므로 거짓
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
		res.sign = -sign;//부호를 반전시킴
		return res;
	}
	bigint operator+(const bigint &v) const {
		if (sign == v.sign) {//부호가 같은 경우
			bigint res = v;//res에 v를 먼저 대입
			int max = std::max(digits.size(), v.digits.size());

			for (int i = 0, carry = 0; i < max || carry; ++i) {//this와 v중 더큰값까지 또는 올림수가 발생하는 동안
				if (i == (int)res.digits.size())//std::vector에 빈공관이 없으면
					res.digits.push_back(0);//추가
				res.digits[i] += carry + (i < (int)digits.size() ? digits[i] : 0);//digits의 자리가 존재하면 digits 아니면 0을 더함
				carry = res.digits[i] >= base;//올림수 발생하는가
				if (carry)//올림수가 발생하면
					res.digits[i] -= base;//i번째에서 올림수 제거
			}
			return res;//결과 반환
		}
		return *this - (-v);// 부호가 다른경우 부호를 통일
	}
	bigint operator-(const bigint &v) const {
		if (sign == v.sign) {//부호가 같은경우
			if (abs(*this) >= abs(v)) {//절대값이 더 큰 경우
				bigint res = *this;//지금 값을 결과에 대입
				for (int i = 0, carry = 0; i < (int)v.digits.size() || carry; ++i) {//v의 자리수를 다 뺴거?carry가 있는 경우
					res.digits[i] -= carry + (i < (int)v.digits.size() ? v.digits[i] : 0);//carry와 v의 i번째 값을 뺌 (i번째 값이 없는 경우 0)
					carry = res.digits[i] < 0;//결과가 음수인가 음수면 1
					if (carry)//캐리가 발생하면
						res.digits[i] += base;//base 만큼 증가
				}
				res.trim();//0을 제거
				return res;
			}
			return -(v - *this);//아닌경우 부호가 바뀌므로 부호를 변환하여 뺌
		}
		return *this + (-v);//다른경우 부호를 변환 하여 더함
	}
	bigint operator*(int v) const {
		bigint res = *this;
		res *= v;// 곱하여 대입
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
		return divmod(*this, v).first;//나누어 몫만 가짐
	}
	bigint operator^(const bigint &v) {
		bigint ans = 1, a = *this, b = v;
		while (!b.isZero()) {//지수가 0이아닐떄까지
			if (b % 2)
				ans *= a;//a^(b/2)*a^(b/2)*a^(b%2)
			a *= a, b /= 2;
		}
		return ans;
	}
	int operator%(int v) const {
		if (v < 0)
			v = -v;//나누는 수가 음수인경우 양수로 전환
		int m = 0;
		for (int i = digits.size() - 1; i >= 0; --i)
			m = (digits[i] % v + m%v * (long long)base%v) % v;//다항식 연산 이용 하여 나머지 계산
		return m * sign;//나머지와 부호를 반환
	}
	bigint operator%(const bigint &v) const {
		return divmod(*this, v).second;//v로 나눈 나머지를 반환
	}
	//assignment operator
	void operator=(const bigint &v) {//복사대입
		sign = v.sign;
		digits = v.digits;
	}
	void operator=(long long v) {
		sign = 1;//부호 양수로 전환
		digits.clear();//숫자열 초기화
		if (v < 0)
			sign = -1, v = -v;//음수인경우 부호 먼저 계산
		for (; v > 0; v = v / base)
			digits.push_back(v % base);//낮은 자리부터 삽입
	}
	//arithmetic assignment operator
	void operator*=(int v) {
		*this *= (long long)v;//long long 으로 변환하여 연산
	}
	void operator*=(long long v) {
		if (v < 0)
			sign = -sign, v = -v;//v가 음수인경우 부호먼저 연산
		for (int i = 0, carry = 0; i < (int)digits.size() || carry; ++i) {//digit의 모든 자리수까지 또는 carry 가 존재할때
			if (i == (int)digits.size())
				digits.push_back(0);//케리에의한 마지막 자리가 존재하지 않을 떄 자리를 늘림
			long long cur = digits[i] * (long long)v + carry;//현재 자리에서 값을 계산
			carry = (int)(cur / base);//carry를 계산
			digits[i] = (int)(cur % base);//나머지를 저장
		}
		trim();//0을 제거
	}
	void operator/=(int v) {
		if (v < 0)
			sign = -sign, v = -v;//부호를 먼저계산
		for (int i = (int)digits.size() - 1, rem = 0; i >= 0; --i) {
			long long cur = digits[i] + rem * (long long)base;//이전 나머지에서 base를 곱한 후 현제 자리수를 더함
			digits[i] = (int)(cur / v);//몫을 i자리에 저장
			rem = (int)(cur % v);//나머지를 넘김
		}
		trim();//앞자리 0을 지움
	}
	void operator+=(const bigint &v) {
		*this = *this + v;//v를 더한후 대입
	}
	void operator-=(const bigint &v) {
		*this = *this - v;//v를 뺸 후 대입
	}
	void operator*=(const bigint &v) {
		*this = *this * v;//v를 곱한 후 대입
	}
	void operator/=(const bigint &v) {
		*this = *this / v;//v를 나눈 후 대입
	}
	//casting method
	operator long long() const {//long long 으로 타입 변환
		long long res = 0;
		for (int i = digits.size() - 1; i >= 0; i--)//마지막자리부터 값을 넣음 (오버플로우는 신경 쓰지 않는다)
			res = res * base + digits[i];
		return res * sign;
	}
	operator std::string() const {
		std::stringstream ss;
		ss << *this;//스트링 스트림에 넣어
		std::string s;
		ss >> s;//스트링에 반환
		return s;
	}

	//method
	void trim() {
		while (!digits.empty() && !digits.back())//마지막 자리가 0이고 digits이 비어 있지 않을동안
			digits.pop_back();//0을 제거
		if (digits.empty())//비어있다면
			sign = 1;//부호를 초기화
	}
	bool isZero() const {
		return digits.empty() || (digits.size() == 1 && !digits[0]);//digits이 비어있거나 0 하나만 들어있는 경우
	}
	int size() {
		if (digits.empty()) return 0;//digitdl 비어 있다면 0자리
		int ans = (digits.size() - 1)*base_digits;//마지막자리를 제외한 모든값에 base의 자리수 만큼 곱함
		int ca = digits.back();//마지막자리에 대해
		while (ca)//자리수만큼 카운트
			ans++, ca /= 10;
		return ans;
	}
	std::string to_string() {
		std::stringstream ss;
		ss << *this;//스트링 스트림에 넣어
		std::string s;
		ss >> s;//스트링에 반환
		return s;
	}
	void read(const std::string &s) {
		//init
		sign = 1;
		digits.clear();

		int pos = 0;
		for (; pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+'); ++pos)//부호를 찾을 떄까지
			if (s[pos] == '-')//-가 있으면
				sign = -sign;//부호 변환

		for (int i = s.size() - 1; i >= pos; i -= base_digits) {//가장 작은 자리부터 부호 뒷부분까지
			int x = 0;
			for (int j = std::max(pos, i - base_digits + 1); j <= i; j++)//한칸 내에서는 자리수를 순서대로 넣음
				x = x * 10 + s[j] - '0';//각 자리수를 계산
			digits.push_back(x);//가장 뒤에 넣음
		}
		trim();//앞의 0을 지움
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
bigint abs(const bigint &v) {//절대값 구하는 함수
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
bigint gcd(const bigint &a, const bigint &b) {//최대공약수
	return b.isZero() ? a : gcd(b, a % b);//recur
}
bigint lcm(const bigint &a, const bigint &b) {//최소공배수
	return a / gcd(a, b) * b;
}
std::istream& operator>>(std::istream &stream, bigint &v) {//입력 스트림 연산자 정의
	std::string s;
	stream >> s;
	v.read(s);
	return stream;
}
std::ostream& operator<<(std::ostream &stream, const bigint &v) {//출력 스트림 연산자 장의
	if (v.sign == -1)
		stream << '-';//부호 출력
	stream << (v.digits.empty() ? 0 : v.digits.back());//비어 있지않으면 가장 마지막 자리 출력 아닌경우 0 출력
	for (int i = (int)v.digits.size() - 2; i >= 0; --i)//나머지 자리 출력
		stream << std::setw(base_digits) << std::setfill('0') << v.digits[i];//base자리수만큼 0으로 칸을 확보하여 출력
	return stream;
}
/*
#######################   THE   BIG   INT   ##########################
######################################################################
*/