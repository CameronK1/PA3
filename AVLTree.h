//
// Created by Cameron on 10/9/2020.
//

#ifndef INC_223PA3_AVLTREE_H
#define INC_223PA3_AVLTREE_H

#include "AVLNode.h"
#include <iostream>
#include <string>

using namespace std;

template<class T>
class AVLTree
{
private:
    T item;

    AVLNode<T> *root;

public:
    // Constructor
    AVLTree();

    // Pointing to root node
    AVLTree(AVLNode<T> *root);

    // Destructor
    ~AVLTree();

    // Checking if empty
    bool isEmpty();

    // Returns height of node or -1 if nullptr
    int height(AVLNode<T> *root);

    // Inserting data into the tree
    void insert(int item);
    AVLTree<T> * insert(int item, AVLNode<T> *tree);

    // Removing an item from the tree
    void remove(int item);
    AVLTree<T> * remove(int item, AVLNode<T> *tree);

    // Removes all nodes
    void clear(AVLNode<T> *tree);

    // Finds smallest item in the tree
    AVLTree<T> * findMin(AVLNode<T> *tree);

    // Finds largest item in the tree
    AVLTree<T> * findMax(AVLNode<T> *tree);

    // Prints the data in increasing order
    void printOrder();
    void printInOrder(AVLNode<T> *tree);
};

template<class T>
AVLTree<T>::AVLTree()
{
    this->root = NULL;
}

template<class T>
AVLTree<T>::~AVLTree<T>()
{

}

template <class T>
bool AVLTree<T>::isEmpty()
{
    return root == nullptr;
}

template<class T>
int AVLTree<T>::height(AVLNode<T> *tree)
{
    return(tree == NULL ? - 1 : tree->height);
}

template <class T>
void insert(int item)
{
    AVLTree<T> root = insert(item, root);
}

template<class T>
AVLTree<T> * insert(int item, AVLNode<T> *tree)
{
    if (tree == NULL)
    {
        tree = new AVLNode<T>;
        tree->height = 0;
        tree->data = item;
        tree->left = tree->right = NULL;
    }

    else if (item < tree->data)
    {
        tree->left = insert(item, tree->left);

        if (height(tree->left)->data - height(tree->right) == 2)
        {
            if (item < tree->left->data)
            {
                tree = AVLNode<T>::rotateRight(tree);
            }
            else
            {
                tree = AVLNode<T>::rotateTwiceRight(tree);
            }
        }
    }
    else if (item < tree->data)
    {
        tree->left = insert(item, tree->left);

        if (height(tree->right) - height(tree->left) == 2)
        {
            tree = AVLNode<T>::rotateLeft(tree);
        }
        else
        {
            tree = AVLNode<T>::rotateTwiceLeft(tree);
        }
    }

    tree->height = max(height(tree->left), height(tree->right) + 1);

    return tree;
}

template<class T>
void remove(int item)
{
    AVLTree<T> root = remove(item, root);
}

template<class T>
AVLTree<T> * remove(int item, AVLNode<T> *tree)
{
    AVLTree<T> * temp;

    // What we were looking for is not found
    if (tree == NULL)
        return NULL;

    // Searching
    else if (item < tree->data)
        tree->left = remove(item, tree->left);
    else if (item > tree->data)
        tree->right = remove(item, tree->right);


    // If we found the item and have two children
    else if (tree->right && tree->left)
    {
        temp = findMin(tree->right);

        tree->data = temp->data;
        tree->right = remove(tree->data, tree->right);
    }

    // If we found the item and there is either 1 or 0 children
    else
    {
        temp = tree;

        if (tree->left == NULL)
            tree = tree->right;
        else if (tree->right == NULL)
            tree = tree->left;

        delete temp;
    }

    if (tree == NULL)
        return tree;

    tree->height = max(height(tree->left), heigh(tree->right)) + 1;

    if (height(tree->left) - height(tree->right) == 2)
    {
        if (height(tree->left->left) - height(tree->left->right) == 1)
            return AVLNode<T>::rotateLeft(tree);
        else
            return AVLNode<T>::rotateTwiceLeft(tree);
    }
    else if (height(tree->right) - height(tree->left) == 2)
    {
        if (height(tree->right->right) - height(tree->right->left) == 1)
            return AVLNode<T>::rotateRight(tree);
        else
            return AVLNode<T>::rotateTwiceRight(tree);
    }

    return tree;
}

template<class T>
void AVLTree<T>::clear(AVLNode<T> *tree)
{
    if (tree == NULL)
        return;

    clear(tree->left);
    clear(tree->right);

    delete tree;
}

template<class T>
AVLTree<T> * findMin(AVLNode<T> *tree)
{
    if (tree == NULL)
        return NULL;
    else if (tree->left == NULL)
        return tree;
    else
        return findMin(tree->left);
}

template<class T>
AVLTree<T> * findMax(AVLNode<T> *tree)
{
    if (tree == NULL)
        return NULL;
    else if (tree->right == NULL)
        return tree;
    else
        return findMax(tree->right);
}

template<class T>
void AVLTree<T>::printOrder()
{
    printInOrder(root);

    cout << endl;
}



template<class T>
void AVLTree<T>::printInOrder(AVLNode<T> *tree)
{
    if (tree == NULL)
        return;
    else
        return height(tree->left) - height(tree->right);
}


#endif //INC_223PA3_AVLTREE_H
