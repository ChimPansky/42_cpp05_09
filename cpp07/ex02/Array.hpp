#pragma once
#include <cstddef>
#include <exception>

template <typename T>
class Array {
  private:
	T*		_data;
	size_t	_size;

	void	_copyData(const Array& other);

  public:
	Array();
	Array(size_t n);
	Array(const Array& other);
	~Array();

	Array& operator=(const Array& other);
	T& operator[](size_t idx);
	size_t	size() const;
	void	print() const;

	class OutOfBoundsException : public std::exception {
	  public:
		const char* what() const throw();
	};
};

#include "Array.tpp"
