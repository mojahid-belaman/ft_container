#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "Iterator_traits.hpp"

//TODO - Reverse iterator
template <class Iterator>
class myiterator_reverse : public iterator<std::random_access_iterator_tag, typename iterator_traits<Iterator>::value_type>
{
    public:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename iterator_traits<Iterator>::pointer             pointer;
        typedef typename iterator_traits<Iterator>::reference           reference;
        //TODO - Constructor Default
        myiterator_reverse() : _ptr(nullptr) {}
        //TODO - initialization
        explicit myiterator_reverse (iterator_type it) : _ptr(it) {}
        //TODO - copy
        template <class Iter>
        myiterator_reverse (const myiterator_reverse<Iter>& rev_it) : _ptr(rev_it._ptr) {}
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
        myiterator_reverse operator+ (difference_type n) const
        {
            return myiterator_reverse(_ptr - n);
        }
        //TODO - Increment iterator position
        myiterator_reverse& operator++()
        {
            --_ptr;
            return (*this);
        }
        myiterator_reverse  operator++(int)
        {
            myiterator_reverse tmp = *this;
            ++(*this);
            return tmp;
        }
        myiterator_reverse& operator+= (difference_type n)
        {
            this->_ptr -= n;
            return (*this);
        }
        myiterator_reverse operator- (difference_type n) const
        {
            return myiterator_reverse(this->_ptr + n);
        }
        myiterator_reverse& operator--()
        {
            return (++(this->base()));
        }
        myiterator_reverse  operator--(int)
        {
            myiterator_reverse tmp = *this;
            --(*this);
            return (tmp);
        }
        myiterator_reverse& operator-= (difference_type n)
        {
            _ptr += n;
            return (*this);
        }
        pointer operator->() const
        {
            return &(operator*());
        }
        reference operator[] (difference_type n) const
        {
            return (*(_ptr - n));
        }
    private:
        iterator_type _ptr;
};
template <class Iterator>
bool operator== (const myiterator_reverse<Iterator>& lhs, const myiterator_reverse<Iterator>& rhs)
{
    return (rhs.base() == lhs.base());
}
template <class Iterator>
bool operator!= (const myiterator_reverse<Iterator>& lhs, const myiterator_reverse<Iterator>& rhs)
{
    return (rhs.base() != lhs.base());
}
template <class Iterator>
bool operator< (const myiterator_reverse<Iterator>& lhs, const myiterator_reverse<Iterator>& rhs)
{
    return (rhs.base() < lhs.base());
}
template <class Iterator>
bool operator<= (const myiterator_reverse<Iterator>& lhs, const myiterator_reverse<Iterator>& rhs)
{
    return (rhs.base() <= lhs.base());
}
template <class Iterator>
bool operator> (const myiterator_reverse<Iterator>& lhs, const myiterator_reverse<Iterator>& rhs)
{
    return (rhs.base() > lhs.base());
}
template <class Iterator>
bool operator>= (const myiterator_reverse<Iterator>& lhs, const myiterator_reverse<Iterator>& rhs)
{
    return (rhs.base() >= lhs.base());
}
template <class Iterator>
myiterator_reverse<Iterator> operator+ (typename myiterator_reverse<Iterator>::difference_type n, const myiterator_reverse<Iterator>& rev_it)
{
    return (*(rev_it.base() - n));
}
template <class Iterator>
typename myiterator_reverse<Iterator>::difference_type operator- (const myiterator_reverse<Iterator>& lhs, const myiterator_reverse<Iterator>& rhs)
{
    return (lhs.base() - rhs.base());
}

#endif