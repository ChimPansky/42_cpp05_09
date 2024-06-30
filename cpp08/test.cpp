#include <functional>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

int main() {
	// std::deque<int> s;
	// std::priority_queue<int, std::vector<int>, std::greater<int> > pQueue1;

	std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    } // 1 2 3 4 5
	std::cout << std::endl;
	std::cout << vec.at(0) << std::endl;	// 1
	std::cout << vec.front() << std::endl;	// 1
	std::cout << vec.back() << std::endl;	// 5
	try {
		std::cout << vec.at(-1) << std::endl;	// throws std::out_of_range exception
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << vec[-1] << std::endl;		// 0
	std::cout << vec.data()[0] << std::endl; // 1
	std::cout << vec.empty() << std::endl; // false
	std::cout << vec.size() << std::endl;  // 5
	std::cout << vec.max_size() << std::endl;  // a lot...
	vec.reserve(5) // preallocate



	vec.assign(3, 42); // clear contents of vector and then 3 times add the value 42
	for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    } // 42 42 42
	std::cout << std::endl;



    return 0;
}


	// s.push_front(1);
	// s.push_front(2);
	// s.push_front(3);
	// std::stack<int>::container_type::iterator it = s.begin();
	// std::stack<int>::container_type::iterator it2 = s.cb

	// std::stack<int>::container_type::iterator it = s.top();
	// std::iterator<std::random_access_iterator_tag, int> it = s.top();
	// for (int i = 0; i < 3; i++) {
	// 	std::cout << "?? " << s.top() - i << std::endl;

	// }
	// while (s.size()) {
	// 	std::cout << s.top() << std::endl;
	// 	s.pop();
	// }

	// std::vector<int> v;
	// for (int i = 0; i < 100; i++) {
	// 	v.push_back(i);
	// }
	// std::iterator<typename Category, typename Tp>

	// std::vector<int>::iterator target =  std::find(v.begin(), v.end(), -1);
	// if (target != v.end()) {
	// 	std::cout << "found: " << *target << std::endl;
	// } else {
	// 	std::cout << "not found" << std::endl;
	// }
	// std::cout << "begin: " << v.begin().base() << "; end: " << v.end().base() <<  std::endl;;
	// std::cout << "end - begin: " << v.end().base() - v.begin().base() <<  std::endl;;

	// for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
	// 	std::cout << *it << std::endl;
	// }

	// for (int i = 0; i < v.size(); i++) {
	// 	std::cout << v[i] << std::endl;
	// }
