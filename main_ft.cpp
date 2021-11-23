#include "Vector.hpp"
#include "Stack.hpp"
#include "Map.hpp"
#include <iostream>
#include <map>


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
    // *************************************************************************
                                //NOTE - Vector
    // *************************************************************************

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

    // //NOTE - Assign content (operator=)
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> foo1 (3,0);
    // ft::vector<int> bar1 (5,0);
    // bar1 = foo1;
    // foo1 = ft::vector<int>();
    // std::cout << "Size of foo: " << int(foo1.size()) << '\n';
    // std::cout << "Size of bar: " << int(bar1.size()) << '\n';

    // //NOTE - Return iterator to beginning
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // for (int i=1; i<=5; i++) myvector1.push_back(i);
    // std::cout << "myvector contains:";
    // for (ft::vector<int>::iterator it = myvector1.begin() ; it != myvector1.end(); ++it)
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
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // for (int i=0; i<100; i++) myvector1.push_back(i);
    // std::cout << "size: " << myvector1.size() << "\n";
    // std::cout << "capacity: " << myvector1.capacity() << "\n";
    // std::cout << "max_size: " << myvector1.max_size() << "\n";

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
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // for (int i=0; i<100; i++) myvector1.push_back(i);
    // std::cout << "size: " << (int) myvector1.size() << '\n';
    // std::cout << "capacity: " << (int) myvector1.capacity() << '\n';
    // std::cout << "max_size: " << (int) myvector1.max_size() << '\n';

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
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1 (10);
    // for (unsigned i=0; i<myvector1.size(); i++)
    //     myvector1.at(i)=i;
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector1.size(); i++)
    //     std::cout << ' ' << myvector1.at(i);
    // std::cout << '\n'; 

    //NOTE - Access first element
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // myvector1.push_back(78);
    // myvector1.push_back(16);
    // myvector1.front() -= myvector1.back();
    // std::cout << "myvector.front() is now " << myvector1.front() << '\n';

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
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // myvector1.push_back (100);
    // myvector1.push_back (200);
    // myvector1.push_back (300);
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector1.size(); i++)
    //     std::cout << ' ' << myvector1[i];
    // std::cout << '\n';
    // std::cout << myvector1.size() << std::endl;
    // std::cout << myvector1.capacity() << std::endl;
    // myvector1.clear();
    // std::cout << myvector1.size() << std::endl;
    // std::cout << myvector1.capacity() << std::endl;
    // myvector1.push_back (1101);
    // myvector1.push_back (2202);
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector1.size(); i++)
    //     std::cout << ' ' << myvector1[i];
    // std::cout << '\n';

    //NOTE - Insert elements
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1(3, 100);
    // std::cout << myvector1.size() << std::endl;
    // std::cout << myvector1.capacity() << std::endl;
    // ft::vector<int>::iterator it1;
    // it1 = myvector1.begin();
    // it1 = myvector1.insert ( it1, 200 );
    // myvector1.insert(it1, 2, 300);
    // it1 = myvector1.begin();
    // ft::vector<int> anothervector1 (2,400);
    // std::cout << myvector1.size() << std::endl;
    // std::cout << myvector1.capacity() << std::endl;
    // myvector1.insert (it1+2,anothervector1.begin(),anothervector1.end());
    // std::cout << myvector1.size() << std::endl;
    // std::cout << myvector1.capacity() << std::endl;
    // int myarray1 [] = { 501,502,503 };
    // myvector1.insert (myvector1.begin(), myarray1, myarray1+3);
    // std::cout << "myvector contains:";
    // for (it1=myvector1.begin(); it1<myvector1.end(); it1++)
    //     std::cout << ' ' << *it1;
    // std::cout << '\n';

    // ft::vector<int> vec1;
    // vec1.push_back(10);
    // vec1.push_back(20);
    // vec1.push_back(30);
    // vec1.push_back(40);
    // ft::vector<int>::iterator it1 = vec1.insert(vec1.begin(), 3);
    // vec1.insert(it1, 2);
    // int i1 = 2;
    // it1 = vec1.insert(vec1.begin() + i1, 7);
    // std::cout << "The vector elements are: ";
    // for (ft::vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end(); ++it1)
    //     std::cout << *it1 << " ";

    //NOTE - Erase elements
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector1;
    // for (int i=1; i<=10; i++) myvector1.push_back(i);
    // std::cout << myvector1.size() << std::endl;
    // std::cout << myvector1.capacity() << std::endl;
    // myvector1.erase (myvector1.begin() - 1);
    // myvector1.erase (myvector1.begin(),myvector1.begin()+3);
    // std::cout << myvector1.size() << std::endl;
    // std::cout << myvector1.capacity() << std::endl;
    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector1.size(); ++i)
    //     std::cout << ' ' << myvector1[i];
    // std::cout << std::endl;

    //NOTE - Swap content
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> foo1(3, 100);   // three ints with a value of 100
    // ft::vector<int> bar1(5, 200);   // five ints with a value of 200
    // std::cout << "Size foo1 before " << foo1.size() << std::endl;
    // std::cout << "Capa foo1 before " << foo1.capacity() << std::endl;
    // std::cout << "Size bar1 before " << bar1.size() << std::endl;
    // std::cout << "Capa bar1 before " << bar1.capacity() << std::endl;
    // foo1.swap(bar1);
    // std::cout << "Size foo1 after " << foo1.size() << std::endl;
    // std::cout << "Capa foo1 after " << foo1.capacity() << std::endl;
    // std::cout << "Size bar1 after " << bar1.size() << std::endl;
    // std::cout << "Capa bar1 after " << bar1.capacity() << std::endl;
    // std::cout << "foo contains:";
    // for (unsigned i=0; i<foo1.size(); i++)
    //     std::cout << ' ' << foo1[i];
    // std::cout << '\n';
    // std::cout << "bar contains:";
    // for (unsigned i=0; i<bar1.size(); i++)
    //     std::cout << ' ' << bar1[i];
    // std::cout << '\n';

    //NOTE - Get allocator
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector;
    // int * p;
    // unsigned int i;
    // p = myvector.get_allocator().allocate(5);
    // for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
    // std::cout << "The allocated array contains:";
    // for (i=0; i<5; i++) std::cout << ' ' << p[i];
    // std::cout << '\n';
    // for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
    // myvector.get_allocator().deallocate(p,5);
    
    //NOTE - Relational operators for vector
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> foo (1,200);
    // ft::vector<int> bar (0);
    // if (foo==bar) std::cout << "foo and bar are equal\n";
    // if (foo!=bar) std::cout << "foo and bar are not equal\n";
    // if (foo< bar) std::cout << "foo is less than bar\n";
    // if (foo> bar) std::cout << "foo is greater than bar\n";
    // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    // if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    
    //NOTE - Exchange contents of vectors
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> foo (3,100);   // three ints with a value of 100
    // ft::vector<int> bar (5,200);   // five ints with a value of 200
    // ft::swap(foo, bar);
    // std::cout << "foo contains:";
    // for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    // std::cout << "bar contains:";
    // for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    
    // *************************************************************************
                                //NOTE - Stack
    // *************************************************************************

    //NOTE - ft::stack::stack
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::vector<int> myvector (2,200);        // vector with 2 elements
    // ft::stack<int> first;                    // empty stack
    // ft::stack<int> third;  // empty stack using vector
    // ft::stack<int> fourth (myvector);
    // std::cout << "size of first: " << first.size() << '\n';
    // std::cout << "size of third: " << third.size() << '\n';
    // std::cout << "size of fourth: " << fourth.size() << '\n';

    //NOTE - ft::stack::empty
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::stack<int> mystack;
    // int sum (0);
    // for (int i=1;i<=10;i++) mystack.push(i);
    // while (!mystack.empty())
    // {
    //     sum += mystack.top();
    //     mystack.pop();
    // }
    // std::cout << "total: " << sum << '\n';

    //NOTE - ft::stack::size
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::stack<int> myints;
    // std::cout << "0. size: " << myints.size() << '\n';
    // for (int i=0; i<5; i++) myints.push(i);
    // std::cout << "1. size: " << myints.size() << '\n';
    // myints.pop();
    // std::cout << "2. size: " << myints.size() << '\n';

    //NOTE - ft::stack::top
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::stack<int> mystack;
    // mystack.push(10);
    // mystack.push(20);
    // mystack.top() -= 5;
    // std::cout << "mystack.top() is now " << mystack.top() << '\n';

    //NOTE - ft::stack::push
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::stack<int> mystack;
    // for (int i=0; i<5; ++i) mystack.push(i);
    // std::cout << "Popping out elements...";
    // while (!mystack.empty())
    // {
    //     std::cout << ' ' << mystack.top();
    //     mystack.pop();
    // }
    // std::cout << '\n';

    //NOTE - ft::stack::pop
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::stack<int> mystack;
    // for (int i=0; i<5; ++i) mystack.push(i);
    // std::cout << "Popping out elements...";
    // while (!mystack.empty())
    // {
    //     std::cout << ' ' << mystack.top();
    //     mystack.pop();
    // }
    // std::cout << '\n';

    //NOTE - operator==
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::stack <int, ft::vector<int> > s1, s2, s3;
    // s1.push( 1 );
    // s2.push( 2 );
    // s3.push( 1 );

    // if ( s1 == s2 )
    //     std::cout << "The stacks s1 and s2 are equal." << std::endl;
    // else
    //     std::cout << "The stacks s1 and s2 are not equal." << std::endl;

    // if ( s1 == s3 )
    //     std::cout << "The stacks s1 and s3 are equal." << std::endl;
    // else
    //     std::cout << "The stacks s1 and s3 are not equal." << std::endl;
    
    //NOTE - operator!=
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::stack <int, ft::vector<int> > s1, s2, s3;
    // s1.push( 1 );
    // s2.push( 2 );
    // s3.push( 1 );
    // if ( s1 != s2 )
    //     std::cout << "The stacks s1 and s2 are not equal." << std::endl;
    // else
    //     std::cout << "The stacks s1 and s2 are equal." << std::endl;
    // if ( s1 != s3 )
    //     std::cout << "The stacks s1 and s3 are not equal." << std::endl;
    // else
    //     std::cout << "The stacks s1 and s3 are equal." << std::endl;
    
    //NOTE - operator<
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::stack <int, ft::vector<int> > s1, s2, s3;
    // s1.push( 2 );
    // s1.push( 4 );
    // s1.push( 6 );
    // s1.push( 8 );
    // s2.push( 5 );
    // s2.push( 10 );
    // s3.push( 2 );
    // s3.push( 4 );
    // s3.push( 6 );
    // s3.push( 8 );
    // if ( s1 < s2 )
    //     std::cout << "The stack s1 is less than "
    //         << "the stack s2." << std::endl;
    // else
    //     std::cout << "The stack s1 is greater than or equal to "
    //         << "the stack s2." << std::endl;

    // if ( s1 < s3 )
    //     std::cout << "The stack s1 is less than "
    //         << "the stack s3." << std::endl;
    // else
    //     std::cout << "The stack s1 is greater than to "
    //         << "the stack s3." << std::endl;
    // ft::stack <int>::size_type i_size_s1 = s1.size( );
    // std::cout << "The stack s1 from the top down is: ( ";
    // unsigned int i;
    // for ( i = 1 ; i <= i_size_s1 ; i++ )
    // {
    //     std::cout << s1.top( ) << " ";
    //     s1.pop( );
    // }
    // std::cout << ")." << std::endl;

    //NOTE - operator<=
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::stack <int> s1, s2, s3;
    // s1.push( 5 );
    // s1.push( 10 );
    // s2.push( 1 );
    // s2.push( 2 );
    // s3.push( 5 );
    // s3.push( 10 );
    // if ( s1 <= s2 )
    //     std::cout << "The stack s1 is less than or equal to "
    //         << "the stack s2." << std::endl;
    // else
    //     std::cout << "The stack s1 is greater than "
    //         << "the stack s2." << std::endl;

    // if ( s1 <= s3 )
    //     std::cout << "The stack s1 is less than or equal to "
    //         << "the stack s3." << std::endl;
    // else
    //     std::cout << "The stack s1 is greater than "
    //         << "the stack s3." << std::endl;

    //NOTE - operator>
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::stack <int, ft::vector<int> > s1, s2, s3;
    // s1.push( 1 );
    // s1.push( 2 );
    // s1.push( 3 );
    // s2.push( 5 );
    // s2.push( 10 );
    // s3.push( 1 );
    // s3.push( 2 );
    // if ( s1 > s2 )
    //     std::cout << "The stack s1 is greater than "
    //         << "the stack s2." << std::endl;
    // else
    //     std::cout << "The stack s1 is not greater than "
    //         << "the stack s2." << std::endl;

    // if ( s1 > s3 )
    //     std::cout << "The stack s1 is greater than "
    //         << "the stack s3." << std::endl;
    // else
    //     std::cout << "The stack s1 is not greater than "
    //         << "the stack s3." << std::endl;

    //NOTE - operator>=
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::stack <int, ft::vector<int> > s1, s2, s3;
    // s1.push( 1 );
    // s1.push( 2 );
    // s2.push( 5 );
    // s2.push( 10 );
    // s3.push( 1 );
    // s3.push( 2 );
    // if ( s1 >= s2 )
    //     std::cout << "The stack s1 is greater than or equal to "
    //         << "the stack s2." << std::endl;
    // else
    //     std::cout << "The stack s1 is less than "
    //         << "the stack s2." << std::endl;

    // if ( s1>= s3 )
    //     std::cout << "The stack s1 is greater than or equal to "
    //         << "the stack s3." << std::endl;
    // else
    //     std::cout << "The stack s1 is less than "
    //         << "the stack s3." << std::endl;


    // *************************************************************************
                                //NOTE - Map
    // *************************************************************************
    
    //NOTE - Construct pair
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::pair <std::string,double> product1;
    // ft::pair <std::string,double> product2 ("tomatoes",2.30);
    // ft::pair <std::string,double> product3 (product2);
    // product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)
    // product2.first = "shoes";
    // product2.second = 39.90;
    // std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    // std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    // std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';


    //NOTE - pair::operator= example
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::pair <std::string,int> planet("Earth",6371), homeplanet;
    // planet = ft::make_pair("Earth",6371);
    // homeplanet = planet;
    // std::cout << "Home planet: " << homeplanet.first << '\n';
    // std::cout << "Planet size: " << homeplanet.second << '\n';


    //NOTE - make_pair example
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::pair <int,int> foo;
    // ft::pair <int,int> bar;
    // foo = ft::make_pair (10,20);
    // bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>
    // std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
    // std::cout << "bar: " << bar.first << ", " << bar.second << '\n';


    //NOTE - Relational operators for pair
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::pair<int,char> foo (10,'z');
    // ft::pair<int,char> bar (90,'a');
    // if (foo==bar) std::cout << "foo and bar are equal\n";
    // if (foo!=bar) std::cout << "foo and bar are not equal\n";
    // if (foo< bar) std::cout << "foo is less than bar\n";
    // if (foo> bar) std::cout << "foo is greater than bar\n";
    // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    // if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

    //NOTE - Construct map
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::map<char,int> first;
    // first['a']=10;
    // first['b']=30;
    // first['c']=50;
    // first['d']=70;
    // ft::map<char,int> second (first.begin(),first.end());
    // for (ft::map<char, int>::iterator i = second.begin(); i != second.end(); i++)
    // {
    //     std::cout << i->first << "\t" << i->second << std::endl;
    // }

    //NOTE - Access element
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::map<char,std::string> mymap;
    // mymap['a']="an element";
    // mymap['b']="another element";
    // mymap['c']=mymap['b'];
    // std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    // std::cout << "mymap['b'] is " << mymap['b'] << '\n';
    // std::cout << "mymap['c'] is " << mymap['c'] << '\n';
    // std::cout << "mymap['d'] is " << mymap['d'] << '\n';
    // std::cout << "mymap now contains " << mymap.size() << " elements.\n";

    //NOTE - Test whether container is empty
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::map<char,int> mymap;
    // mymap['a']=10;
    // mymap['b']=20;
    // mymap['c']=30;
    // while (!mymap.empty())
    // {
    //     std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    //     mymap.erase(mymap.begin());
    // }

    //NOTE - Return maximum size
    // std::cout << "------------- Library FT -------------" << std::endl;
    // int i;
    // ft::map<int,int> mymap;
    // if (mymap.max_size()>1000)
    // {
    //     for (i=0; i<1000; i++) mymap[i]=0;
    //     std::cout << "The map contains 1000 elements.\n";
    // }
    // std::cout << mymap.max_size() << std::endl;

    //NOTE - Insert elements
    // std::cout << "------------- Library FT -------------" << std::endl;
    // // first insert function version (single parameter):
    // ft::map<char,int> mymap;
    // mymap.insert ( ft::pair<char,int>('a',100) );
    // mymap.insert ( ft::pair<char,int>('z',200) );
    // ft::pair<ft::map<char,int>::iterator,bool> ret;
    // ret = mymap.insert ( ft::pair<char,int>('z',500) );
    // if (ret.second==false) {
    //     std::cout << "element 'z' already existed";
    //     std::cout << " with a value of " << ret.first->second << '\n';
    // }
    // std::cout << mymap.size() << std::endl;
    // // second insert function version (with hint position):
    // ft::map<char,int>::iterator it = mymap.begin();
    // mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
    // mymap.insert (it, ft::pair<char,int>('c',400));
    // std::cout << "mymap contains:\n";
    // for (it=mymap.begin(); it!=mymap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';
    // // third insert function version (range insertion):
    // ft::map<char,int> anothermap;
    // anothermap.insert(mymap.begin(),mymap.end());
    // for (ft::map<char, int>::iterator i = anothermap.begin(); i != anothermap.end(); i++)
    // {
    //     std::cout << i->first << "\t" << i->second << std::endl;
    // }

    //NOTE - Clear content
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::map<char,int> mymap;
    // mymap['x']=100;
    // mymap['y']=200;
    // mymap['z']=300;
    // std::cout << "mymap contains:\n";
    // for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';
    // mymap.clear();
    // mymap['a']=1101;
    // mymap['b']=2202;
    // std::cout << "mymap contains:\n";
    // for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';
    
    //NOTE - Assignement Operator (new_map = old_map)
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::map<char,int> first;
    // ft::map<char,int> second;
    // first['x']=8;
    // first['y']=16;
    // first['z']=32;
    // second=first;                // second now contains 3 ints
    // first = ft::map<char,int>();  // and first is now empty
    // std::cout << "Size of first: " << first.size() << '\n';
    // std::cout << "Size of second: " << second.size() << '\n';

    //NOTE - Erase elements
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::map<char,int> mymap;
    // // insert some values:
    // mymap['a']=10;
    // mymap['b']=20;
    // mymap['c']=30;
    // mymap['d']=40;
    // mymap['e']=50;
    // mymap['f']=60;
    // ft::map<char,int>::iterator it = mymap.begin();
    // // it=mymap.find('b');
    // mymap.erase(it, mymap.end());                   // erasing by iterator
    // mymap.erase ('c');                  // erasing by key
    
    // // it=mymap.find ('e');
    // // mymap.erase ( it, mymap.end() );    // erasing by range
    // // show content:
    // for (it=mymap.begin(); it!=mymap.end(); ++it)
    // {     
    //     std::cout << it->first << " => " << it->second << '\n';
    // }

    //NOTE - Swap content
    // std::cout << "------------- Library FT -------------" << std::endl;
    // ft::map<char,int> foo,bar;
    // foo['x']=100;
    // foo['y']=200;

    // bar['a']=11;
    // bar['b']=22;
    // bar['c']=33;
    // foo.swap(bar);
    // std::cout << "foo contains:\n";
    // for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    // {
    //     std::cout << it->first << " => " << it->second << '\n';
    // }
    // std::cout << "bar contains:\n";
    // for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';

    //NOTE - Return key comparison object
    std::cout << "------------- Library FT -------------" << std::endl;
    ft::map<char,int> mymap;
    ft::map<char,int>::key_compare mycomp = mymap.key_comp();
    mymap['a']=100;
    mymap['b']=200;
    mymap['c']=300;
    std::cout << "mymap contains:\n";
    char highest = mymap.rbegin()->first;     // key value of last element
    ft::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( mycomp((*it++).first, highest) );

    std::cout << '\n';  
    // std::pair<int, int> p551;
    // p551.first = 21;
    // p551.second = 15;
    // std::pair<int, int> p51;
    // p51.first = 18;
    // p51.second = 6;
    // std::pair<int, int> p52;
    // p52.first = 25;
    // p52.second = 20;
    // std::pair<int, int> p53;
    // p53.first = 26;
    // p53.second = 25;
    // std::pair<int, int> p55;
    // p55.first = 19;
    // p55.second = 9;
    // std::pair<int, int> p56;
    // p56.first = 16;
    // p56.second = 3;
    // std::pair<int, int> p57;
    // p57.first = 20;
    // p57.second = 8;
    // std::map<int, int> y;
    // y.insert(p551);
    // y.insert(p51);
    // y.insert(p52);
    // y.insert(p53); // 26
    // y.insert(p55);
    // y.insert(p56);
    // y.insert(p57);
    // std::map<int, int>::iterator it5 = y.begin();
    // std::map<int, int>::iterator ite = y.end();
    // while (it5 != ite)
    // {
    //     std::cout << it5->first << std::endl;
    //     it5++;
    // }
    // ft::pair<int, int> p1;
    // p1.first = 15;
    // p1.second = 15;
    // ft::pair<int, int> p2;
    // p2.first = 13;
    // p2.second = 6;
    // ft::pair<int, int> p3;
    // p3.first = 14;
    // p3.second = 20;
    // ft::pair<int, int> p4;
    // p4.first = 16;
    // p4.second = 20;
    // ft::pair<int, int> p5;
    // p5.first = 12;
    // p5.second = 25;
    // ft::pair<int, int> p5;
    // p5.first = 19;
    // p5.second = 9;
    // ft::pair<int, int> p6;
    // p6.first = 16;
    // p6.second = 3;
    // ft::pair<int, int> p7;
    // p7.first = 20;
    // p7.second = 8;
    // ft::map<int, int>::tree b;
    // b.insert_node(p);
    // b.insert_node(p1);
    // b.insert_node(p2);
    // b.insert_node(p3);
    // b.insert_node(p5);
    // b.print_bst();
    // b.insert_node(p6);
    // b.insert_node(p7);
    // ft::map<int, int>::iterator it6(b.get_min());
    // ft::map<int, int>::iterator it7(b.get_max());
    // std::cout << "my tree" << std::endl;
    // while (it6 != it7)
    // {
    //     std::cout << it6->first << std::endl;
    //     it6++;
    // }
    // b.print_bst();
    // // std::cout << "\nsearch node" << std::endl;
    // ft::node<ft::pair<const int, int> >* ptr = b.search_node(p3);
    // std::cout << "\n search" << ptr->_data.first << ", " << ptr->_data.second << std::endl;
    // std::cout << ptr->parent->_data.first << std::endl;
    // std::cout << "\ndelete node" << std::endl;
    // b.delete_node(p1);
    // b.print_bst();

    // iterator
    // ft::map<int, int>::iterator it(b.get_end());

    // std::cout << "\n" << it->first << " " << it->second << std::endl;
    // std::cout << "\n" << it->first << " " << it->second << std::endl;
    // ft::map<int, int>::reverse_iterator rit(it);
    // --rit;
    // ++rit;
    // std::cout << rit->first << std::endl;
    // std::cout << "\n" << it->first << std::endl;
    // ft::map<int, int>::const_iterator it(b.get_max());
    // ft::map<int, int>::const_iterator it1(b.get_min());
    // --it;
    // std::cout << "\n" << it->first << " " << it->second << std::endl;
    // for (; it != it1; it--)
    // {
    // std::cout << it->first << "\t";
    // std::cout << it->second << std::endl;
    // }
    // it->second = 15;
    // std::cout << it->first << "\t";
    // std::cout << it->second << std::endl;
    // it++;
    // std::cout << it->first << std::endl;
    // std::cout << it->second << std::endl;

    // ft::map<int, int>::tree tr;
    // for (size_t i = 1; i <= 5; i++)
    // {
        // tr.insert_node(ft::make_pair(i, i*2));
        // m.insert(std::make_pair(i, i*2));
        // m[i] = i*2;
    // }
    // tr.insert_node(p1);
    // tr.insert_node(p2);
    // tr.insert_node(p3);
    // tr.insert_node(p4);
    // tr.insert_node(p5);
    // std::cout << tr.size() << std::endl;
    // tr.print_bst();
    // std::cout << "Delete" << std::endl;
    // tr.delete_node(p1);
    // std::cout << tr.size() << std::endl;
    // tr.print_bst();
    // std::cout << "==============" << std::endl;
    // tr.insert_node(ft::make_pair(4, 0));
    // tr.print_bst();
    // std::cout << "==============" << std::endl;
    // tr.insert_node(ft::make_pair(5, 0));
    // tr.print_bst();
    // std::cout << "==============" << std::endl;
    // tr.insert_node(ft::make_pair(6, 0));
    // tr.print_bst();
    // std::cout << "==============" << std::endl;
    // tr.insert_node(ft::make_pair(7, 0));
    // tr.print_bst();
    // ft::map<int, int>::iterator it(tr.get_max());
    // --it;
    // std::cout << "\n" << it->first << std::endl;
    // std::cout << tr.search_node(ft::make_pair(99999, 12))->_data.second << std::endl;
    

    
}