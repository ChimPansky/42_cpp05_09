#include "FjVector.hpp"
#include <iostream>
#include <algorithm>

int main() {

	FjVector	fjVec;
	FjVector	fjVec2;

	int arr[] = {6, 7, 8, 5, 3, 1, 2, 4, 14, 67, 10, 34, 42, 78, 651, 15, 13, 65, 31, 74, 81};
	// int arr[] = {1, 0, 3, 2};
	fjVec.assign(arr, arr + sizeof(arr) / sizeof(int));
	fjVec.print();
	fjVec.sort();
	fjVec.print();

	// std::cout << "swapping..." << std::endl;
	// fjVec.swap(fjVec2);
	return 0;

}
