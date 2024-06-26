#pragma once

template <typename T>
void	swap(T& a, T& b) {
	T temp = b;
	b = a;
	a = temp;
}

template <typename X>
X	min(X& a, X& b) {
	if (a < b)
		return a;
	return b;
}

template <typename ANY>
ANY	max(ANY& a, ANY& b) {
	if (a > b)
		return a;
	return b;
}
