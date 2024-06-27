#include <iostream>
#include <vector>

int main() {
	std::vector<int> v;
	for (int i = 0; i < 100; i++) {
		v.push_back(i);
	}
	std::iterator<typename Category, typename Tp>

	std::vector<int>::iterator target =  std::find(v.begin(), v.end(), -1);
	if (target != v.end()) {
		std::cout << "found: " << *target << std::endl;
	} else {
		std::cout << "not found" << std::endl;
	}
	// std::cout << "begin: " << v.begin().base() << "; end: " << v.end().base() <<  std::endl;;
	// std::cout << "end - begin: " << v.end().base() - v.begin().base() <<  std::endl;;

	// for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
	// 	std::cout << *it << std::endl;
	// }

	// for (int i = 0; i < v.size(); i++) {
	// 	std::cout << v[i] << std::endl;
	// }

}
