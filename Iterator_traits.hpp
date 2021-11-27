#ifndef ITERATOR_TRAITS
#define ITERATOR_TRAITS

#include <iostream>

namespace ft
{
    //TODO - Define Iterator traits
    template <class T>
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
    template <typename T>
    class iterator_traits<const T*>
    {
        public:
            typedef std::random_access_iterator_tag iterator_category;
            typedef T                               value_type;
            typedef const T*                        pointer;
            typedef const T&                        reference;
            typedef std::ptrdiff_t                  difference_type;
    };
    //TODO - Base Iterator
    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    class iterator 
    {
        public:
            typedef T         value_type;
            typedef Distance  difference_type;
            typedef Pointer   pointer;
            typedef Reference reference;
            typedef Category  iterator_category;
    };
}
#endif