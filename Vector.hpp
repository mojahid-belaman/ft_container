#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <limits>

namespace ft
{
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
    // TODO - Implement my_Iterator
    template <class Iterator>
    class vector_iterator : public iterator<std::random_access_iterator_tag, typename iterator_traits<Iterator>::value_type>
    {
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::reference reference;
            typedef typename iterator_traits<Iterator>::pointer pointer;

            // TODO - All iterators must be constructible, copy-constructible, copy-assignable, destructible
            vector_iterator() : _ptr(nullptr) {}

            explicit vector_iterator(iterator_type it) : _ptr(it) {}

            template <class Iter>
            vector_iterator (const vector_iterator<Iter>& it) : _ptr(it._ptr) {}

            iterator_type   base() const {return (_ptr);}

            // TODO - Dereference iterator (public member function )
            reference   operator*() const
            {
                return (*_ptr);
            }
            // TODO - Addition operator (public member function )
            vector_iterator    operator+ (difference_type n) const
            {
                return (_ptr + n);
            }
            // TODO - Increment iterator position (public member function )
            vector_iterator&   operator++()
            {
                _ptr++;
                return (*this);
            }
            vector_iterator    operator++(int)
            {
                vector_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }
            // TODO - Decrease iterator position (public member function )
            vector_iterator&   operator--()
            {
                _ptr--;
                return (*this);
            }
            vector_iterator    operator--(int)
            {
                vector_iterator tmp = *this;
                --(*this);
                return (tmp);
            }
            // TODO - Increases the iterator by n element positions.
            vector_iterator&   operator+=(difference_type n)
            {
                _ptr += n;
                return (*this);
            }
            // TODO - Descreases the iterator by n element positions.
            vector_iterator&   operator-=(difference_type n)
            {
                _ptr -= n;
                return (*this);
            }
            // TODO - Subtraction operator (public member function )
            vector_iterator    operator- (difference_type n) const
            {
                return (_ptr - n);
            } 
            // TODO - Dereference iterator (public member function )
            pointer     operator->() const
            {
                return (_ptr);
            }
            // TODO - Dereference iterator with offset
            reference   operator[] (difference_type n) const
            {
                return (*(_ptr + n));
            }
        private:
            iterator_type _ptr;
    };

    // TODO - Relational operators for iterator (function template )
    template <class Iterator>
    bool operator== (const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator>
    bool operator!= (const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator>
    bool operator< (const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator>
    bool operator<= (const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class Iterator>
    bool operator> (const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator>
    bool operator>= (const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template <class Iterator>
    vector_iterator<Iterator> operator+ (typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator>& itr)
    {
        return (itr.base() + n);
    }
    template <class Iterator>
    typename vector_iterator<Iterator>::difference_type operator- (const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs)
    {
        return (lhs.base() - rhs.base());
    }
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
        typedef vector_iterator<pointer> iterator;
        typedef vector_iterator<const_pointer> const_iterator;

        // TODO - Implement Constructor Default (empty)
        vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _arr(nullptr), _alloc(alloc)
        {
        }
        // TODO - Implement Constructor Fill (Parametrize)
        vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc)
        {
            _arr = _alloc.allocate(_capacity);
            for (size_t i = 0; i < _size; i++)
            {
                _arr[i] = val;
            }
        }
        // TODO - Implement Constructor Range (Range Iterators)
        // template <class InputIterator>
        // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc)
        // {
        //     while (first != last)
        //     {
        //         _size++;
        //         _capacity++;
        //         first++;
        //     }
        //     _arr = _alloc.allocate(_capacity);
        //     for (size_t i = 0; i < _size; i++)
        //     {
        //         _arr[i] = *(last - 1);
        //     }
        // }
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
        // TODO - Returns an iterator pointing to the first element in the vector.
        iterator    begin()
        {
            return (_arr);
        }
        const_iterator  begin() const
        {
            return (_arr);
        }
        //TODO - Returns an iterator referring to the past-the-end element in the vector container.
        iterator    end()
        {
            return (_arr + _size);
        }
        const_iterator  end() const
        {
            return (_arr + _size);
        }
        //TODO - Returns the number of elements in the vector.
        size_type size() const
        {
            return (_size);
        }
        //TODO - Returns the maximum number of elements that the vector can hold.
        size_type max_size() const
        {
            return (std::numeric_limits<size_type>::max());
        }
        //TODO - Resizes the container so that it contains n elements
        void    resize(size_type n, value_type val = value_type())
        {
            allocator_type alloc = allocator_type();
            _alloc = alloc;
            _arr = _alloc.allocate(n);
            for (int i = 0; i < n; i++)
            {
                _arr[i] = val;
            }
            
        }
        //TODO - Implement Destructor (default)
        ~vector()
        {
            delete [] _arr;
        }
    };
}

#endif