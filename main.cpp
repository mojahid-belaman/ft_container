#include "Vector.hpp"
#include <vector>
#include <iterator>
#include <iostream>

struct data
{
    int a;
    int b;
    data() {std::cout << "Constructor Default\n";}
    data(int a = 1337, int b = 42) : a(a), b(b)
    {
        std::cout << "a: " << a << ", b: " << b << std::endl;
        std::cout << "Constructor parametrse\n";}
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
};


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

    std::vector<int> myvector;
    myvector.resize(5);
    myvector.resize(8,100);
    myvector.resize(12);

    std::cout << "myvector contains:";
    for (int i=0;i<myvector.size();i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';
    return (0);
}