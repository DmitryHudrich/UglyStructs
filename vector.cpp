namespace DimaLib {
	template <typename T>
	class DynamicArray {
	private:
		const int DEFAULT_CAPACITY = 2;
	private:
		// вместимость
		size_t _capacity;
		// заполненность
		size_t _fullness;
		size_t _last_index;
		T* _data;
	private:
		void _copy(T* old, T* young);
		void _resize(size_t new_size);

	public:
		size_t add(T item);
		T get(size_t index);
		size_t get_fullness();
	public:
		DynamicArray();
	};

	//definitions

	template<typename T>
	inline void DynamicArray<T>::_copy(T* old, T* young) {
		for (size_t i = 0; i < _capacity; i++) {
			*(young + i) = *(old + i);
		}
	}
	template<typename T>
	inline void DynamicArray<T>::_resize(size_t new_size) {
		_capacity = new_size;
		T* out = new T[_capacity];
		_copy(_data, out);
		_data = out;
	}
	template<typename T>
	inline size_t DynamicArray<T>::add(T item) {
		if (_fullness++ == _capacity) {
			_resize(_capacity * 2);
		}
		*(_data + _last_index++) = item;
		return _last_index;
	}
	template<typename T>
	inline T DynamicArray<T>::get(size_t index) {
		if (index > _fullness)
			throw "overflow except";
		return *(_data + index);
	}
	template<typename T>
	inline size_t DynamicArray<T>::get_fullness() {
		return _fullness;
	}
	template<typename T>
	inline DynamicArray<T>::DynamicArray() {
		_last_index = -1;
		_capacity = DEFAULT_CAPACITY;
		_fullness = 0;
		_data = new T[_capacity];
	}
}