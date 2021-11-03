#include <vector>
#include <exception>
#include <stack>
#include "./vector.hpp"
#include "./map.hpp"
#include <map>

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
	typedef ft::vector<int>::iterator Iterator;

	ft::vector<int> stv;
	// stv.push_back(1);
	// stv.push_back(2);
	// stv.push_back(3);
	// stv.push_back(4);
	// stv.push_back(5);
	// stv.push_back(6);
	// stv.push_back(7);
	// stv.push_back(8);
	// put("int_arr Size : " << stv.size() << " Cap : "<< stv.capacity());
	// // stv.resize(19,55);
	// stv.reserve(91);
	// stv.insert(stv.begin(), 2,9999);
	// // stv.assign(16, 10);
	// 	for(Iterator it = stv.begin(); it != stv.end(); it++)
	// 		put(*it);
	// put("int_arr Size : " << stv.size() << " Cap : "<< stv.capacity());


	// ft::vector<int> int_arr(5, 10);
	// ft::vector<int> v;
	// v.push_back(1);
	// v.push_back(2);
	// v.push_back(3);

	// ft::vector<int>::reverse_iterator it = v.rbegin();
	// put("iter : " << it[0]);
	// put("base : " << *it.base());
	
	// typedef ft::vector<int>::iterator Iterator;

	// put("int_arr Size : " << int_arr.size() << " Cap : "<< int_arr.capacity());
	// put("---------------------- push back it vector ----------------------");
	// 	for(int  i = 0; i < 4; i++)
	// 		int_arr.push_back(i + 1);


	// put("----------------------Print Vector using itertor----------------------");
	// put("int_arr Size : " << int_arr.size() << " Cap : "<< int_arr.capacity());
	// 	for(Iterator it = int_arr.begin(); it != int_arr.end(); it++)
	// 		put(*it);

	// put("----------------------Vector member function----------------------");
	// put("max_size : " << int_arr.max_size());
	// int_arr.resize(2);
	// int_arr.resize(8, 3);
	// int_arr.resize(12);
	// int_arr.reserve(24);
	// put("----------------------Print Vector using itertor----------------------");
	// put("is empty : "<< std::boolalpha << int_arr.empty());
	// put("int_arr Size : " << int_arr.size() << " Cap : "<< int_arr.capacity());
	// 	for(int i = 0; i < int_arr.size(); i++){
	// 		put(int_arr.at(i));
	// 	}
	// put("----------------------New Vector member function----------------------");
	// ft::vector<int> copy;
	// copy.assign(int_arr.begin(), int_arr.end());
	// put("is empty : "<< std::boolalpha << copy.empty());
	// for (size_t i = 0; i < 5; i++)
	// 	copy.pop_back();
	// put("copy Size : " << copy.size() << " Cap : "<< copy.capacity());
	// put("----------------------Print Vector using itertor----------------------");
	// 	for(int i = 0; i <= copy.size(); i++){
	// 		put(copy.at(i));
	// 	}
	// put("----------------------Print Vector using itertor----------------------");
	// copy.insert(copy.begin() + 2, int_arr.begin(), int_arr.end());
	// copy.erase(copy.begin() + 10, copy.end());
	// put("copy Size : " << copy.size() << " Cap : "<< copy.capacity());
	// for(int i = 0; i < copy.size(); i++){
	// 	put(copy.at(i));
	// }
	// put("----------------------Print Vector using itertor----------------------");
	// int_arr.clear();
	// put("is empty : "<< std::boolalpha << int_arr.empty());
	// put("int_arr Size : " << int_arr.size() << " Cap : "<< int_arr.capacity());
	// 	for(int i = 0; i < int_arr.size(); i++){
	// 		put(int_arr.at(i));
	// 	}
	{
		typedef ft::__tree<ft::pair<int, int>, std::less<int>, std::allocator<ft::pair<int, int> > > tree;
		typedef ft::_node<ft::pair<int, int> > node;
			ft::pair<int, int> p;
		p.first = 9;
		p.second = 45;
			ft::pair<int, int> p1;
		p1.first = 4;
		p1.second = 43;
			ft::pair<int, int> p2;
		p2.first = 2;
		p2.second = 44;
			ft::pair<int, int> p3;
		p3.first = 1;
		p3.second = 43;
			ft::pair<int, int> p4;
		p4.first = 3;
		p4.second = 44;
			ft::pair<int, int> p5;
		p5.first = 15;
		p5.second = 45;
			ft::pair<int, int> p6;
		p6.first = 13;
		p6.second = 46;
			ft::pair<int, int> p7;
		p7.first = 12;
		p7.second = 47;
			ft::pair<int, int> p8;
		p8.first = 14;
		p8.second = 48;
			ft::pair<int, int> p9;
		p9.first = 16;
		p9.second = 49;
			ft::pair<int, int> p10;
		p10.first = 19;
		p10.second = 410;
			ft::pair<int, int> p11;
		p11.first = 18;
		p11.second = 411;
			ft::pair<int, int> p12;
		p12.first = 20;
		p12.second = 412;

		tree Tr;
		node tmp;
		Tr.AddinTree(Tr.MakeNode(p));
		Tr.AddinTree(Tr.MakeNode(p1));
		Tr.AddinTree(Tr.MakeNode(p2));
		Tr.AddinTree(Tr.MakeNode(p3));
		Tr.AddinTree(Tr.MakeNode(p4));
		Tr.AddinTree(Tr.MakeNode(p5));
		Tr.AddinTree(Tr.MakeNode(p6));
		Tr.AddinTree(Tr.MakeNode(p7));
		Tr.AddinTree(Tr.MakeNode(p8));
		Tr.AddinTree(Tr.MakeNode(p9));
		Tr.AddinTree(Tr.MakeNode(p10));
		Tr.AddinTree(Tr.MakeNode(p11));
		Tr.AddinTree(Tr.MakeNode(p12));
		std::cout << Tr.treeMin(Tr.getRoot())->Value << std::endl;
		std::cout << Tr.treeMax(Tr.getRoot())->Value << std::endl;
		std::cout << Tr.size() << std::endl;
		std::cout << Tr.search(1)->Value << std::endl;
		// Tr._delete(4);
		// std::cout << Tr.size() << std::endl;
		// std::cout << Tr.search(1)->Value << std::endl;
		Tr.ordred_traversal(Tr.getRoot());
		// std::cout << Tr.search(4)->Value << std::endl;
		// std::cout << Tr.search(5)->Value << std::endl;
		// std::cout << Tr.search() << std::endl;
	}
    return 0;
}
