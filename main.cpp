#include "Vector.hpp"
#include <vector>

int main()
{
    // NOTE - This Vector the System
    std::cout << "Vector System:" << std::endl;
    std::vector<int>v1(4, 1337);
    // std::cout << v1.size() << std::endl;
    // std::cout << v1.capacity() << std::endl;
    // for (size_t i = 0; i < v1.size(); i++)
    // {
    //     std::cout << v1[i] << std::endl;
    // }
    std::vector<int>v3(v1.begin(), v1.end());
    std::cout << v3.size() << std::endl;
    std::cout << v3.capacity() << std::endl;
    for (size_t i = 0; i < v3.size(); i++)
    {
        std::cout << v3[i] << std::endl;
    }


    // NOTE - This My Vector
    // std::cout << "My Vector:" << std::endl;
    // ft::vector<int>v2(v1.begin(), v1.end());
    // ft::vector<int>v3(v2);

    return (0);
}