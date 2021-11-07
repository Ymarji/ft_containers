#include <vector>
#include <exception>
#include <stack>
#include "./vector.hpp"
#include "./map.hpp"
#include <map>
#include <utility>
#define	BST_S 11 
#define	BST(x , y) p12.first = 20; p12.second = 412;
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
	// typedef ft::vector<int>::iterator Iterator;
	// ft::vector<int> stv;
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
		typedef ft::__tree<ft::pair<const int, int>, std::less<int>, std::allocator<ft::pair<int, int> > > tree;
		typedef ft::__node<ft::pair<const int, int> > node;
			ft::pair<const int, int> p1(9, 45);
			ft::pair<const int, int> p2(8, 45);
			ft::pair<const int, int> p3(2, 45);
			ft::pair<const int, int> p4(5, 45);
			ft::pair<const int, int> p5(1, 45);
			ft::pair<const int, int> p6(15, 45);
			ft::pair<const int, int> p7(13, 45);
			ft::pair<const int, int> p8(16, 45);
			ft::pair<const int, int> p9(19, 45);
			ft::pair<const int, int> p10(20, 45);
			ft::pair<const int, int> p11(18, 45);
			ft::pair<const int, int> p12(14, 45);
			ft::pair<const int, int> p13(12, 45);
		ft::map<int, int>::tree Tr;
		// INSERT IN TREE;
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
		Tr.AddinTree(Tr.MakeNode(p13));
		// OPERATION ON TREE
		// std::cout << Tr.treeMin(Tr.getRoot())->Value << std::endl;
		// std::cout << Tr.treeMax(Tr.getRoot())->Value << std::endl;
		// std::cout << Tr.search(1)->Value << std::endl;
		// std::cout << Tr.size() << std::endl;
		// Tr.ordred_traversal(Tr.getRoot());
		// put("========");
		// Tr._delete(4);
		// Tr._delete(9);
		// Tr._delete(1);
		// Tr._delete(19);
		// std::cout << Tr.size() << std::endl;
		// // IN-ORDER TREE WALK
		Tr.ordred_traversal(Tr.getRoot());
		put("========");
		ft::map<int, int>::iterator it(Tr.treeMax());
		--it;
		++it;
		std::cout << (*it) << std::endl;
		// for (size_t i = 0; i < 13; i++)
		// {
		// 	std::cout  << i << "  "<< (*it++) << std::endl;
		// }
		ft::pair<int ,int> *a = new ft::pair<int ,int>();
		std::cout  << a->second;
		// std::cout << (*it++) << std::endl;
		// // std::cout << (*it--) << std::endl;
		// std::cout << (*it) << std::endl;
		// std::cout << (*--it) << std::endl;

		// ft::map<int, int>::const_iterator it(Tr.treeMin());
		// for (size_t i = 0; i < 13; i++)
		// {
		// 	std::cout << (*it++) << std::endl;
		// }
		// std::cout << (*it++) << std::endl;
		// // std::cout << (*it--) << std::endl;
		// std::cout << (*it) << std::endl;
		// std::cout << (*--it) << std::endl;


		// std::map<int,int> a;
		// // a[1] = 1;
		// // a[2] = 2;
		// // a[3] = 3;
		// // a[4] = 4;
		// // a[5] = 5;
		// // a[6] = 6;

		// std::map<int, int>::iterator it11 = a.end();
		// // --it11;
		// // std::cout << it11->second << std::endl;
		// std::cout << std::atoi("-1");
	}
    return 0;
}
