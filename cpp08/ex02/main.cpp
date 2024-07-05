#include <iostream>
#include "MutantStack.h"
#include <deque>
#include <list>

int main() {
	{
		std::cout << "\n---TESTS FROM SUBJECT (MutantStack)---" << std::endl;
		MutantStack<int, std::deque<int> > mstack;
		// MutantStack<int> mstackx;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int, std::deque<int> >::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n---TESTS FROM SUBJECT (std::list)---" << std::endl;
		std::list<int> ls;
		ls.push_back(5);
		ls.push_back(17);
		std::cout << ls.back() << std::endl;
		ls.pop_back();
		std::cout << ls.size() << std::endl;
		ls.push_back(3);
		ls.push_back(5);
		ls.push_back(737);
		//[...]
		ls.push_back(0);
		std::list<int>::iterator it = ls.begin();
		std::list<int>::iterator ite = ls.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
	}
	{
		std::cout << "\n---SECTION 1---" << std::endl;
		std::cout << "simple MutantStack tests\n" << std::endl;

		std::cout << "Default Constructor test:" << std::endl;
		MutantStack<int> st1;

		st1.print();
		std::cout << std::endl;

		st1.push(100);
		st1.push(50);
		st1.push(-42);

		st1.print();
		std::cout << std::endl;
		st1.rprint();
		std::cout << std::endl;

		std::cout << "Copy Constructor test:" << std::endl;
		MutantStack<int> st2 = st1;
		st2.print();
		std::cout << std::endl;

		std::cout << "Copy assignment operator overload test:" << std::endl;
		MutantStack<int> st3;
		st3 = st2;
		st3.print();
		std::cout << std::endl;
	}
	{
		std::cout << "\n---SECTION 2---" << std::endl;
		std::cout << "std::deque is what is \"behind\" std::stack...\n" << std::endl;
		std::deque<int> deq;

		deq.push_front(5);
		deq.push_front(1);
		deq.push_front(6);

		std::cout << "deque iteration front to back:" << std::endl;
		for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++) {
			std::cout << *it << std::endl;
		}
		std::cout << "\n deque iteration back to front:" << std::endl;
		for (std::deque<int>::reverse_iterator it = deq.rbegin(); it != deq.rend(); it++) {
			std::cout << *it << std::endl;
		}
	}
	{
		std::cout << "\n---SECTION 3---" << std::endl;
		std::cout << "MutantStack iterator/reverse_iterator test\n" << std::endl;

		MutantStack<std::string> st1;

		st1.push("Hello");
		st1.push("World");
		st1.push("!");

		std::cout << "MutantStack<std::string> iteration front to back:" << std::endl;
		for (MutantStack<std::string>::iterator it = st1.begin(); it != st1.end(); it++) {
			std::cout << *it << std::endl;
		}

		std::cout << "\nMutantStack<std::string> iteration back to front:" << std::endl;
		for (MutantStack<std::string>::reverse_iterator it = st1.rbegin(); it != st1.rend(); it++) {
			std::cout << *it << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
	{
		std::cout << "\n---SECTION 4---" << std::endl;
		std::cout << "MutantStack const_iterator/const_reverse_iterator test\n" << std::endl;

		// MutantStack<float> st1;
		MutantStack<float, std::deque<float> > st1;
		st1.push(42.42f);
		st1.push(0);
		st1.push(-456464.32435454f);

		const MutantStack<float> st2(st1);

		// std::cout << "MutantStack<float> const iteration front to back:" << std::endl;
		// for (MutantStack<float>::const_iterator it = st2.begin(); it != st2.end(); it++) {
		// 	std::cout << *it << std::endl;
		// }

		// std::cout << "\nMutantStack<float> const iteration back to front:" << std::endl;
		// for (MutantStack<float>::const_reverse_iterator it = st2.rbegin(); it != st2.rend(); it++) {
		// 	std::cout << *it << std::endl;
		// }
		// std::cout << std::endl;
	}

	// std::deque<int>::const_iterator cit = deq.end();


	// MutantStack<int>::container_type::iterator  it = st1.begin();
	// MutantStack<int>::iterator  it2 = st1.begin();

	// MutantStack<int>::const_iterator cit = st1.cbegin();
}
