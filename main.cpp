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
    std::cout << "My Vector:" << std::endl;
    ft::vector<int>v2(3, 1337);
    // ft::vector<int>v3(v2);
    // ft::vector<int>v3(3, 1337);

    return (0);
}