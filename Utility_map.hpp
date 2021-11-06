#ifndef UTILITY_MAP_HPP
#define UTILITY_MAP_HPP

#include <iostream>
#include "Utility.hpp"
namespace ft
{
    template <class T>
    struct node
    {
        T           _data;
        node        *left;
        node        *right;
        node        *parent;

        node(const T& src) : _data(src)
        {
        }
    };

    //NOTE - define Iterator Tree
    template <class T, class ptr_node>
    class tree_iterator
    {
        public:
            typedef T                   value_type;

            tree_iterator() : curr_node(nullptr)
            {
            }
            tree_iterator(ptr_node ptr) : curr_node(ptr)
            {
            }
            value_type   &operator*() const
            {
                return (curr_node->_data);
            }
            value_type *operator->() const
            {
                return (&(curr_node->_data));
            }
            tree_iterator&  operator++()
            {
               curr_node = successor();
               return *this;
            }
            tree_iterator   operator++(int)
            {
                tree_iterator itr(*this);
                ++(*this);
                return itr;
            }
            tree_iterator& operator--()
            {
                curr_node = predecessor();
                return *this;
            }
            tree_iterator   operator--(int)
            {
                tree_iterator itr(*this);
                --(*this);
                return (itr);
            }
            friend  bool  operator==(const tree_iterator& x, const tree_iterator& y)
            {
                return (x.curr_node == y.curr_node);
            }
            friend  bool  operator!=(const tree_iterator& x, const tree_iterator& y)
            {
                return (x.curr_node != y.curr_node);
            }
            ~tree_iterator() {}
        private:
            ptr_node    curr_node;
            ptr_node    successor()
            {
                ptr_node curr;

                curr = curr_node;
                if (curr->right != nullptr)
                {
                    curr = curr->right;
                    while (curr->left != nullptr)
                        curr = curr->left;
                    return curr;
                }
                else
                {
                    ptr_node ptr_parent = curr->parent;
                    while (ptr_parent != nullptr && curr == ptr_parent->right)
                    {
                        curr = ptr_parent;
                        ptr_parent = ptr_parent->parent;
                    }
                    return ptr_parent;
                }
            }
            ptr_node    predecessor()
            {
                ptr_node curr;
                curr = curr_node;
                if (curr->left != nullptr)
                {
                    curr = curr->left;
                    while (curr->right != nullptr)
                        curr = curr->right;
                    return curr;
                }
                else
                {
                    ptr_node ptr_parent = curr->parent;
                    while (ptr_parent != nullptr && curr == ptr_parent->left)
                    {
                        curr = ptr_parent;
                        ptr_parent = ptr_parent->parent;
                    }
                    return ptr_parent;

                }
            }
    };

    //NOTE - define Reverse Iterator Tree
    template <class iter>
    class tree_reverse_iterator : public iterator<std::bidirectional_iterator_tag, typename iterator_traits<iter>::value_type>
    {
        private:
            iter _it;
        public:
            typedef    iter                                             iterator_type;
            typedef typename    iterator_traits<iter>::difference_type  difference_type;
            typedef typename    iterator_traits<iter>::reference        reference;
            typedef typename    iterator_traits<iter>::pointer          pointer;

            iterator_type base() const
            {
                return (_it);
            }
            tree_reverse_iterator() : _it()
            {
            }
            explicit tree_reverse_iterator (iterator_type it) : _it(it)
            {
            }
            template <class Iter>
            tree_reverse_iterator (const tree_reverse_iterator<Iter>& rev_it) : _it(rev_it.base())
            {
            }
            reference operator*() const
            {
                iter tmp = _it;
                return *--tmp;
            }
            tree_reverse_iterator operator+ (difference_type n) const
            {
                return tree_reverse_iterator(_it - n);
            }
            tree_reverse_iterator& operator++()
            {
                --_it;
                return *this;
            }
            tree_reverse_iterator  operator++(int)
            {
                tree_reverse_iterator tmp(*this);
                --_it;
                return (tmp);
            }
            tree_reverse_iterator& operator+= (difference_type n)
            {
                _it -= n;
                return (*this);
            }
            tree_reverse_iterator operator- (difference_type n) const
            {
                return (tree_reverse_iterator(_it + n));
            }
            tree_reverse_iterator& operator--()
            {
                ++_it;
                return (*this);
            }
            tree_reverse_iterator  operator--(int)
            {
                tree_reverse_iterator tmp(*this);
                ++_it;
                return (tmp);
            }
            tree_reverse_iterator& operator-= (difference_type n)
            {
                _it += n;
                return (*this);
            }
            pointer operator->() const
            {
                return (this->_it);
            }
            reference operator[] (difference_type n) const
            {
                return(*(_it - n));
            }

            

    };
}
#endif