#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

namespace ft
{
    template <class T>
    struct node
    {
        T           _data;
        node        *left;
        node        *right;
    };

    //NOTE - Make Binary Search Tree (BST)
    template <class T, class Compare, class Alloc = std::allocator<node<T> > >
    class BST
    {
        public:
            typedef T           value_type;
            typedef node<T>     *ptr_node;
            typedef Alloc       allocator_type;
            typedef Compare     key_compare;
        
            BST(const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare()) : _root(nullptr), _alloc(alloc), _cmp(comp)
            {
            }

            void    insert_node(value_type data)
            {
                ptr_node new_node = _alloc.allocate(1);
                new_node->_data = data;
                new_node->left = nullptr;
                new_node->right = nullptr;

                if (_root == nullptr)
                {
                    _root = new_node;
                    return ;
                }
                ptr_node tmp = _root;
                ptr_node parent = nullptr;
                while (tmp != nullptr)
                {
                    parent = tmp;
                    if (_cmp(new_node->_data.first, tmp->_data.first))
                        tmp = tmp->left;
                    else if (new_node->_data.first == tmp->_data.first)
                    {
                        tmp->_data = new_node->_data;
                        _alloc.deallocate(new_node, 1);
                        return ;
                    }
                    else
                        tmp = tmp->right;
                }
                if (_cmp(new_node->_data.first, parent->_data.first))
                    parent->left = new_node;
                else
                    parent->right = new_node;
            }

            void    print_first()
            {
                std::cout << _root->_data.first << " , " << _root->_data.second << std::endl;
                std::cout << _root->right->_data.first << " , " << _root->right->_data.second << std::endl;
            }
        private:
            //NOTE - Start Tree
            ptr_node            _root;
            allocator_type      _alloc;
            key_compare         _cmp;

    }; 

    //NOTE - class template (Pair of values)
    template <class T1, class T2>
    struct pair
    {
        //NOTE - Member types
        typedef T1  first_type;
        typedef T2  second_type;

        //NOTE - Member variables
        first_type  first;
        second_type second;

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
        typedef BST<value_type, value_compare>                    tree;
    };
}

#endif