#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "Iterator_traits.hpp"
#include "Reverse_iterator.hpp"
#include "Enable_if.hpp"
#include "Is_integral.hpp"

namespace ft
{
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
            vector_iterator (const vector_iterator<Iter>& it) : _ptr(it.base()) {}

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
        typedef myiterator_reverse<iterator>                reverse_iterator;
        typedef myiterator_reverse<const_iterator>          const_reverse_iterator;
        typedef ptrdiff_t                                   difference_type;
        typedef size_t                                      size_type;
        // TODO - Implement Constructor Default (empty)
        explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _arr(nullptr), _alloc(alloc)
        {
        }
        // TODO - Implement Constructor Fill (Parametrize)
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
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
        vector (const vector& x): _capacity(0)
        {
            *this = x;
        }
        // TODO - Implement Assignment Operator (operator=)
        vector& operator= (const vector& x)
        {
            if (this != &x)
            {
                if (_capacity != 0)
                    _alloc.deallocate(_arr, _capacity);
                _size = x._size;
                _capacity = x._capacity;
                _alloc = x._alloc;
                if (_capacity != 0)
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
            return (_alloc.max_size());
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
        reference at(size_type n)
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
                    typename  enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
        {
            difference_type dt = last - first;
            _size = dt;
            _capacity = dt;
            _alloc.deallocate(_arr, _capacity);
            _arr = _alloc.allocate(_capacity);
            for (size_type i = 0; i < _size; i++)
            {
                _arr[i] = *(first + i);
            }
        }
        void assign(size_type n, const value_type& val)
        {
            this->clear();
            for (size_type i = 0; i < n; i++)
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
                for (size_type i = 0; i < _size; i++)
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
                for (size_type i = 0; i < _size; i++)
                {
                    new_ptr[i] = _arr[i];
                }
                _alloc.deallocate(_arr, _capacity);
                _arr = new_ptr;
                _capacity *= 2;

            }
            _arr[_size] = val;
            _size++;
            for (size_type i = _size - 1; i > pos; i--)
            {
                _arr[i] = _arr[i - 1];
            }
            _arr[pos] = val;
            return iterator(_arr + pos);
        }
        void    insert (iterator position, size_type n, const value_type& val)
        {
            size_type pos = position - begin();
            if ((_size + n) > _capacity)
                this->reserve(_size + n);
            for (size_type i = _size; i > pos; i--)
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
        void swap (vector& x)
        {
            vector<value_type> tmp;
            tmp = x;
            x = *this;
            *this = tmp;
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
            if (_capacity != 0)
                _alloc.deallocate(_arr, _capacity);
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
    //TODO - Test whether the elements in two ranges are equal (equal)
    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while (first1!=last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1; ++first2;
        }
        return true;
    }
    //TODO - Non-member function overloads
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin()));
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