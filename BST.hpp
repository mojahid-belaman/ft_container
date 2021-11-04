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
    //     node_pointer next()
        //     {
        //         TreeNode<T> *curr;
        //         TreeNode<T> *last;

        //         curr = _ptr;
        //         if (curr->right)
        //         {
        //             curr = curr->right;
        //             while (curr->left)
        //                 curr = curr->left;
        //             return curr;
        //         }
        //         else
        //         {
        //             while (curr->parent)
        //             {
        //                 last = curr;
        //                 curr = curr->parent;
        //                 if (curr->right != last)
        //                     return curr;
        //             }
        //         }
        //         return nullptr;
        //     }

		// node_pointer previous()
		// {
		// 	TreeNode<T> *curr;
		// 	TreeNode<T> *last;

		// 	curr = _ptr;
		// 	if (curr->left)
		// 	{
		// 		curr = curr->left;
		// 		while (curr->right)
		// 			curr = curr->right;
		// 		return curr;
		// 	}
		// 	else
		// 	{
		// 		while (curr->parent)
		// 		{
		// 			last = curr;
		// 			curr = curr->parent;
		// 			if (curr->right == last)
		// 				return curr;
		// 		}
		// 	}
		// 	return nullptr;
		// }
};

#endif