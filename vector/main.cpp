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
// void	allocatora(){
// 	std::allocator<int> alloc;
// 	int *tab = alloc.allocate(5);
// 	tab[0] = 0;
// 	tab[1] = 1;
// 	tab[2] = 2;
// 	tab[3] = 3;
// 	tab[4] = 4;

// 	int *tmp = tab;
// 	alloc.destroy(tab);
// 	alloc.destroy(tab + 1);
// 	alloc.destroy(tab + 2);
// 	alloc.destroy(tab + 3);
// 	alloc.destroy(tab + 4);
// 	alloc.deallocate(tab, 5);
// 	put(tmp);
// 	put(tab);
// 	for (size_t i = 0; i < 5; i++)
// 	{
// 		put(tmp[i]);
// 	}
	
// }
int main(){
	ft::vector<int> int_arr(5, 10);

	typedef ft::vector<int>::iterator Iterator;

	put("int_arr Size : " << int_arr.size() << " Cap : "<< int_arr.capacity());
	put("---------------------- push back it vector ----------------------");
		for(int  i = 0; i < 4; i++)
			int_arr.push_back(i + 1);


	put("----------------------Print Vector using itertor----------------------");
	put("int_arr Size : " << int_arr.size() << " Cap : "<< int_arr.capacity());
		for(Iterator it = int_arr.begin(); it != int_arr.end(); it++)
			put(*it);

	put("----------------------Vector member function----------------------");
	put("max_size : " << int_arr.max_size());
	int_arr.resize(2);
	int_arr.resize(8, 3);
	int_arr.resize(12);
	int_arr.reserve(24);
	put("----------------------Print Vector using itertor----------------------");
	put("is empty : "<< std::boolalpha << int_arr.empty());
	put("int_arr Size : " << int_arr.size() << " Cap : "<< int_arr.capacity());
		for(int i = 0; i < int_arr.size(); i++){
			put(int_arr.at(i));
		}
	put("----------------------New Vector member function----------------------");
	ft::vector<int> copy;
	copy.assign(int_arr.begin(), int_arr.end());
	put("is empty : "<< std::boolalpha << copy.empty());
	for (size_t i = 0; i < 5; i++)
		copy.pop_back();
	put("copy Size : " << copy.size() << " Cap : "<< copy.capacity());
	put("----------------------Print Vector using itertor----------------------");
		for(int i = 0; i <= copy.size(); i++){
			put(copy.at(i));
		}
	put("----------------------Print Vector using itertor----------------------");
	copy.insert(copy.begin() + 2, int_arr.begin(), int_arr.end());
	copy.erase(copy.begin() + 10, copy.end());
	put("copy Size : " << copy.size() << " Cap : "<< copy.capacity());
	for(int i = 0; i < copy.size(); i++){
		put(copy.at(i));
	}
	put("----------------------Print Vector using itertor----------------------");
	int_arr.clear();
	put("is empty : "<< std::boolalpha << int_arr.empty());
	put("int_arr Size : " << int_arr.size() << " Cap : "<< int_arr.capacity());
		for(int i = 0; i < int_arr.size(); i++){
			put(int_arr.at(i));
		}
    return 0;
}
