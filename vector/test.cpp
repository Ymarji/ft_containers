#include<iostream>
#include <vector>
  #define print(x) cout << x << endl
using namespace std;
  
struct base {
	int i;
	int j;
	int k;
};

  
int main(void)
{
	std::allocator<int> alloc;
	int *i = alloc.allocate(1);
	typedef typename std::allocator<int>::template rebind<base>::other _Alty;
	base *b = _Alty(alloc).allocate(1);
	
	return 0;
}