#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "Utility_map.hpp"
#include "Pair.hpp"
#include "Make_pair.hpp"

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
            typedef size_t                      size_type;
        
            BST(const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare()) : _root(nullptr), _end(nullptr), _alloc(alloc), _cmp(comp), _size(0)
            {
            }
            size_type size() const
            {
                return _size;
            }
            size_type max_size() const
            {
                return (_alloc.max_size());
            }
            void swap (BST& x)
            {
                size_type       s_size = x._size;
                allocator_type  s_alloc = x._alloc;
                ptr_node        s_end = x._end;
                ptr_node        s_root = x._root;
                x._size = _size;
                _size = s_size;
                x._alloc = _alloc;
                _alloc = s_alloc;
                x._end = _end;
                _end = s_end;
                x._root = _root;
                _root = s_root;

            }
            ptr_node    all_clean_tree(ptr_node node)
            {
                if (node != nullptr)
                {
                    all_clean_tree(node->left);
                    all_clean_tree(node->right);
                    _alloc.deallocate(node, 1);
                }
                return nullptr;
            }
            void clear()
            {
                _root = all_clean_tree(_root);
                _size = 0;
            }
            void    insert_node(value_type data)
            {
                ptr_node new_node = _alloc.allocate(1);
                _alloc.construct(new_node, data);
                new_node->left = nullptr;
                new_node->right = nullptr;
                new_node->parent = nullptr;
                new_node->bf = 0;

                if (_root == nullptr)
                {
                    _end = _alloc.allocate(1);
                    _root = new_node;
                    _root->parent = _end;
                    _end->left = _root;
                    _size++;
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
                {
                    parent->left = new_node;
                    _size++;
                }
                else
                {
                    parent->right = new_node;
                    _size++;
                }
                new_node->parent = parent;
                
                //NOTE - Calcule bf every node
                insert_balance_factor(new_node);     
            }
            ptr_node    get_max() const
            {
                ptr_node tmp = _root;
                if (tmp == nullptr)
                    return nullptr;
                return get_max_helper(tmp);
            }

            ptr_node    get_min() const
            {
                ptr_node tmp = _root;
                if (tmp == nullptr)
                    return nullptr;
                return get_min_helper(tmp);
            }

            ptr_node  search_node(value_type val)
            {
                ptr_node tmp = _root;
                
                if (tmp == nullptr)
                    return (nullptr);
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
                bool isonechild = false;
                ptr_node node = this->search_node(val);
                ptr_node node_p= this->search_node(val)->parent;
                if (node->left == nullptr || node->right == nullptr)
                    isonechild = true;
                _root = delete_helper(_root, val);
                if (_root == nullptr)
                {
                    _alloc.deallocate(_end, 1);
                    _end = nullptr;
                }
                if (isonechild == true)
                    delete_balance_factor(node_p, val);
            }
            void    print_bst()
            {
                print_bst_preorder(this->_root);
            }

            ptr_node get_end() const {return _end;}

            ~BST()
            {
                _root = all_clean_tree(_root);
                _alloc.deallocate(_end, 1);
            }

        private:
            //NOTE - Start Tree
            ptr_node            _root;
            ptr_node            _end;
            allocator_type      _alloc;
            key_compare         _cmp;
            size_type           _size;
            

            ptr_node get_max_helper(ptr_node tmp)
            {
                while (tmp->right != nullptr)
                    tmp = tmp->right;
                return tmp;
            }

            ptr_node get_min_helper(ptr_node tmp) const
            {
                while (tmp->left != nullptr)
                    tmp = tmp->left;
                return tmp;
            }
            ptr_node    delete_helper(ptr_node root, value_type val)
            {
                ptr_node tmp;
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
                        _size--;
                        return tmp;
                    }
                    else if (root->right == nullptr)
                    {
                        ptr_node tmp = root->left;
                        if (tmp != nullptr)
                            tmp->parent = root->parent;
                        _alloc.deallocate(root, 1);
                        _size--;
                        return tmp;
                    }
                    else
                    {
                        ptr_node max_val = this->get_max_helper(root->left);
                        value_type vt = max_val->_data;
                        ptr_node node = max_val->parent;
                        root->left = delete_helper(root->left, max_val->_data);
                        tmp = delete_balance_factor(node, vt);
                        _alloc.construct(root, max_val->_data);
                        if (tmp != nullptr)
                            root = tmp;
                    }
                }
                return root;
            }

            void    print_bst_preorder(ptr_node root)
            {
                if (root != nullptr)
                {
                    std::cout <<root->_data.first << "\t"<< root->bf << std::endl;
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
            ptr_node    right_rotation(ptr_node node)
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
                node->bf = node->bf - 1 - max(0, tmp->bf);
                tmp->bf = tmp->bf - 1 - min(0, node->bf);
                return tmp;
            }
            ptr_node    left_rotation(ptr_node node)
            {
                ptr_node    tmp = node->right;
                node->right = tmp->left;
                if (tmp->left != nullptr)
                    tmp->left->parent = node;
                tmp->parent = node->parent;
                if (node->parent == _end)
                {
                    this->_root = tmp;
                    this->_root->parent = _end;
                    _end->left = this->_root;
                }
                else if (node == node->parent->left)
                    node->parent->left = tmp;
                else
                    node->parent->right = tmp;
                
                tmp->left = node;
                node->parent = tmp;
                node->bf = node->bf + 1 - min(0, tmp->bf);
                tmp->bf = tmp->bf + 1 + max(0, node->bf);
                return tmp;
            }
            ptr_node    rebalance(ptr_node node)
            {
                ptr_node tmp = nullptr;

                if (node->bf < 0)
                {
                    if (node->right->bf > 0)
                    {
                        right_rotation(node->right);
                        tmp = left_rotation(node);
                    }
                    else
                        tmp = left_rotation(node);
                }
                else if (node->bf > 0)
                {
                    if (node->left->bf < 0)
                    {
                        left_rotation(node->left);
                        tmp = right_rotation(node);
                    }
                    else
                        tmp = right_rotation(node);

                }
                return tmp;
            }
            void    insert_balance_factor(ptr_node node)
            {
                if (node->bf < -1 || node->bf > 1)
                {
                    rebalance(node);
                    return ;
                }
                if (node->parent != _end)
                {
                    if (node == node->parent->left)
                        node->parent->bf += 1;
                    if (node == node->parent->right)
                        node->parent->bf -= 1;
                    if (node->parent->bf != 0)
                        insert_balance_factor(node->parent);
                }
            }
            ptr_node    delete_balance_factor(ptr_node node, value_type val)
            {
                if (node != _end)
                {
                    if (node->_data.first > val.first)
                        node->bf -= 1;
                    else if (node->_data.first < val.first)
                        node->bf += 1;
                    if (node->bf < -1 || node->bf > 1)
                    {
                        return rebalance(node);
                    }
                    if (node->bf == 0)
                        delete_balance_factor(node->parent, val);
                }
                return nullptr;
            }

    };

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
            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
                _tree(), _cmp(comp), _alloc(alloc)
            {
                while (first != last)
                {
                    _tree.insert_node(*first);
                    first++;
                }
                
            }
            //NOTE - copy constructor
            map (const map& x) : _cmp(x._cmp), _alloc(x._alloc)
            {
                insert(x.begin(), x.end());
            }
            //NOTE - Copy container content
            map& operator= (const map& x)
            {
                if (x.size() == 0)
                {
                    this->clear();
                    return *this;
                }
                if (this != &x)
                {
                    this->clear();
                    insert(x.begin(), x.end());
                }
                return *this;
            }
            //NOTE - Map destructor
            ~map()
            {
            }
            //NOTE - Access element
            mapped_type& operator[] (const key_type& k)
            {
                ptr_node node = _tree.search_node(ft::make_pair(k, mapped_type()));
                if (node == nullptr)
                    _tree.insert_node(ft::make_pair(k, mapped_type()));
                node = _tree.search_node(ft::make_pair(k, mapped_type()));
                return (node->_data.second);
            }
            //NOTE - size_type size() const
            size_type size() const
            {
                return _tree.size();
            }
            //NOTE - Test whether container is empty
            bool empty() const
            {
                return(_tree.size() == 0);
            }
            //NOTE - Return maximum size
            size_type max_size() const
            {
                return (_tree.max_size());
            }
            //NOTE - Insert elements
            pair<iterator,bool> insert(const value_type& val)
            {
                ptr_node node = _tree.search_node(val);
                if (node != nullptr)
                    return ft::pair<iterator, bool>(iterator(node), false);
                _tree.insert_node(val);
                node = _tree.search_node(val);
                return (ft::pair<iterator, bool>(iterator(node), true));
            }
            iterator    insert(iterator position, const value_type& val)
            {
                static_cast<void>(position);
                ptr_node node = _tree.search_node(val);
                if (node != nullptr)
                    return iterator(node);
                _tree.insert_node(val);
                node = _tree.search_node(val);
                return (iterator(node));
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    _tree.insert_node(*first);
                    first++;
                }
            }
            //NOTE - Erase elements
            void    erase(iterator position)
            {
                if (position != iterator(nullptr))
                    _tree.delete_node(ft::make_pair(position->first, position->second));
            }
            size_type   erase(const key_type& k)
            {
                ptr_node node = _tree.search_node(ft::make_pair(k, mapped_type()));
                if (node != nullptr)
                {
                    _tree.delete_node(ft::make_pair(k, mapped_type()));
                    return 1;
                }
                else
                    return 0;
            }
            void    erase(iterator first, iterator last)
            {
                while (first != last)
                {
                    this->erase(first);
                    first++;
                }
            }
            //NOTE - Swap content
            void swap (map& x)
            {
                _tree.swap(x._tree);
            }
            //NOTE - Clear content
            void clear()
            {
                _tree.clear();
            }
            //NOTE - Return key comparison object
            key_compare key_comp() const
            {
                return key_compare();
            }
            //NOTE - Return iterator to beginning
            iterator begin()
            {
                return iterator(_tree.get_min());
            }
            const_iterator begin() const
            {
                return const_iterator(_tree.get_min());
            }
            //NOTE - Return iterator to end
            iterator end()
            {
                return iterator(_tree.get_end());
            }
            const_iterator end() const
            {
                return const_iterator(_tree.get_end());
            }
            //NOTE - Return reverse iterator to reverse beginning
            reverse_iterator rbegin()
            {
                return reverse_iterator(this->end());
            }
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(this->end());
            }
            //NOTE - Return reverse iterator to reverse end
            reverse_iterator rend()
            {
                return reverse_iterator(this->begin());
            }
            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(this->begin());
            }
        private:
            tree    _tree;
            key_compare _cmp;
            allocator_type _alloc;
    };
}

#endif