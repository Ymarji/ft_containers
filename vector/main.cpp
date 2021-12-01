#include <vector>
#include <exception>
#include <stack>
#include "./vector.hpp"
#include "./map.hpp"
#include <map>
#include <utility>
#define	BST_S 11 
#define	BST(x , y) p12.first = 20; p12.second = 412;

int main(){
    ft::vector<int> vec(10,6);

    vec.insert(vec.begin(),20);
    for (ft::vector<int>::iterator it1=vec.begin(); it1<vec.end(); it1++)
            std::cout << ' ' << *it1;


    {
        std::cout << "------------- Library FT -------------" << std::endl;
        ft::vector<int> myvector1(3, 100);
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        ft::vector<int>::iterator it1;
        it1 = myvector1.begin();
        it1 = myvector1.insert ( it1, 200 );
        myvector1.insert(it1, 2, 300);
        it1 = myvector1.begin();
        ft::vector<int> anothervector1 (2,400);
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        myvector1.insert (it1+2,anothervector1.begin(),anothervector1.end());
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        int myarray1 [] = { 501,502,503 };
        myvector1.insert (myvector1.begin(), myarray1, myarray1+3);
        std::cout << "myvector contains:";
        for (it1=myvector1.begin(); it1<myvector1.end(); it1++)
            std::cout << ' ' << *it1;
        std::cout << '\n';
    }
    {
        std::cout << "------------- Library std -------------" << std::endl;
        std::vector<int> myvector1(3, 100);
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        std::vector<int>::iterator it1;
        it1 = myvector1.begin();
        it1 = myvector1.insert ( it1, 200 );
        myvector1.insert(it1, 2, 300);
        it1 = myvector1.begin();
        std::vector<int> anothervector1 (2,400);
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        myvector1.insert (it1+2,anothervector1.begin(),anothervector1.end());
        std::cout << myvector1.size() << std::endl;
        std::cout << myvector1.capacity() << std::endl;
        int myarray1 [] = { 501,502,503 };
        myvector1.insert (myvector1.begin(), myarray1, myarray1+3);
        std::cout << "myvector contains:";
        for (it1=myvector1.begin(); it1<myvector1.end(); it1++)
            std::cout << ' ' << *it1;
        std::cout << '\n';
    }
    return 0;
}
