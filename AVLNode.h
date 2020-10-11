//
// Created by Cameron on 10/9/2020.
//

#ifndef INC_223PA3_AVLNODE_H
#define INC_223PA3_AVLNODE_H

#include <iostream>
#include <string>


template<class T>
class AVLNode
{
private:
    int height;

    T data;
    T item;

    AVLNode<T> *left = nullptr;
    AVLNode<T> *right = nullptr;
    AVLNode<T> *next = nullptr;

public:
    // Getting the next node
    AVLNode<T> *getNext();

    // Getting the data
    T getData();

    // Setting the next node
    void setNext(AVLNode<T> *next);

    // Setting data
    void setData(T update);

    // Rotate subtree left
    AVLNode<T> *rotateLeft(AVLNode<T> * x);

    // Rotate subtree right
    AVLNode<T> *rotateRight(AVLNode<T> * y);

    // Checking if it's balanced
    int balanced(AVLNode<T> *root);

    // Printing preorder of the tree
    void preOrder(AVLNode<T> *root);

    // Creating a newNode we can use for insert()
    AVLNode<T> *newNode(int item);

    AVLNode<T> *rotateTwiceRight(AVLNode<T> * &tree);
    AVLNode<T> *rotateTwiceLeft(AVLNode<T> * &tree);
};

template<class T>
AVLNode<T> * AVLNode<T>::getNext()
{
    return next;
}

template<class T>
void AVLNode<T>::setNext(AVLNode<T> *next)
{
    this->next = next;
}

template<class T>
T AVLNode<T>::getData()
{
    return data;
}

template<class T>
void AVLNode<T>::setData(T update)
{
    data = update;
}

template<class T>
AVLNode<T> * AVLNode<T>::rotateRight(AVLNode<T> *y)
{
    // Initializing the rotations
    AVLNode<T> *x = y->left;
    AVLNode<T> *x2 = x->right;

    // Rotating here
    x->right = y;
    y->left = x2;

    // Making sure the heights are updated
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Returning the new root
    return x;
}

template<class T>
AVLNode<T> * AVLNode<T>::rotateLeft(AVLNode<T> *x)
{
    // Initializing the rotations
    AVLNode<T> *y = x->left;
    AVLNode<T> *y2 = x->right;

    // Rotating here
    y->right = x;
    x->left = y2;

    // Making sure the heights are updated
    y->height = max(height(x->left), height(x->right)) + 1;
    x->height = max(height(y->left), height(y->right)) + 1;

    // Returning the new root
    return y;
}

template<class T>
int AVLNode<T>::balanced(AVLNode<T> *root)
{
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

template<class T>
AVLNode<T> *newNode(int item)
{
    AVLNode<T> *node = new AVLNode<T>();

    node->item = item;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

template<class T>
AVLNode<T> * rotateTwiceLeft(AVLNode<T> *&tree)
{
    tree->right = AVLNode<T>::rotateRight(tree->right);

    return rotateLeft(tree);
}

template<class T>
AVLNode<T> * rotateTwiceRight(AVLNode<T> *&tree)
{
    tree->left = AVLNode<T>::rotateLeft(tree->left);

    return AVLNode<T>::rotateRight(tree);
}

#endif //INC_223PA3_AVLNODE_H
