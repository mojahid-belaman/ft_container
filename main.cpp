#include "Vector.hpp"
#include <vector>
#include <iterator>
#include <iostream>
#include <type_traits>

typedef struct data
{
    int a;
    int b;
    // data() {std::cout << "Constructor Default\n";}
    data(int a = 1337, int b = 42) : a(a), b(b)
    {
        std::cout << "a: " << a << ", b: " << b << std::endl;
        std::cout << "Constructor parametrse\n";
    }
    data(const data& dt) {*this = dt;}
    data& operator= (const data& dt)
    {
        if (this != &dt)
        {
            this->a = dt.a;
            this->b = dt.b;
        }
        return (*this);
    }
} t_data;

int main()
{
    // NOTE - This Vector the System
    std::cout << "Vector System:" << std::endl;
    // std::vector<data>v1;
    // std::vector<int>::iterator it;
    // it = 3 + it;
    // v1.push_back(32);
    // v1.push_back(42);
    // v1.push_back(19);
    // std::vector<data>::reverse_iterator it = v1.begin();
    // std::cout << it->a << std::endl;
    // std::cout << it->b << std::endl;

    // v1.push_back(1337);
    // v1.push_back(42);
    // v1.push_back(19);
    // int a = 42;
    // std::vector<int>::iterator it1 ;
    // std::cout << it1->a << std::endl;

    // std::cout << v1.size() << std::endl;
    // std::cout << v1.capacity() << std::endl;
    // for (size_t i = 0; i < v1.size(); i++)
    // {
    //     std::cout << v1[i] << std::endl;
    // }
    // std::vector<int>v3(v1.begin(), v1.end());
    // std::cout << v3.size() << std::endl;
    // std::cout << v3.capacity() << std::endl;
    // for (size_t i = 0; i < v3.size(); i++)
    // {
    //     std::cout << v3[i] << std::endl;
    // }

    // NOTE - This My Vector
    // std::cout << "My Vector:" << std::endl;
    // ft::vector<int> myvector(5, 42);


    // ft::vector<int> myvector(3, 42);
    // ft::vector<int>::iterator it1 = myvector.begin();
    // ft::vector<int>::iterator it2;
    // it2 = it1;
    // std::cout << *it2 << std::endl;
    // ft::vector<int>::iterator it1;
    // ft::vector<int>::const_iterator it2;
    // it2 = it1;
//   std::cout << "myvector contains:";
//   for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

    // ft::vector<int> myvector;
    // myvector.push_back (100);
    // myvector.push_back (200);
    // myvector.push_back (300);
    // std::cout << &myvector[0] << std::endl;
    // std::cout << &myvector[1] << std::endl;
    // std::cout << &myvector[2] << std::endl;
    // myvector.pop_back();

    // std::cout << myvector.size() << std::endl;
    // for (size_t i = 0; i < myvector.size(); i++)
    // {
    //     std::cout << myvector[i] << std::endl;
    // }
    // std::cout << "end of main" << std::endl;

    // for (int i=1;i<10;i++) myvector.push_back(i);
//  ft::vector<int> test(begin, end);
//     std::vector<int> first;
//   std::vector<int> second;
//   ft::vector<int> third;

//   first.assign (7,100);             // 7 ints with a value of 100

//   ft::vector<int>::iterator it;
//   it=first.begin()+1;

//   second.assign (it,first.end()-1); // the 5 central values of first

//   int myints[] = {-1776,7,4};
//   third.assign (&myints[0],&myints[2]);   // assigning from array.
//         std::cout << third.size() << std::endl;
//         std::cout << third.capacity() << std::endl;
//     for (size_t i = 0; i < third.size(); i++)
//     {
//         std::cout << third[i] << std::endl;
//     }
    
//   std::cout << "Size of first: " << int (first.size()) << '\n';
//   std::cout << "Size of second: " << int (second.size()) << '\n';
//   std::cout << "Size of third: " << int (third.size()) << '\n';


//   myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
//   it = myvector.begin();

//   std::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   int myarray [] = { 501,502,503 };
//   myvector.insert (myvector.begin(), myarray, myarray+3);

//   std::cout << "myvector contains:";
//   for (it=myvector.begin(); it<myvector.end(); it++)
//     std::cout << ' ' << *it;


ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it, 200 );
  for (size_t i = 0; i < myvector.size(); i++)
  {
      std::cout << myvector[i] << std::endl;
  }
  

//   std::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   int myarray [] = { 501,502,503 };
//   myvector.insert (myvector.begin(), myarray, myarray+3);

//   std::cout << "myvector contains:";
//   for (it=myvector.begin(); it<myvector.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
}