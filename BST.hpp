#ifndef BST_HPP
#define BST_HPP

#include <iostream>

class BST
{
private:
    struct node
    {
        int _data;
        node* left;
        node* right;
    };
    node* root;
public:
    BST()
    {
        root = nullptr;
    }
    node *create_leaf(int data)
    {
        node* new_node = new node;
        new_node->_data = data;
        new_node->left = nullptr;
        new_node->right = nullptr;
        return new_node;
    }
    void    add_leaf(int data, node* ptr)
    {
        if (root == NULL)
            root = create_leaf(data);
        else if (data < ptr->_data)
        {
            if (ptr->left != nullptr)
                add_leaf(data, ptr->left);
            else
                 ptr->left = create_leaf(data);
        }
    }
};

#endif