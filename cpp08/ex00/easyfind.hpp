#pragma once
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int target) {
	return std::find(container.begin(), container.end(), target);
}

template <typename T>
const typename T::const_iterator easyfind(const T &container, int target) {
	return std::find(container.begin(), container.end(), target);
}
