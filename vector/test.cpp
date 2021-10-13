#include<iostream>
#include <vector>
  #define print(x) cout << x << endl
using namespace std;
  
class base {

    public:
    base()     
    { cout<<"Constructing base "<< std::endl; }
    ~base()
    { cout<<"Destructing base "<< std::endl; }     
};
  
class derived: public base {
  public:
    derived()     
    { cout<<"Constructing derived "<< std::endl; }
    ~derived()
    { cout<<"Destructing derived "<< std::endl; }
};
  
int main(void)
{
  vector<int> vec;
  for (int i = 0; i < 10; i++)
  {
    vec.push_back(i);
  }
  vector<int>::reverse_iterator ritb = vec.rbegin();
  vector<int>::iterator it = vec.end() - 1;

  // for (int i = 0; i < 10; i++)
  // {

    print("rv " << *ritb);
    print("rv " << *it);
    // ritb++;
  // }
  


  
  return 0;
}