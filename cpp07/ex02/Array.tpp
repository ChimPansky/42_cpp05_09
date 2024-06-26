#include <iostream>

template <typename T>
Array<T>::Array()
	: _data(0), _size(0) {}

template <typename T>
Array<T>::Array(size_t n)
	: _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other)
	: _data(new T[other._size]()), _size(other._size) {
	_copyData(other);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		delete[] _data;
		_data = new T[other._size]();
		_copyData(other);
		_size = other._size;
	}
	return *this;
}

template <typename T>
void	Array<T>::_copyData(const Array<T>& other) {
	for (size_t i = 0; i < other._size; i++) {
		_data[i] = other._data[i];
	}
}

template <typename T>
T& Array<T>::operator[](size_t idx) {
	if (idx >= _size) {
		throw Array<T>::OutOfBoundsException();
	}
	return _data[idx];
}

template <typename T>
size_t	Array<T>::size() const {
	return _size;
}

template <typename T>
void	Array<T>::print() const {
	for (size_t i = 0; i < _size; i++) {
		std::cout << "Array[" << i << "]: " << _data[i] << std::endl;
	}
}

template <typename T>
Array<T>::~Array() {
	delete[] _data;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return "Array index out of bounds";
}
