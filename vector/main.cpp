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
   	v1.push_back(24);
   	v1.push_back(1337);
   	v1.push_back(42);

	int a[] = { 1 , 2 ,3};
	ft::vector<int> v(v1.begin(), v1.end());
	for (ft::vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		std::cout  << *i << std::endl;
	}
	
	// std::cout << *(v.begin())  << std::endl;
	// ft::vector<int>::iterator it = v.begin();
	// it++;

//     return 0;
}