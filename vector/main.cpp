#include <vector>
#include "./vector.hpp"
// #include <iostream>
// #include <algorithm>
// #include <memory>
// // // template <class MyIterator>
// // // void do_something(MyIterator start, MyIterator end) {
// // //     typedef typename std::iterator_traits<MyIterator>::value_type value_type; 
// // //     value_type v = *start;
// // //     std::cout << v;
// // // }
int main(){

	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(9);
	v1.push_back(10);
	// v1.assign(5, 200);
	put("-------------------std::vector::print-----------------");
	// int a[] = { 1 , 2 ,3};
	for (std::vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
	{
		std::cout  << *i << std::endl;
	}
	put("------------------- ft::vector::print-----------------");
	ft::vector<int> v(v1.begin(), v1.end());
	for (ft::vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		std::cout  << *i << std::endl;
	}
	put("------------------- ft::vector::re::print-----------------");
	// v.resize(5);
	// v.resize(8,100);
	// v.resize(10);
	v.assign(5, 200);
	
	for (ft::vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		std::cout  << *i << std::endl;
	}
	// std::cout << *(v.begin())  << std::endl;
	// ft::vector<int>::iterator it = v.begin();
	// it++;

//     return 0;
}
