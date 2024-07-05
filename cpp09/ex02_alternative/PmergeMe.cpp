#include "FjVector.hpp"
#include <iostream>
#include <algorithm>

int main() {

	FjVector	fjVec;
	FjVector	fjVec2;

	// int arr[] = {6, 7, 8, 5, 3, 1, 2, 4};
	int arr[] = {6, 7, 8, 5, 3, 1, 2, 4};
	fjVec.assign(arr, arr + sizeof(arr) / sizeof(int));
	fjVec.print();
	fjVec.sort();
	fjVec.print();

	// std::cout << "swapping..." << std::endl;
	// fjVec.swap(fjVec2);
	return 0;

}
