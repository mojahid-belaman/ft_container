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
    //NOTE - Constructor
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> first;                                
    // std::vector<int> second (4,100);                      
    // std::vector<int> third (second.begin(),second.end()); 
    // std::vector<int> fourth (third);                       
    // int myints[] = {16,2,77,29};
    // std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    // std::cout << "The contents of fifth are:";
    // for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';

    // //NOTE - Constructor
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> first1;                                
    // ft::vector<int> second1 (4,100);                       
    // ft::vector<int> third1 (second.begin(),second.end());  
    // ft::vector<int> fourth1 (third1);               
    // int myints1[] = {16,2,77,29};
    // ft::vector<int> fifth1 (myints, myints + sizeof(myints) / sizeof(int) );
    // std::cout << "The contents of fifth are:";
    // for (ft::vector<int>::iterator it = fifth1.begin(); it != fifth1.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';

    //NOTE - Assign content (operator=)
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> foo (3,0);
    // std::vector<int> bar (5,0);
    // bar = foo;
    // foo = std::vector<int>();
    // std::cout << "Size of foo: " << int(foo.size()) << '\n';
    // std::cout << "Size of bar: " << int(bar.size()) << '\n';

    // //NOTE - Assign content (operator=)
    // std::cout << "------------- Library FT -------------" << std::endl;
    // std::vector<int> foo1 (3,0);
    // std::vector<int> bar1 (5,0);
    // bar1 = foo1;
    // foo1 = std::vector<int>();
    // std::cout << "Size of foo: " << int(foo1.size()) << '\n';
    // std::cout << "Size of bar: " << int(bar1.size()) << '\n';

    //NOTE - Return iterator to beginning
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector;
    // for (int i=1; i<=5; i++) myvector.push_back(i);
    // std::cout << "myvector contains:";
    // for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    
    // //NOTE - Return iterator to beginning
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // for (int i=1; i<=5; i++) myvector1.push_back(i);
    // std::cout << "myvector contains:";
    // for (ft::vector<int>::iterator it = myvector1.begin() ; it != myvector1.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';

    //NOTE - Return iterator to end
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector;
    // for (int i=1; i<=5; i++) myvector.push_back(i);
    // std::cout << "myvector contains:";
    // for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    
    // //NOTE - Return iterator to end
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // for (int i=1; i<=5; i++) myvector1.push_back(i);
    // std::cout << "myvector contains:";
    // for (ft::vector<int>::iterator it = myvector1.begin() ; it != myvector1.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';

    //NOTE - Return reverse iterator to reverse beginning
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector (5);  // 5 default-constructed ints
    // int i=0;
    // std::vector<int>::reverse_iterator rit = myvector.rbegin();
    // for (; rit!= myvector.rend(); ++rit)
    //     *rit = ++i;
    // std::cout << "myvector contains:";
    // for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    
    //NOTE - Return reverse iterator to reverse beginning
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1 (5);  // 5 default-constructed ints
    // int i1=0;
    // ft::vector<int>::reverse_iterator rit1 = myvector1.rbegin();
    // for (; rit1!= myvector1.rend(); ++rit1)
    //     *rit1 = ++i1;
    // std::cout << "myvector contains:";
    // for (ft::vector<int>::iterator it1 = myvector1.begin(); it1 != myvector1.end(); ++it1)
    //     std::cout << ' ' << *it1;
    // std::cout << '\n';

    //NOTE - Return reverse iterator to reverse end
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector (5); 
    // std::vector<int>::reverse_iterator rit = myvector.rbegin();
    // int i=0;
    // for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
    //     *rit = ++i;
    // std::cout << "myvector contains:";
    // for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    
    //NOTE - Return reverse iterator to reverse end
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1 (5); 
    // ft::vector<int>::reverse_iterator rit1 = myvector1.rbegin();
    // int i1=0;
    // for (rit1 = myvector1.rbegin(); rit1!= myvector1.rend(); ++rit1)
    //     *rit1 = ++i1;
    // std::cout << "myvector contains:";
    // for (ft::vector<int>::iterator it1 = myvector1.begin(); it1 != myvector1.end(); ++it1)
    //     std::cout << ' ' << *it1;
    // std::cout << '\n';

    //NOTE - Return size
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myints;
    // std::cout << "0. size: " << myints.size() << '\n';
    // for (int i=0; i<10; i++) myints.push_back(i);
    // std::cout << "1. size: " << myints.size() << '\n';
    // myints.insert (myints.end(),10,100);
    // std::cout << "2. size: " << myints.size() << '\n';
    // myints.pop_back();
    // std::cout << "3. size: " << myints.size() << '\n';
    
    //NOTE - Return size
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myints1;
    // std::cout << "0. size: " << myints1.size() << '\n';
    // for (int i=0; i<10; i++) myints1.push_back(i);
    // std::cout << "1. size: " << myints1.size() << '\n';
    // myints1.insert (myints1.end(),10,100);
    // std::cout << "2. size: " << myints1.size() << '\n';
    // myints1.pop_back();
    // std::cout << "3. size: " << myints1.size() << '\n';

    //NOTE - Return maximum size
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector;
    // for (int i=0; i<100; i++) myvector.push_back(i);
    // std::cout << "size: " << myvector.size() << "\n";
    // std::cout << "capacity: " << myvector.capacity() << "\n";
    // std::cout << "max_size: " << myvector.max_size() << "\n"; 
    
    //NOTE - Return maximum size
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // for (int i=0; i<100; i++) myvector1.push_back(i);
    // std::cout << "size: " << myvector1.size() << "\n";
    // std::cout << "capacity: " << myvector1.capacity() << "\n";
    // std::cout << "max_size: " << myvector1.max_size() << "\n";

    //NOTE - Change size
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector;
    // for (int i=1;i<10;i++) myvector.push_back(i);
    // myvector.resize(5);
    // myvector.resize(8,100);
    // myvector.resize(12);
    // std::cout << "myvector contains:";
    // for (int i=0;i<myvector.size();i++)
    //     std::cout << ' ' << myvector[i];
    // std::cout << '\n';
    
    //NOTE - Change size
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // for (int i=1;i<10;i++) myvector1.push_back(i);
    // myvector1.resize(5);
    // myvector1.resize(8,100);
    // myvector1.resize(12);
    // std::cout << "myvector contains:";
    // for (int i=0;i<myvector1.size();i++)
    //     std::cout << ' ' << myvector1[i];
    // std::cout << '\n';

    //NOTE - Return size of allocated storage capacity
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector;
    // for (int i=0; i<100; i++) myvector.push_back(i);
    // std::cout << "size: " << (int) myvector.size() << '\n';
    // std::cout << "capacity: " << (int) myvector.capacity() << '\n';
    // std::cout << "max_size: " << (int) myvector.max_size() << '\n';
    
    //NOTE - Return size of allocated storage capacity
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // for (int i=0; i<100; i++) myvector1.push_back(i);
    // std::cout << "size: " << (int) myvector1.size() << '\n';
    // std::cout << "capacity: " << (int) myvector1.capacity() << '\n';
    // std::cout << "max_size: " << (int) myvector1.max_size() << '\n';

    //NOTE - Test whether vector is empty
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector;
    // int sum (0);
    // for (int i=1;i<=10;i++) myvector.push_back(i);
    // while (!myvector.empty())
    // {
    //     sum += myvector.back();
    //     myvector.pop_back();
    // }
    // std::cout << "total: " << sum << '\n';
    
    //NOTE - Test whether vector is empty
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // int sum1 (0);
    // for (int i=1;i<=10;i++) myvector1.push_back(i);
    // while (!myvector1.empty())
    // {
    //     sum1 += myvector1.back();
    //     myvector1.pop_back();
    // }
    // std::cout << "total: " << sum1 << '\n';

    //NOTE - Request a change in capacity
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int>::size_type sz;
    // std::vector<int> foo;
    // sz = foo.capacity();
    // std::cout << "making foo grow:\n";
    // for (int i=0; i<100; ++i) {
    //     foo.push_back(i);
    //     if (sz!=foo.capacity()) {
    //     sz = foo.capacity();
    //     std::cout << "capacity changed: " << sz << '\n';
    //     }
    // }
    // std::vector<int> bar;
    // sz = bar.capacity();
    // bar.reserve(100);   // this is the only difference with foo above
    // std::cout << "making bar grow:\n";
    // for (int i=0; i<100; ++i) {
    //     bar.push_back(i);
    //     if (sz!=bar.capacity()) {
    //     sz = bar.capacity();
    //     std::cout << "capacity changed: " << sz << '\n';
    //     }
    // }
    
    //NOTE - Request a change in capacity
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int>::size_type sz1;
    // ft::vector<int> foo1;
    // sz1 = foo1.capacity();
    // std::cout << "making foo grow:\n";
    // for (int i=0; i<100; ++i) {
    //     foo1.push_back(i);
    //     if (sz1!=foo1.capacity()) {
    //     sz1 = foo1.capacity();
    //     std::cout << "capacity changed: " << sz1 << '\n';
    //     }
    // }
    // ft::vector<int> bar1;
    // sz1 = bar1.capacity();
    // bar1.reserve(100);   // this is the only difference with foo above
    // std::cout << "making bar grow:\n";
    // for (int i=0; i<100; ++i) {
    //     bar1.push_back(i);
    //     if (sz1!=bar1.capacity()) {
    //     sz1 = bar1.capacity();
    //     std::cout << "capacity changed: " << sz1 << '\n';
    //     }
    // }

    //NOTE - Access element
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector (10);
    // std::vector<int>::size_type sz = myvector.size();
    // for (unsigned i=0; i<sz; i++) myvector[i]=i;
    // for (unsigned i=0; i<sz/2; i++)
    // {
    //     int temp;
    //     temp = myvector[sz-1-i];
    //     myvector[sz-1-i]=myvector[i];
    //     myvector[i]=temp;
    // }
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<sz; i++)
    //     std::cout << ' ' << myvector[i];
    // std::cout << '\n';
    
    //NOTE - Access element
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1 (10);
    // ft::vector<int>::size_type sz1 = myvector1.size();
    // for (unsigned i=0; i<sz1; i++) myvector1[i]=i;
    // for (unsigned i=0; i<sz1/2; i++)
    // {
    //     int temp1;
    //     temp1 = myvector1[sz1-1-i];
    //     myvector1[sz1-1-i]=myvector1[i];
    //     myvector1[i]=temp1;
    // }
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<sz; i++)
    //     std::cout << ' ' << myvector1[i];
    // std::cout << '\n';

    //NOTE - Access element
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector (10);
    // for (unsigned i=0; i<myvector.size(); i++)
    //     myvector.at(i)=i;
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector.size(); i++)
    //     std::cout << ' ' << myvector.at(i);
    // std::cout << '\n';
    
    //NOTE - Access element
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1 (10);
    // for (unsigned i=0; i<myvector1.size(); i++)
    //     myvector1.at(i)=i;
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector1.size(); i++)
    //     std::cout << ' ' << myvector1.at(i);
    // std::cout << '\n';

    //NOTE - Access first element
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector;
    // myvector.push_back(78);
    // myvector.push_back(16);
    // myvector.front() -= myvector.back();
    // std::cout << "myvector.front() is now " << myvector.front() << '\n';
    
    //NOTE - Access first element
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // myvector1.push_back(78);
    // myvector1.push_back(16);
    // myvector1.front() -= myvector1.back();
    // std::cout << "myvector.front() is now " << myvector1.front() << '\n';

    //NOTE - Access last element
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector;
    // myvector.push_back(10);
    // while (myvector.back() != 0)
    // {
    //     myvector.push_back ( myvector.back() -1 );
    // }
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector.size() ; i++)
    //     std::cout << ' ' << myvector[i];
    // std::cout << '\n';
    
    //NOTE - Access last element
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // myvector1.push_back(10);
    // while (myvector1.back() != 0)
    // {
    //     myvector1.push_back ( myvector1.back() -1 );
    // }
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector1.size() ; i++)
    //     std::cout << ' ' << myvector1[i];
    // std::cout << '\n';

    //NOTE - Assign vector content
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> first;
    // std::vector<int> second;
    // std::vector<int> third;
    // first.assign (7,100);          
    // std::vector<int>::iterator it;
    // it=first.begin()+1;
    // second.assign (it,first.end()-1);
    // int myints[] = {1776,7,4};
    // third.assign (myints,myints+3);
    // std::cout << "Size of first: " << int (first.size()) << '\n';
    // std::cout << "Size of second: " << int (second.size()) << '\n';
    // std::cout << "Size of third: " << int (third.size()) << '\n';
    
    //NOTE - Assign vector content
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> first1;
    // ft::vector<int> second1;
    // ft::vector<int> third1;
    // first1.assign (7,100);          
    // ft::vector<int>::iterator it1;
    // it1=first1.begin()+1;
    // second1.assign (it1,first1.end()-1);
    // int myints1[] = {1776,7,4};
    // third1.assign (myints1,myints1+3);
    // std::cout << "Size of first: " << int (first1.size()) << '\n';
    // std::cout << "Size of second: " << int (second1.size()) << '\n';
    // std::cout << "Size of third: " << int (third1.size()) << '\n';

    //NOTE - Add element at the end
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector;
    // int myint;
    // std::cout << "Please enter some integers (enter 0 to end):\n";
    // do {
    //     std::cin >> myint;
    //     myvector.push_back (myint);
    // } while (myint);
    // std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
    
    //NOTE - Add element at the end
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // int myint1;
    // std::cout << "Please enter some integers (enter 0 to end):\n";
    // do {
    //     std::cin >> myint1;
    //     myvector1.push_back (myint1);
    // } while (myint1);
    // std::cout << "myvector stores " << int(myvector1.size()) << " numbers.\n";

    //NOTE - Delete last element
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector;
    // int sum (0);
    // myvector.push_back (100);
    // myvector.push_back (200);
    // myvector.push_back (300);
    // while (!myvector.empty())
    // {
    //     sum+=myvector.back();
    //     myvector.pop_back();
    // }
    // std::cout << "The elements of myvector add up to " << sum << '\n';
    
    //NOTE - Delete last element
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // int sum1 (0);
    // myvector1.push_back (100);
    // myvector1.push_back (200);
    // myvector1.push_back (300);
    // while (!myvector1.empty())
    // {
    //     sum1+=myvector1.back();
    //     myvector1.pop_back();
    // }
    // std::cout << "The elements of myvector add up to " << sum1 << '\n';

    //NOTE - Clear content
    // std::cout << "------------- Library STD -------------" << std::endl;
    // std::vector<int> myvector;
    // myvector.push_back (100);
    // myvector.push_back (200);
    // myvector.push_back (300);
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector.size(); i++)
    //     std::cout << ' ' << myvector[i];
    // std::cout << '\n';
    // myvector.clear();
    // myvector.push_back (1101);
    // myvector.push_back (2202);
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector.size(); i++)
    //     std::cout << ' ' << myvector[i];
    // std::cout << '\n';
    
    //NOTE - Clear content
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // myvector1.push_back (100);
    // myvector1.push_back (200);
    // myvector1.push_back (300);
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector1.size(); i++)
    //     std::cout << ' ' << myvector1[i];
    // std::cout << '\n';
    // myvector1.clear();
    // myvector1.push_back (1101);
    // myvector1.push_back (2202);
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector1.size(); i++)
    //     std::cout << ' ' << myvector1[i];
    // std::cout << '\n';

    //NOTE - Insert elements
    std::cout << "------------- Library STD -------------" << std::endl;
    std::vector<int> myvector (3,100);
    std::vector<int>::iterator it;
    it = myvector.begin();
    it = myvector.insert ( it , 200 );
    std::cout << myvector.size() << std::endl;
    std::cout << myvector.capacity() << std::endl;
    for (size_t i = 0; i < myvector.size(); i++)
    {
        std::cout << myvector[i] << std::endl;
    }
    std::cout << "------------- Library FT -------------" << std::endl;
    ft::vector<int> myvector1 (3,100);
    ft::vector<int>::iterator it1;
    it1 = myvector1.begin();
    it1 = myvector1.insert ( it1 , 200 );
    std::cout << myvector.size() << std::endl;
    std::cout << myvector.capacity() << std::endl;
    for (size_t i = 0; i < myvector1.size(); i++)
    {
        std::cout << myvector1[i] << std::endl;
    }
    
    // myvector.insert (it,2,300);
    // it = myvector.begin();
    // std::vector<int> anothervector (2,400);
    // myvector.insert (it+2,anothervector.begin(),anothervector.end());
    // int myarray [] = { 501,502,503 };
    // myvector.insert (myvector.begin(), myarray, myarray+3);
    // std::cout << "myvector contains:";
    // for (it=myvector.begin(); it<myvector.end(); it++)
    //     std::cout << ' ' << *it;
    std::cout << '\n';

}