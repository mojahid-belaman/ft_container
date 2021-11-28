#include <iostream>

class ilias
{
    private:
        int a;
    public:
        ilias() : a(1337) {}
        int get_nb(){
            
            std::cout << "function return copy" << std::endl;
            std::cout << &a << std::endl;
            return a;}
        int &get_n(){

            std::cout << "function return reference" << std::endl;
            std::cout << &a << std::endl;
            return a;}
};


int &get_num(int (&arr)[3])
{
    std::cout << arr[0] << std::endl;
    return arr[0];
}

int main()
{
    // int arr[3] = {1337, 42, 19};

    // std::cout << &arr[0] << std::endl;
    
    // std::cout << &get_num(arr) << std::endl;
    ilias a;
    // std::cout << &a.get_nb() << std::endl;
    std::cout << &a.get_n() << std::endl;
    return 0;
}