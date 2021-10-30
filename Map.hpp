#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

namespace ft
{
    template <class T>
    struct BST_node
    {
        T               _data;
        BST_node        *left;
        BST_node        *right;
        BST_node        *parent;
    };

    //NOTE - Make Binary Search Tree (BST)
    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<BST_Node<T> > >
    class BST
    {
        public:
            typedef T               value_type;
            typedef BST_node<T>     node_type;
            typedef node_type       *node_pointer;

    }; 

    //NOTE - class template (Pair of values)
    template <class T1, class T2>
    struct pair
    {
        //NOTE - Member types
        typedef T1  first_type;
        typedef T2  second_type;

        //NOTE - Member variables
        T1 first;
        T2 second;

        //NOTE - default constructor
        pair() : first(), second()
        {
        }
        //NOTE - copy constructor
        template<class U, class V>
        pair (const pair<U,V>& pr) : first(pr.first), second(pr.second)
        {
        }
        //NOTE - initialization constructor
        pair (const first_type& a, const second_type& b) : first(a), second(b)
        {
        }
        //NOTE - Assign contents
        pair& operator= (const pair& pr)
        {
            if (this != &pr)
            {
                first = pr.first;
                second = pr.second;
            }
            return (*this);
        }
        //NOTE - Relational operators for pair
        template <class t1, class t2>
        friend bool operator== (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs);
        template <class t1, class t2>
        friend bool operator!= (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs);
        template <class t1, class t2>
        friend bool operator< (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs);
        template <class t1, class t2>
        friend bool operator<= (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs);
        template <class t1, class t2>
        friend bool operator> (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs);
        template <class t1, class t2>
        friend bool operator>= (const pair<t1,t2>& lhs, const pair<t1,t2>& rhs);

    };

    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }
    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class T1, class T2>
    bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }
    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(rhs < lhs);
    }
    template <class T1, class T2>
    bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (rhs < lhs);
    }
    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(lhs < rhs);
    }
    //NOTE - function template (make_pair)
    template <class T1, class T2>
    pair<T1,T2> make_pair(T1 x, T2 y)
    {
        return pair<T1, T2>(x, y);
    }

    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
    class map
    {
        //NOTE - Member types
        typedef Key                                             key_type;
        typedef T                                               mapped_type;
        typedef pair<const key_type, mapped_type>               value_type;
        typedef Compare                                         key_compare;
        //NOTE - Nested function class to compare elements
        class value_compare : std::binary_function<value_type, value_type, bool>
        {
            friend class map;
            protected:
                Compare comp;
                value_compare(Compare c) : comp(c)
                {
                }
            public:
                bool operator()(const value_type& x, const value_type& y)
                {
                    return comp(x.first, y.first);
                }
        };
        typedef Alloc                                           allocator_type;
        typedef typename allocator_type::reference              reference;
        typedef typename allocator_type::const_reference        const_reference;
        typedef typename allocator_type::pointer                pointer;
        typedef typename allocator_type::const_pointer          const_pointer;        
    };
}

#endif