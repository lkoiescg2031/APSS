namespace my {
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
};