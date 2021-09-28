#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        // ANCHOR - This Is Data Structure Will be Used
        private:
            int _size;
            int _capacity;
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
            _arr = _alloc.allocate(_size);
            for (size_t i = 0; i < _size; i++)
            {
                _arr[i] = val;
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
                for (size_t i = 0; i < _size; i++)
                {
                    /* code */
                }
                

            }
        }
    };
}

#endif