#include <vector>
#include <exception>
#include <stack>
#include "./vector.hpp"
#include "./map.hpp"
#include "./stack.hpp"
#include <map>
#include <utility>
// #include "draw.hpp"
#define	BST_S 11 
#define	BST(x , y) p12.first = 20; p12.second = 412;
#define DELIMIT std::cout << "---------- ---------- ----------\n" << "STD: UP ^ | FT: DOWN v \n" << "---------- ---------- ----------"  << std::endl
#define NEXTD std::cout << "<---------- ---------- ---------- ---------- ---------- ----------|\n" << "<---------- ---------- ---------- ---------- ---------- ----------|"  << std::endl

int main(){


	std::cout << "+++++++++++++++++++++" << std::endl;
	{
		{
			std::map<char,int> first;
			std::map<char,int> second;

			first['x']=8;
			first['y']=16;
			first['z']=32;

			second=first;                // second now contains 3 ints
			first=std::map<char,int>();  // and first is now empty

			std::cout << "Size of first: " << first.size() << '\n';
			std::cout << "Size of second: " << second.size() << '\n';
		}
		DELIMIT;
		{
			ft::map<char,int> first;
			ft::map<char,int> second;

			first['x']=8;
			first['y']=16;
			first['z']=32;

			second=first;                // second now contains 3 ints
			first=ft::map<char,int>();  // and first is now empty

			std::cout << "Size of first: " << first.size() << '\n';
			std::cout << "Size of second: " << second.size() << '\n';
		}
	}
	NEXTD;
	{
		//NOTE: Begin Test
		{
			std::map<char,int> mymap;
			mymap['b'] = 100;
			mymap['a'] = 200;
			mymap['c'] = 300;
			// show content:
			for (std::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << "mymap.size() is " << mymap.size() << '\n';
		}
		DELIMIT;
		{
			ft::map<char,int> mymap;
			mymap['b'] = 100;
			mymap['a'] = 200;
			mymap['c'] = 300;
			// show content:
			for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << "mymap.size() is " << mymap.size() << '\n';
			
		}
	}
	NEXTD;
	{
		// NOTE: Operator[]
		{
			std::map<char,std::string> mymap;
			mymap['a']="an element";
			mymap['b']="another element";
			mymap['c']=mymap['b'];
			std::cout << "mymap['a'] is " << mymap['a'] << '\n';
			std::cout << "mymap['b'] is " << mymap['b'] << '\n';
			std::cout << "mymap['c'] is " << mymap['c'] << '\n';
			std::cout << "mymap['d'] is " << mymap['d'] << '\n';
			std::cout << "mymap now contains " << mymap.size() << " elements.\n";
			std::cout << "mymap.size() is " << mymap.size() << '\n';
		}
		DELIMIT;
		{
			ft::map<char,std::string> mymap;
			mymap['a']="an element";
			mymap['b']="another element";
			mymap['c']=mymap['b'];
			std::cout << "mymap['a'] is " << mymap['a'] << '\n';
			std::cout << "mymap['b'] is " << mymap['b'] << '\n';
			std::cout << "mymap['c'] is " << mymap['c'] << '\n';
			std::cout << "mymap['d'] is " << mymap['d'] << '\n';
			std::cout << "mymap now contains " << mymap.size() << " elements.\n";
			std::cout << "mymap.size() is " << mymap.size() << '\n';
			// mymap.prettyPrint();
		}
	}
	NEXTD;
	{
		// NOTE: INSERT (singel Par, multi -with hint-);
		{
			std::map<char,int> mymap;
			// first insert function version (single parameter):
			mymap.insert ( std::pair<char,int>('a',100) );
			mymap.insert ( std::pair<char,int>('z',200) );
			std::pair<std::map<char,int>::iterator,bool> ret;
			ret = mymap.insert ( std::pair<char,int>('z',500) );
			if (ret.second==false) {
				std::cout << "element 'z' already existed";
				std::cout << " with a value of " << ret.first->second << '\n';
			}else{
				std::cout << "element 'z' created";
				std::cout << " with a value of " << ret.first->second << '\n';
			}
			// second insert function version (with hint position):
			std::map<char,int>::iterator it = mymap.begin();
			mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
			mymap.insert (it, std::pair<char,int>('c',400));
			// third insert function version (range insertion):
			std::map<char,int> anothermap;
			anothermap.insert(mymap.begin(),mymap.find('c'));

			// showing contents:
			std::cout << "mymap contains:\n";
			for (it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << "anothermap contains:\n";
			for (it=anothermap.begin(); it!=anothermap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

		}
		DELIMIT;
		{
			ft::map<char,int> mymap;
			// first insert function version (single parameter):
			mymap.insert ( ft::pair<char,int>('a',100) );
			mymap.insert ( ft::pair<char,int>('z',200) );
			ft::pair<ft::map<char,int>::iterator,bool> ret;
			ret = mymap.insert ( ft::pair<char,int>('z',500) );
			if (ret.second==false) {
				std::cout << "element 'z' already existed";
				std::cout << " with a value of " << ret.first->second << '\n';
			}else{
				std::cout << "element 'z' created";
				std::cout << " with a value of " << ret.first->second << '\n';
			}
			// second insert function version (with hint position):
			ft::map<char,int>::iterator it = mymap.begin();
			mymap.insert(it, ft::pair<char,int>('b',300));  // max efficiency inserting
			mymap.insert(it, ft::pair<char,int>('c',400));
			 // third insert function version (range insertion):
			ft::map<char,int> anothermap;
			anothermap.insert(mymap.begin(),mymap.find('c'));
			std::cout << mymap.size() << std::endl;
			// showing contents:
			std::cout << "mymap contains:\n";
			for (it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << "anothermap contains:\n";
			for (it=anothermap.begin(); it!=anothermap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			// mymap.prettyPrint();
		}
	}
	NEXTD;
	{
		// NOTE: FIND (singel Par)
		{
			std::map<char,int> mymap;
			std::map<char,int>::iterator it;
			mymap['a']=50;
			mymap['b']=100;
			mymap['c']=150;
			mymap['d']=200;
			it = mymap.find('b');
			if (it != mymap.end())
				mymap.erase (it);
			// print content:
			std::cout << "elements in mymap:" << '\n';
			std::cout << "a => " << mymap.find('a')->second << '\n';
			std::cout << "c => " << mymap.find('c')->second << '\n';
			std::cout << "d => " << mymap.find('d')->second << '\n';
			std::cout << "d => " << mymap.find('b')->second << '\n';
		}
		DELIMIT;
		{
			ft::map<char,int> mymap;
			ft::map<char,int>::iterator it;
			mymap['a']=50;
			mymap['b']=100;
			mymap['c']=150;
			mymap['d']=200;
			it = mymap.find('b');
			if (it != mymap.end())
				mymap.erase (it);
			// print content:
			std::cout << "elements in mymap:" << '\n';
			std::cout << "a => " << mymap.find('a')->second << '\n';
			std::cout << "c => " << mymap.find('c')->second << '\n';
			std::cout << "d => " << mymap.find('d')->second << '\n';
			std::cout << "d => " << mymap.find('b')->second << '\n';
		}
	}
	NEXTD;
	{
		// NOTE: ERASE (singel Par)
		{
			std::map<char,int> mymap;
			std::map<char,int>::iterator it;
			// insert some values:
			mymap['a']=10;
			mymap['b']=20;
			mymap['c']=30;
			mymap['d']=40;
			mymap['e']=50;
			mymap['f']=60;
			it=mymap.find('b');
			mymap.erase (it);                   	// erasing by iterator
			mymap.erase ('c');                  	// erasing by key
			it=mymap.find ('e');
			mymap.erase ( it, mymap.end() );		// erasing by range
			// show content:
			for (it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
		DELIMIT;
		{
			ft::map<char,int> mymap;
			ft::map<char,int>::iterator it;
			// insert some values:
			mymap['a']=10;
			mymap['b']=20;
			mymap['c']=30;
			mymap['d']=40;
			mymap['e']=50;
			mymap['f']=60;
			it=mymap.find('b');
			mymap.erase (it);                   	// erasing by iterator
			mymap.erase ('c');             	// erasing by key
			// mymap.prettyPrint();
			it=mymap.find ('e');
			mymap.erase ( it, mymap.end() );		// erasing by range
			// show content:
			for (it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
	}
	NEXTD;
	{
		//NOTE: SWAP member;
		{
			std::map<char,int> foo,bar;
			foo['x']=100;
			foo['y']=200;
			bar['a']=11;
			bar['b']=22;
			bar['c']=33;
			foo.swap(bar);
			std::cout << "foo contains:\n";
			for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << "bar contains:\n";
			for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
		DELIMIT;
		{
			ft::map<char,int> foo,bar;
			foo['x']=100;
			foo['y']=200;
			bar['a']=11;
			bar['b']=22;
			bar['c']=33;
			foo.swap(bar);
			std::cout << "foo contains:\n";
			for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << "bar contains:\n";
			for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
	}
	NEXTD;
	{
		{
			std::map<char,int> mymap;
			mymap['x']=1001;
			mymap['y']=2002;
			mymap['z']=3003;
			std::cout << "mymap contains:\n";
			std::pair<char,int> highest = *mymap.rbegin();          // last element
			std::map<char,int>::iterator it = mymap.begin();
			do {
				std::cout << it->first << " => " << it->second << '\n';
			} while ( mymap.value_comp()(*it++, highest) );
		}
		DELIMIT;
		{
			ft::map<char,int> mymap;
			mymap['x']=1001;
			mymap['y']=2002;
			mymap['z']=3003;
			std::cout << "mymap contains:\n";
			ft::pair<char,int> highest = *mymap.rbegin();          // last element
			ft::map<char,int>::iterator it = mymap.begin();
			do {
				std::cout << it->first << " => " << it->second << '\n';
			} while ( mymap.value_comp()(*it++, highest) );
		}
	}
	NEXTD;
	{
		{
		std::map<char,int> mymap;
		std::map<char,int>::iterator itlow,itup;
		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['f']=100;
		itlow=mymap.lower_bound ('f');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		std::cout << itlow->first << std::endl;
		std::cout << itup->first << std::endl;
		mymap.erase(itlow,itup);        // erases [itlow,itup)
		// print content:
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		}
		DELIMIT;
		{
			ft::map<char,int> mymap;
			ft::map<char,int>::iterator itlow,itup;
			mymap['a']=20;
			mymap['b']=40;
			mymap['c']=60;
			mymap['d']=80;
			mymap['f']=100;
			itlow=mymap.lower_bound ('f');  // itlow points to b
			itup=mymap.upper_bound ('d');   // itup points to e (not d!)

			std::cout << itlow->first << std::endl;
			std::cout << itup->first << std::endl;
			mymap.erase(itlow,itup);        // erases [itlow,itup)
			// print content:
			for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
	}
	NEXTD;
	{
		{
			std::map<char,int> mymap;

			mymap['a']=10;
			mymap['b']=20;
			mymap['c']=30;

			std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
			ret = mymap.equal_range('b');

			std::cout << "lower bound points to: ";
			std::cout << ret.first->first << " => " << ret.first->second << '\n';

			std::cout << "upper bound points to: ";
			std::cout << ret.second->first << " => " << ret.second->second << '\n';
		}
		DELIMIT;
		{
			ft::map<char,int> mymap;

			mymap['a']=10;
			mymap['b']=20;
			mymap['c']=30;

			ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
			ret = mymap.equal_range('b');

			std::cout << "lower bound points to: ";
			std::cout << ret.first->first << " => " << ret.first->second << '\n';

			std::cout << "upper bound points to: ";
			std::cout << ret.second->first << " => " << ret.second->second << '\n';
		}
	}
	NEXTD;
	{
		{
			int psize;
			std::map<char,int> mymap;
			std::pair<const char,int>* p;

			// allocate an array of 5 elements using mymap's allocator:
			p=mymap.get_allocator().allocate(5);

			// assign some values to array
			psize = sizeof(std::map<char,int>::value_type)*5;

			std::cout << "The allocated array has a size of " << psize << " bytes.\n";

			mymap.get_allocator().deallocate(p,5);
		}
		DELIMIT;
		{
			int psize;
			ft::map<char,int> mymap;
			ft::pair<const char,int>* p;

			// allocate an array of 5 elements using mymap's allocator:
			p=mymap.get_allocator().allocate(5);

			// assign some values to array
			psize = sizeof(ft::map<char,int>::value_type)*5;

			std::cout << "The allocated array has a size of " << psize << " bytes.\n";

			mymap.get_allocator().deallocate(p,5);
		}
	}
}
/*
NEXTD;
	{
		{

		}
		DELIMIT;
		{

		}
	}
*/