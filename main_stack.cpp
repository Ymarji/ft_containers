#include <iostream>
#include <string>
#include <deque>
#include "stack.hpp"
#include <stack>
#include <stdlib.h>

#ifndef	PH
#define	PH	ft
#endif

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public PH::stack<T>
{
public:
	MutantStack() {std::cout << "====================\n";}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename PH::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main() {
	PH::stack<int> stack_int;

	MutantStack<char> iterable_stack;

	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	ft::stack<int> t1;
	ft::stack<int> t2;

	for (int letter = 0; letter <= 5; letter++){
		t1.push(letter);	
		t2.push(letter);
	}
	if (t1 == t2)
		std::cout << "OK" << std::endl;
	return (0);
}