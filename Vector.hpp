#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace ft
{
    // NOTE - Category to which the iterator belongs to
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag {};
    struct bidirectional_iterator_tag {};
    struct random_access_iterator_tag {};

    // TODO - Implement Iterator
    template < class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& > class iterator
    {
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
        typedef Category    iterator_category;
    };

    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        // ANCHOR - This Is Data Structure Will be Used
        private:
            size_t _size;
            size_t _capacity;
            T*  _arr;
            Alloc _alloc;
        public:
        // ANCHOR - This is member types
        typedef T           value_type;
        typedef Alloc       allocator_type;
        typedef T&          reference;
        typedef const T&    const_reference;
        typedef T*          pointer;
        typedef const T*    const_pointer;
        typedef size_t      size_type;
        typedef iterator<random_access_iterator_tag, value_type>        iterator; 
        typedef iterator<random_access_iterator_tag, const value_type>  const_iterator;

        // TODO - Implement Constructor Default (empty)
        vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _arr(nullptr), _alloc(alloc)
        {
        }
        // TODO - Implement Constructor Fill (Parametrize)
        vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
        {
            _size = n;
            _capacity = n;
            _alloc = alloc;
            _arr = _alloc.allocate(_capacity);
            for (size_t i = 0; i < _size; i++)
            {
                _arr[i] = val;
            }
        }
        // TODO - Implement Constructor Range (Range Iterators)
        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0)
        {
            _alloc = alloc;
            while (first != last)
            {
                _size++;
                _capacity++;
                first++;
            }
            _arr = _alloc.allocate(_capacity);
            for (size_t i = 0; i < _size; i++)
            {
                _arr[i] = *(last - 1);
            }
        }
        // TODO - Implement Constructor the Copy
        vector (const vector& x)
        {
            *this = x;
        }
        // TODO - Implement Assignment Operator (operator=)
        vector& operator= (const vector& x)
        {
            if (this != &x)
            {
                _size = x._size;
                _capacity = x._capacity;
                _alloc = x._alloc;
                _arr = _alloc.allocate(_capacity);
                for (size_t i = 0; i < _size; i++)
                {
                    _arr[i] = x._arr[i];
                }
            }
            return (*this);
        }
        //TODO - Implement Destructor (default)
        ~vector()
        {
            delete [] _arr;
        }
    };
}

#endif