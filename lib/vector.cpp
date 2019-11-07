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
};