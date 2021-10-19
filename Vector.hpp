#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <limits>

namespace ft
{
    //TODO - Define enable_if
    template <bool Cond, class T = void>
    struct enable_if {};
    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    //TODO - Define Is integral
    template <class T> 
    struct is_integral
    {
        static const bool value = false;
    };
    template <>
    struct is_integral<char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<char16_t>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<char32_t>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<wchar_t>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<short int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<long int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<long long int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned short int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned long int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned long long int>
    {
        static const bool value = true;
    };

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
                return vector_iterator(_ptr + n);
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
                return vector_iterator(_ptr - n);
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

    //TODO - Reverse iterator
    template <class Iterator>
    class vector_iterator_reverse : public iterator<std::random_access_iterator_tag, typename iterator_traits<Iterator>::value_type>
    {
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename iterator_traits<Iterator>::pointer             pointer;
            typedef typename iterator_traits<Iterator>::reference           reference;

            //TODO - Constructor Default
            vector_iterator_reverse() : _ptr(nullptr) {}
            //TODO - initialization
            explicit vector_iterator_reverse (iterator_type it) : _ptr(it) {}
            //TODO - copy
            template <class Iter>
            vector_iterator_reverse (const vector_iterator_reverse<Iter>& rev_it) : _ptr(rev_it._ptr) {}
            //TODO - Return base iterator
            iterator_type base() const
            {
                return _ptr;
            }
            //TODO - Dereference iterator
            reference operator*() const
            {
                return (*(--this->base()));
            }
            //TODO - Addition operator
            vector_iterator_reverse operator+ (difference_type n) const
            {
                return vector_iterator_reverse(_ptr - n);
            }
            //TODO - Increment iterator position
            vector_iterator_reverse& operator++()
            {
                --_ptr;
                return (*this);
            }
            vector_iterator_reverse  operator++(int)
            {
                vector_iterator_reverse tmp = *this;
                ++(*this);
                return tmp;
            }
            vector_iterator_reverse& operator+= (difference_type n)
            {
                this->_ptr -= n;
                return (*this);
            }
            vector_iterator_reverse operator- (difference_type n) const
            {
                return vector_iterator_reverse(this->_ptr + n);
            }
            vector_iterator_reverse& operator--()
            {
                return (++(this->base()));
            }
            vector_iterator_reverse  operator--(int)
            {
                vector_iterator_reverse tmp = *this;
                --(*this);
                return (tmp);
            }
            vector_iterator_reverse& operator-= (difference_type n)
            {
                _ptr += n;
                return (*this);
            }
            pointer operator->() const
            {
                return (this->_ptr);
            }
            reference operator[] (difference_type n) const
            {
                return (*(_ptr - n));
            }
        private:
            iterator_type _ptr;
    };
    template <class Iterator>
    bool operator== (const vector_iterator_reverse<Iterator>& lhs, const vector_iterator_reverse<Iterator>& rhs)
    {
        return (rhs.base() == lhs.base());
    }

    template <class Iterator>
    bool operator!= (const vector_iterator_reverse<Iterator>& lhs, const vector_iterator_reverse<Iterator>& rhs)
    {
        return (rhs.base() != lhs.base());
    }

    template <class Iterator>
    bool operator< (const vector_iterator_reverse<Iterator>& lhs, const vector_iterator_reverse<Iterator>& rhs)
    {
        return (rhs.base() < lhs.base());
    }

    template <class Iterator>
    bool operator<= (const vector_iterator_reverse<Iterator>& lhs, const vector_iterator_reverse<Iterator>& rhs)
    {
        return (rhs.base() <= lhs.base());
    }

    template <class Iterator>
    bool operator> (const vector_iterator_reverse<Iterator>& lhs, const vector_iterator_reverse<Iterator>& rhs)
    {
        return (rhs.base() > lhs.base());
    }

    template <class Iterator>
    bool operator>= (const vector_iterator_reverse<Iterator>& lhs, const vector_iterator_reverse<Iterator>& rhs)
    {
        return (rhs.base() >= lhs.base());
    }

    template <class Iterator>
    vector_iterator_reverse<Iterator> operator+ (typename vector_iterator_reverse<Iterator>::difference_type n, const vector_iterator_reverse<Iterator>& rev_it)
    {
        return (*(rev_it.base() - n));
    }

    template <class Iterator>
    typename vector_iterator_reverse<Iterator>::difference_type operator- (const vector_iterator_reverse<Iterator>& lhs, const vector_iterator_reverse<Iterator>& rhs)
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
        typedef T                                           value_type;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef vector_iterator<pointer>                    iterator;
        typedef vector_iterator<const_pointer>              const_iterator;
        typedef vector_iterator_reverse<iterator>           reverse_iterator;
        typedef vector_iterator_reverse<const_iterator>     const_reverse_iterator;
        typedef ptrdiff_t                                   difference_type;
        typedef size_t                                      size_type;
        // TODO - Implement Constructor Default (empty)
        vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _arr(nullptr), _alloc(alloc)
        {
        }
        // TODO - Implement Constructor Fill (Parametrize)
        vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
                : _size(n), _capacity(n), _alloc(alloc)
        {
            _arr = _alloc.allocate(_capacity);
            for (size_t i = 0; i < _size; i++)
            {
                _arr[i] = val;
            }
        }
        // TODO - Implement Constructor Range (Range Iterators)
        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = nullptr) 
                : _size(0), _capacity(0), _alloc(alloc)
        {
            difference_type dt = last - first;
            InputIterator it = first;
            while (it != last)
            {
                _size++;
                _capacity++;
                it++;
            }
            _arr = _alloc.allocate(_capacity);
            for (size_t i = 0; i < static_cast<size_t>(dt); i++)
            {
                _arr[i] = *first;
                first++;
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
        // TODO - Returns an iterator pointing to the first element in the vector.
        iterator    begin()
        {
            return iterator(_arr);
        }
        const_iterator  begin() const
        {
            return const_iterator(_arr);
        }
        //TODO - Returns an iterator referring to the past-the-end element in the vector container.
        iterator    end()
        {
            return iterator(_arr + _size);
        }
        const_iterator  end() const
        {
            return const_iterator(_arr + _size);
        }
        //TODO - Return reverse iterator to reverse beginning
        reverse_iterator rbegin()
        {
            return reverse_iterator(this->end());
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(this->begin());
        }
        //TODO - Return reverse iterator to reverse end
        reverse_iterator rend()
        {
            return reverse_iterator(this->begin());
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(_arr);
        }
        //TODO - All functions the Capacity:
        size_type size() const
        {
            return (_size);
        }
        size_type capacity() const
        {
            return (_capacity);
        }
        size_type max_size() const
        {
            return (std::numeric_limits<size_type>::max());
        }
        bool empty() const
        {
            return (_size == 0);
        }
        void    resize(size_type n, value_type val = value_type())
        {
                if (n > _size)
                {
                    for (size_t i = _size; i < n; i++)
                        push_back(val);
                }
                else if(n < _size)
                {
                    size_type tmp = _size;
                    for (size_t i = n; i < tmp; i++)
                        pop_back();
                }
        }
        void reserve (size_type n)
        {
            if (n > capacity())
            {   
                value_type *new_arr;
                if (n > _capacity * 2)
                {
                    new_arr = _alloc.allocate(n);
                    _capacity = n;
                }
                else
                {
                    new_arr = _alloc.allocate(_capacity * 2);
                    _capacity *= 2;
                }
                for (size_t i = 0; i < size(); i++)
                {
                    new_arr[i] = _arr[i];
                }
                _alloc.deallocate(_arr, _capacity);
                _arr = new_arr;
            }
        }
        //TODO - All functions the Element access: 
        reference operator[] (size_type n)
        {
            return (_arr[n]);
        }
        const_reference operator[] (size_type n) const
        {
            return (_arr[n]);
        }
        reference at (size_type n)
        {
            if (n >= _size)
                throw std::out_of_range("index is not within the bound in the vector.");
            return (_arr[n]);
        }
        const_reference at (size_type n) const
        {
            if (n >= _size)
                throw std::out_of_range("index is not within the bound in the vector.");
            return (_arr[n]);
        }
        reference front()
        {
            return (_arr[0]);
        }
        const_reference front() const
        {
            return (_arr[0]);
        }
        reference back()
        {
            return (_arr[_size - 1]);
        }
        const_reference back() const
        {
            return (_arr[_size - 1]);
        }
        //TODO - All functions the Modifiers:
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last,
                    typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
        {
            difference_type dt = last - first;
            _size = dt;
            _capacity = dt;
            _arr = _alloc.allocate(_capacity);
            for (size_t i = 0; i < _size; i++)
            {
                _arr[i] = *(first + i);
            }
        }
        void assign(size_type n, const value_type& val)
        {
            this->clear();
            for (size_t i = 0; i < n; i++)
                this->push_back(val);
        }
        void push_back(const value_type& val)
        {
            if (_capacity == 0)
            {
                _arr = _alloc.allocate(1);
                _capacity++;
            }
            if (_size == _capacity)
            {
                value_type *new_ptr = _alloc.allocate(_capacity * 2);
                for (size_t i = 0; i < _size; i++)
                {
                    new_ptr[i] = _arr[i];
                }
                _alloc.deallocate(_arr, _capacity);
                _arr = new_ptr;
                _capacity *= 2;

            }
            _arr[_size] = val;
            _size++;
        }
        void pop_back()
        {
            if (_size > 0)
            {
                _alloc.destroy(_arr + (_size - 1));
                _size -= 1;
            }
        }
        iterator insert (iterator position, const value_type& val)
        {   
            size_type pos = position - begin();
            if (_capacity == 0)
            {
                _arr = _alloc.allocate(1);
                _capacity++;
            }
            if (_size == _capacity)
            {
                value_type *new_ptr = _alloc.allocate(_capacity * 2);
                for (size_t i = 0; i < _size; i++)
                {
                    new_ptr[i] = _arr[i];
                }
                _alloc.deallocate(_arr, _capacity);
                _arr = new_ptr;
                _capacity *= 2;

            }
            _arr[_size] = val;
            _size++;
            for (size_t i = _size - 1; i > pos; i--)
            {
                _arr[i] = _arr[i - 1];
            }
            _arr[pos] = val;
            return (_arr + pos);
        }
        void    insert (iterator position, size_type n, const value_type& val)
        {
            size_type pos = position - begin();
            if ((_size + n) > _capacity)
                this->reserve(_size + n);
            for (size_t i = _size; i > pos; i--)
            {
                _arr[i - 1 + n] = _arr[i - 1];
            }
            _size += n;
            while (n--)
            {
                _arr[pos + n] = val;
            }
        }

        template <class InputIterator>
        void    insert(iterator position, InputIterator first, InputIterator last,
                        typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
        {
            size_type count = 0;
            size_type pos = position - begin();
            while (first != last)
            {
                count++;
                first++;
            }
            if ((_size + count) > _capacity)
                this->reserve(_size + count);
            for (size_t i = _size; i > pos; i--)
            {
                _arr[i - 1 + count] = _arr[i - 1];
            }
            _size += count;
            while (count--)
            {
                _arr[pos + count] = *(last - 1);
                last--;
            }
            
        }
        iterator erase (iterator position)
        {
            for (iterator it = position; it != end(); ++it)
                *it = *(it + 1);
            pop_back();
            return position;
        }

        iterator	erase(iterator first, iterator last)
        {
            iterator tmp = first;

            while (tmp != last)
            {
                erase(first);
                tmp++;
            }
            return (first);
        }
        //NOTE - Not Fixed _capacity 
        void swap (vector& x)
        {
            vector<value_type> tmp;
            tmp = x;
            x.clear();
            for (iterator i = begin(); i != end(); i++)
                x.push_back(*i);
            clear();
            for (iterator i = tmp.begin(); i != tmp.end(); i++)
                this->push_back(*i);
        }
        void clear()
        {
            size_type tmp = _size;
            for (size_t i = 0; i < tmp; i++)
            {
                _alloc.destroy(_arr + i);
                _size--;
            }
        }
    
        //TODO - Allocator:
        allocator_type  get_allocator() const
        {
            return (_alloc);
        }
        
        ~vector()
        {
            delete [] _arr;
        }
    };
    //TODO - Lexicographical less-than comparison
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1)
        {
            if (first2==last2 || *first2<*first1) return false;
            else if (*first1<*first2) return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }

    //TODO - Non-member function overloads
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() == rhs.size())
        {
            for (size_t i = 0; i < lhs.size(); i++)
            {
                if (lhs.at(i) != rhs.at(i))
                    return false;
            }
            return true;
        }
        else
            return false;
    }
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }
    template <class T, class Alloc>
    bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(rhs < lhs);
    }
    template <class T, class Alloc>
    bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (rhs < lhs);
    }
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }

    //TODO - Exchange contents of vectors
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
}

#endif