namespace my {
	template<typename T>
	class vector {
		T* _container;
		int _size, _capacity;
	public:
		vector() : _size(0), _capacity(32) {
			_container = new T[_capacity];
		}
		vector(int size) : _size(size), _capacity(size) {
			_container = new T[_capacity];
		}
		vector(int size, T val) : _size(size), _capacity(size) {
			int i = 0;
			_container = new T[_capacity];
			while (i < size) _container[i++] = val;
		}
		~vector() {
			delete[] _container;
		}

		T operator[] (int idx) const {
			return _container[idx];
		}
		T& operator[] (int idx) {
			return _container[idx];
		}

		int size() const {
			return _size;
		}
		T* begin() const {
			return _container;
		}
		T* end() const {
			return _container + _size;
		}

		void clear() {
			_size = 0;
			_capacity = 32;
			_container = new T[_capacity];
		}
		void resize(int size) {

			T* temp = new T[size];
			int i = size < _size ? size : _size;
			while (--i) temp[i] = _container[i];

			delete[] _container;
			_container = temp;
			_size = _capacity = size;
		}

		void push_back(T ele) {
			if (_size == _capacity) {
				resize(2 * _size);
				_size /= 2;
			}
			_container[_size++] = ele;
		}
		void pop_back() {
			_size--;
		}
	};

	template<typename T>
	class queue {
		struct _node {
			T val;
			_node* next;
			_node() : next(nullptr) {}
			_node(T val) : next(nullptr), val(val) {}
		};

		_node* _head, * _tail;
		int _size;

	public:
		~queue() {
			_node* temp;
			while (_head) {
				temp = _head;
				_head = _head->next;
				delete temp;
			}
		}

		int size() const {
			return _size;
		}
		bool empty() const {
			return !_head;
		}
		T front() const {
			return _head->val;
		}
		T back() const {
			return _tail->val;
		}

		void push(T val) {
			_node* temp = new _node(val);
			if (!_head) _head = _tail = temp;
			else {
				_tail->next = temp;
				_tail = temp;
			}
			_size++;
		}
		void pop() {
			_node* temp = _head;
			_head = _head->next;
			delete temp;

		}
	};

	template<typename T>
	inline T abs(T val) {
		return val < 0 ? -val : val;
	}
}
using namespace my;

#define INF 0x3f3f3f3f
#define A 1
#define B 0

int n, cost[11], team[11], visit[11];
vector<int> adj[11];

int bfs(int start, int team_size, int choice) {
	int cnt = 0, sum = 0;;
	queue<int> q;
	vector<int> visit(n + 1, false);
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		sum += cost[cur];
		cnt++;

		for (int i = 0; i < adj[cur].size();i++) {
			int next = adj[cur][i];
			if (!visit[next] && team[next] == choice) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
	if (cnt == team_size) return sum;
	return INF;
}

int go(int idx, int teamA, int teamB) {
	int a, b;

	if (idx > n) {
		if (teamA == 0 || teamB == 0) return INF;

		int cur = 1;
		while (team[cur] != A) cur++;
		a = bfs(cur, teamA, A);
		if (a == INF) return INF;

		cur = 1;
		while (team[cur] != B) cur++;
		b = bfs(cur, teamB, B);
		if (b == INF) return INF;

		return abs(a - b);
	}

	team[idx] = A;
	a = go(idx + 1, teamA + 1, teamB);
	team[idx] = B;
	b = go(idx + 1, teamA, teamB + 1);
	return a > b ? b : a;
}

#include <cstdio>
using namespace std;

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &cost[i + 1]);

	for (int i = 0; i < n; i++) {
		int len, t;
		scanf("%d", &len);
		while (len--) {
			scanf("%d", &t);
			adj[i + 1].push_back(t);
		}
	}

	int ans = go(1, 0, 0);
	if (ans == INF) ans = -1;
	printf("%d\n", ans);

	return 0;
}