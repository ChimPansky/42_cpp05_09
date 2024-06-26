#pragma once
#include <cstddef>

template <typename T>
void	iter(T* arrayPtr, size_t arrayLen, void (*foo)(T&)) {
	for (size_t i = 0; i < arrayLen; i++) {
		foo(arrayPtr[i]);
	}
}
