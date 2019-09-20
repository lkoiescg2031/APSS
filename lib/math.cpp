namespace my {
	template<typename T>
	inline T abs(T val) {
		return val < 0 ? -val : val;
	};
};