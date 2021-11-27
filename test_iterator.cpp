#include <iostream>
#include <vector>

template <class T> //std::vector<int>::iterator
class iterator_traits
{
    public:
        typedef typename T::value_type value_type;
        typedef typename T::difference_type difference_type;
        typedef typename T::iterator_category iterator_category;
        typedef typename T::pointer pointer;
        typedef typename T::reference reference;
};

template <typename T>
class iterator_traits<T*>
{
    public:
        typedef std::random_access_iterator_tag iterator_category;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::ptrdiff_t                  difference_type;
};

template <class MyIter>
void    do_some(MyIter f, MyIter l)
{
    (void)l;
    typedef typename iterator_traits<MyIter>::value_type value_type;
    // typedef typename MyIter::value_type value_type;
    value_type v = *f;
    std::cout << v << std::endl;
}

int main()
{
    std::vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    do_some(v.begin(), v.end());
    // int arr[] = {1, 2, 3, 4};
    // do_some(&arr[0], &arr[3]);

    return (0);
}