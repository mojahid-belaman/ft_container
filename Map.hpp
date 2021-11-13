#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "Utility_map.hpp"

namespace ft
{
    //NOTE - Make Binary Search Tree (BST)
    template <class T, class Compare, class Alloc = std::allocator<node<T> > >
    class BST
    {
        public:
            typedef T                           value_type;
            typedef node<T>*                    ptr_node;
            typedef Alloc                       allocator_type;
            typedef Compare                     key_compare;
        
            BST(const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare()) : _root(nullptr), _end(nullptr), _alloc(alloc), _cmp(comp)
            {
            }
            void    insert_node(value_type data)
            {
                ptr_node new_node = _alloc.allocate(1);
                _alloc.construct(new_node, data);
                // new_node->left = nullptr;
                // new_node->right = nullptr;
                // new_node->parent = nullptr;
                // new_node->bf = 0;

                if (_root == nullptr)
                {
                    _end = _alloc.allocate(1);
                    _root = new_node;
                    _root->parent = _end;
                    _end->left = _root;
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
                        tmp->_data.second = new_node->_data.second;
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
                new_node->parent = parent;
                
                //NOTE - Calcule bf every node
                update_balance_factor(new_node);                
            }
            ptr_node    get_max()
            {
                ptr_node tmp = _root;
                return get_max_helper(tmp);
            }

            ptr_node    get_min()
            {
                ptr_node tmp = _root;
                return get_min_helper(tmp);
            }

            ptr_node  search_node(value_type val)
            {
                ptr_node tmp = _root;
                while (tmp->_data.first != val.first)
                {
                    if (tmp != nullptr)
                    {
                        if (tmp->_data.first > val.first)
                            tmp = tmp->left;
                        else
                            tmp = tmp->right;
                    }
                    if (tmp == nullptr)
                        return nullptr;
                }
                return tmp;
                
            }

            void    delete_node(value_type val)
            {
                _root = delete_helper(_root, val);
            }
            void    print_bst()
            {
                print_bst_preorder(this->_root);
            }

        private:
            //NOTE - Start Tree
            ptr_node            _root;
            ptr_node            _end;
            allocator_type      _alloc;
            key_compare         _cmp;

            ptr_node get_max_helper(ptr_node tmp)
            {
                while (tmp->right != nullptr)
                    tmp = tmp->right;
                return _end;
            }

            ptr_node get_min_helper(ptr_node tmp)
            {
                while (tmp->left != nullptr)
                    tmp = tmp->left;
                return tmp;
            }

            ptr_node    delete_helper(ptr_node root, value_type val)
            {
                if (root == nullptr)
                    return root;
                else if (val.first < root->_data.first)
                    root->left = delete_helper(root->left, val);
                else if (val.first > root->_data.first)
                    root->right = delete_helper(root->right, val);
                else
                {
                    if (root->left == nullptr)
                    {
                        ptr_node tmp = root->right;
                        if (tmp != nullptr)
                            tmp->parent = root->parent;
                        _alloc.deallocate(root, 1);
                        return tmp;
                    }
                    else if (root->right == nullptr)
                    {
                        ptr_node tmp = root->left;
                        if (tmp != nullptr)
                            tmp->parent = root->parent;
                        _alloc.deallocate(root, 1);
                        return tmp;
                    }
                    else
                    {
                        ptr_node max_val = this->get_max_helper(root->left);
                        _alloc.construct(root, max_val->_data);
                        root->left = delete_helper(root->left, max_val->_data);
                    }
                }
                return root;
            }

            void    print_bst_preorder(ptr_node root)
            {
                if (root != nullptr)
                {
                    std::cout << root->_data.first << "\t";
                    print_bst_preorder(root->left);
                    print_bst_preorder(root->right);
                }
            }
            int     max(int a, int b)
            {
                return (a > b ? a : b);
            }
            int     min(int a, int b)
            {
                return (a < b ? a : b);
            }
            void    right_rotation(ptr_node node)
            {
                ptr_node tmp = node->left;
                node->left = tmp->right;
                if (tmp->right != nullptr)
                    tmp->right->parent = node;
                tmp->parent = node->parent;
                if (node->parent == _end)
                {
                    this->_root = tmp;
                    tmp->parent = _end;
                }
                else if (node == node->parent->right)
                    node->parent->right = tmp;
                else
                    node->parent->left = tmp;
                
                tmp->right = node;
                node->parent = tmp;
                node->bf = node->bf + 1 - min(0, tmp->bf);
                tmp->bf = tmp->bf + 1 + max(0, node->bf);
            }
            void    left_rotation(ptr_node node)
            {
                ptr_node    tmp = node->right;
                node->right = tmp->left;
                if (tmp->left != nullptr)
                    tmp->left->parent = node;
                tmp->parent = node->parent;
                if (node->parent == _end)
                {
                    this->_root = tmp;
                    tmp->parent = _end;
                }
                else if (node == node->parent->left)
                    node->parent->left = tmp;
                else
                    node->parent->right = tmp;
                
                tmp->left = node;
                node->parent = tmp;
                node->bf = node->bf + 1 - min(0, tmp->bf);
                tmp->bf = tmp->bf + 1 + max(0, node->bf);

            }
            void    rebalance(ptr_node node)
            {
                if (node->bf < 0)
                {
                    if (node->right->bf > 0)
                    {
                        right_rotation(node->right);
                        left_rotation(node);
                    }
                    else
                        left_rotation(node);
                }
                else if (node->bf > 0)
                {
                    if (node->left->bf < 0)
                    {
                        left_rotation(node->left);
                        right_rotation(node);
                    }
                    else
                        right_rotation(node);

                }
            }
            void    update_balance_factor(ptr_node node)
            {
                if (node->bf < -1 || node->bf > 1)
                {
                    rebalance(node);
                    return ;
                }
                if (node->parent != nullptr)
                {
                    if (node == node->parent->left)
                        node->parent->bf += 1;
                    if (node == node->parent->right)
                        node->parent->bf -= 1;
                    if (node->parent->bf != 0)
                        update_balance_factor(node->parent);
                }
            }

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
        public:
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
            typedef BST<value_type, key_compare>                    tree;
            typedef typename tree::ptr_node                         ptr_node;
            typedef tree_iterator<value_type, ptr_node>             iterator;
            typedef const_tree_iterator<value_type, ptr_node>       const_iterator;
            typedef tree_reverse_iterator<iterator>                 reverse_iterator;
            typedef tree_reverse_iterator<const_iterator>           const_reverse_iterator;
            typedef ptrdiff_t                                       difference_type;
            typedef size_t                                          size_type;

            //NOTE - Default Constructor
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : 
                            _tree(), _cmp(comp), _alloc(alloc)
            {
            }
            //NOTE - Range Constructor
            // template <class InputIterator>
            // map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
            //     _tree(), _cmp(comp), _alloc(alloc)
            // {
            // }

            //NOTE - Return iterator to beginning
            iterator begin()
            {
                return iterator(_tree.get_min());
            }
            const_iterator begin() const
            {
                iterator(_tree.get_min());
            }
            //NOTE - Return iterator to end
            iterator end()
            {
                return iterator(_tree.get_max());
            }
            // const_iterator end() const
            // {
            //     return iterator(_tree.get_max());
            // }
            //NOTE - Return reverse iterator to reverse beginning
            reverse_iterator rbegin()
            {
                return reverse_iterator(this->end());
            }
            // const_reverse_iterator rbegin() const
            // {
            //     return reverse_iterator(this->end());
            // }
            //NOTE - Return reverse iterator to reverse end
            reverse_iterator rend()
            {
                return reverse_iterator(this->begin());
            }
            // const_reverse_iterator rend() const
            // {
            //     return reverse_iterator(this->begin());
            // }
        private:
            tree    _tree;
            key_compare _cmp;
            allocator_type _alloc;
    };
}

#endif