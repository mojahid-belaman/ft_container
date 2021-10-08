#include <iostream>
#include "Vector.hpp"

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

int main(){
	ft::vector<int> 			vect;
	vect.push_back(1337);
	vect.push_back(42);
	vect.push_back(23);
	vect.push_back(6);
	vect.push_back(1997);
	ft::vector<int>::iterator	iter = vect.begin();
	std::cout << *iter << std::endl;
	std::cout << *(++iter) << std::endl;
	std::cout << *(iter + 2) << std::endl;
	std::cout << iter[2] << std::endl;
	ft::vector<int> myvector;
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);
    myvector.pop_back();

    for (size_t i = 0; i < myvector.size(); i++)
    {
        std::cout << myvector[i] << std::endl;
    }

	ft::vector<data>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	ft::vector<data>::iterator it = v.begin();
	std::cout << it->a << std::endl;
	it++;
	std::cout << it->a << std::endl;

	ft::vector<int> myvec(10);   // 10 zero-initialized elements

	ft::vector<int>::size_type sz = myvec.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvec[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvec[sz-1-i];
		myvec[sz-1-i]=myvec[i];
		myvec[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvec[i];
	std::cout << '\n';

}