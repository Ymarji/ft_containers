#include <vector>
#include <exception>
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
// class test{
// 	public:
// 		test():a(100){};
// 		int a;
// 		int geta(){return a;}
// };
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
	put("-------------------std::vector::print-----------------");
	// int a[] = { 1 , 2 ,3};
	
	// for (std::vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
	// {
	// 	std::cout << *(i.base()) << std::endl;
	// 	// std::cout  << *i << std::endl;
	// }
	v1.assign(2, 200);

	for (int i = 0; i < 10; i++)
	{
		std::cout  << v1[i] << std::endl;
	}
	put("------------------- ft::vector::print-----------------");
	std::vector<int> v(v1.begin(), v1.end());
	// std::vector<int> v(5, 100);
		for (int i = 0; i < 10; i++)
	{
		std::cout  << v[i] << std::endl;
	}
	std::cout  << v.capacity() << " " << v.size() << std::endl;
	// put("------------------- ft::vector::print-----------------");
	// ft::vector<int> v(v1.begin(), v1.end());
	// // ft::vector<int> v(5, 100);
	// for (ft::vector<int>::iterator i = v.begin(); i != v.end(); i++)
	// {
	// 	// std::cout  << i.base() << std::endl;
	// 	std::cout  << *i << std::endl;
	// }
	// std::cout  << v.capacity() << " " << v.size() << std::endl;
	// put("------------------- ft::vector::re::print-----------------");
	// // // v.resize(5);
	// // // v.resize(8,100);
	// // // v.resize(10);
	// v.assign(2, 200);
	// for (ft::vector<int>::iterator i = v.begin(); i != v.end(); i++)
	// {
	// 	std::cout  << *i << std::endl;
	// }
	// std::cout  << v.capacity() << " " << v.size() << std::endl;
	// std::cout << *(v.begin())  << std::endl;
	// ft::vector<int>::iterator it = v.begin();
	// it++;
	// std::vector<int> v(v1.begin(), v1.end());
	// // std::vector<int> v(5, 100);
	// for (std::vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); i++)
	// {
	// 	// std::cout  << i.base() << std::endl;
	// 	std::cout  << *i << std::endl;
	// }
	put("-------------------reverse ft::vector::print-----------------");
	// ft::vector<int> mv(v1.begin(), v1.end());
	// // ft::vector<int> v(5, 100);
	// for (ft::vector<int>::reverse_iterator i = mv.rbegin(); i != mv.rend(); i++)
	// {
	// 	// std::cout  << i.base() << std::endl;
	// 	std::cout  << *i << std::endl;
	// }
	put("-------------------reverse ft::vector::re::print-----------------");
	// v.resize(5);
	// v.resize(8,100);
	// v.resize(10);
	// v.assign(5, 200);	
	// for (ft::vector<int>::iterator i = v.begin(); i != v.end(); i++)
	// {
	// 	std::cout  << *i << std::endl;
	// }
	// std::cout << *(v.begin())  << std::endl;
	// ft::vector<int>::iterator it = v.begin();
	// it++;
    return 0;
}
