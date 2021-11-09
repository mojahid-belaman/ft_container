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
    //  size_type       height

    //  size_type   max(size_type a, size_type b) {
    //     return (a > b) ? a : b;
    // }

    //  size_type   heightOf(AvlNode node) {
    //     return (node == NULL) ? 0 : node->height;
    // }

    //  int getBalanceFactor(AvlNode node) {
    //     return (node == NULL) ? 0 : heightOf(node->left) - heightOf(node->right);
    // }

    //  AvlNode rightRotate(AvlNode y) {
    //     AvlNode		x = y->left;

    //     if(x->right != NULL)
    //         x->right->parent = y;
	// 	x->parent = y->parent;
	// 	y->parent = x;
    //     y->left = x->right;
	// 	x->right = y;
    //     y->height = max(heightOf(y->left), heightOf(y->right)) + 1;
    //     x->height = max(heightOf(x->left), heightOf(x->right)) + 1;
    //     return x;
    // }

    //  AvlNode leftRotate(AvlNode x) {
    //     AvlNode     y = x->right;

    //     if(y->left != NULL)
    //         y->left->parent = x;
    //     y->parent = x->parent;
	// 	x->parent = y;
	// 	x->right = y->left;
	// 	y->left = x;
    //     x->height = max(heightOf(x->left), heightOf(x->right)) + 1;
    //     y->height = max(heightOf(y->left), heightOf(y->right)) + 1;
    //     return y;
    // }

    // node->height = max(heightOf(node->left), heightOf(node->right)) + 1;
    //     int balanceFactor = getBalanceFactor(node);
    //     if (balanceFactor > 1) {
    //         if (m_comp(data, node->left->data)) {
    //             return rightRotate(node);
    //         } else {
    //             node->left = leftRotate(node->left);
    //             return rightRotate(node);
    //         }
    //     } else if (balanceFactor < -1) {
    //         if (m_comp(node->right->data, data)) {
    //             return leftRotate(node);
    //         } else {
    //             node->right = rightRotate(node->right);
    //             return leftRotate(node);
    //         }
    //     }
    //     return node;

};

#endif