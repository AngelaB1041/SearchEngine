/*  Chelby Rhoades, Angela Barsallo
 *  Owner: Angela Barsallo
 *  Created: 07 November 2018 Chelby Rhoades
 *  Modified: 09 November 2018 Chelby Rhoades
 *  ThanosTree is our AVLtree, but renamed because of the nature of the AVLtree. Everything is perfectly balanced, as it should be.
 */

/* Edit History
 * Modified: 13 November 2018
 * Added templating to the existing code
 *
 * Modified: 15 November 2018
 * Finished adding all of the functions Weiss implemented on the tree
 *
 * Modified: 16 November 2018
 *
*/
#ifndef THANOSTREE_H
#define THANOSTREE_H
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <utility>
#include "thanosnode.h"
#include "word.h"
using namespace std;

template <class T>
class thanosTree{

private:

            thanosNode<T>* root;
            int numNodes;

            int height(thanosNode<T> *t) const;
            int max(int lhs, int rhs) const;
            void insert(const T& x, thanosNode<T>* & t);
            void rotateWithLeftChild(thanosNode<T>* & k2);
            void rotateWithRightChild(thanosNode<T>* & k2);
            void doubleWithLeftChild(thanosNode<T>* & k3);
            void doubleWithRightChild(thanosNode<T>* & k1);
            thanosNode<T>* findMin(thanosNode<T> *t) const;
            thanosNode<T>* findMax(thanosNode<T> *t) const;
            bool contains(const T& x, thanosNode<T>* t) const;
            void makeEmpty(thanosNode<T>* &t);
            void printTree(thanosNode<T>* t) const;
            thanosNode<T>* clone(thanosNode<T>* t) const;
            void copy(thanosNode<T>* t);
            void clear(thanosNode<T>*& t);

public:
            thanosTree() : root(nullptr), numNodes(0){}
            thanosTree(const thanosTree<T> &rhs);
            ~thanosTree();
            T& findMin();
            T& findMax();
            bool contains(const T& x);
            bool isEmpty() const;
            void makeEmpty();
            void insert(const T &x);
            const thanosTree& operator=(const thanosTree& rhs);
            T &find(const T& x, thanosNode<T>* rhs);
            int getNumNodes();
            void printTree() const;


};
//Copy function that can be called in the copy constructor
template<class T>
void thanosTree<T>::copy(thanosNode<T> *t){
    if(t!=nullptr){
        copy(t->right);
        copy(t->left);
        insert(t,t->key);
    }
}

//copy constructor
template<class T>
thanosTree<T>::thanosTree(const thanosTree<T> &rhs) : root(nullptr){
    *this = rhs;
}

template<class T>
thanosNode<T>* thanosTree<T>::clone(thanosNode<T> *t) const{
    if(t==nullptr){
        return nullptr;
    }else{
        return new thanosNode<T>(t->element, clone(t->left),clone(t->right),t->height);
    }
}

//Overloaded assignment operator
template<class T>
const thanosTree<T>& thanosTree<T>::operator =(const thanosTree& rhs){
    if(this != &rhs){
        makeEmpty();
        root = clone(rhs.root);
        numNodes = rhs.numNodes;
    }
    return *this;
}

/***
 * Return the height of the node t or -1 if NULL
 **/
template<class T>
int thanosTree<T>::height(thanosNode<T> *t) const{
    return t == nullptr ? -1 : t->height;
}

template<class T>
int thanosTree<T>::max(int lhs, int rhs) const{
    return lhs > rhs ? lhs : rhs;
}

/***
 * Internal method to insert into a subtree.
 * x is the item to insert
 * t is the node that roots the subtree.
 * Set the new root of the subtree
 **/
template<class T>
void thanosTree<T>::insert(const T& x, thanosNode<T>*& t){
       if (t==nullptr){
           t = new thanosNode<T>(x, nullptr, nullptr);
           //numNodes++;
       }else if(x < t->element){
           insert(x, t->left);
           if(height(t->left) - height(t->right)==2)
               if(x < t->left->element)
                   rotateWithLeftChild(t);
                else
                   doubleWithLeftChild(t);
           //numNodes++;
       }
       else if(t->element < x){
           insert(x, t->right);
           if(height(t->right) - height(t->left) == 2)
               if(t->right->element < x)
                   rotateWithRightChild(t);
                else
                   doubleWithRightChild(t);
           //numNodes++;
       }
       else
           ;
       t->height = max(height(t->left), height(t->right)) + 1;
}

/*
 *Internal method to find the smallest item in a subtree t
 * Return node containing smallest item.
 */
template<class T>
thanosNode<T>* thanosTree<T>::findMin(thanosNode<T>* t) const{
    if(t==nullptr)
        return nullptr;
    if(t->left==nullptr)
        return t;
    return findMin(t->left);
}

/***
 * Find minimum item in the tree. throw underflowexveption if empty
 **/
template<class T>
T& thanosTree<T>::findMin(){
    if(isEmpty())
    {
        throw out_of_range("There is nothing in the tree");
    }
    return findMin(root)->element;
}

/*
 * Internal Method to find the largest item in a subtree t.
 * Return node containing the smallest item
 */
template<class T>
thanosNode<T>* thanosTree<T>::findMax(thanosNode<T> *t) const{
    if(t!=nullptr)
        while(t->right != nullptr)
            t = t->right;
    return t;
}

/***
 * Find the largest item in the tree.
 * Throw UnderflowException if empty
 **/
template<class T>
T& thanosTree<T>::findMax(){
    if(isEmpty())
    {
        throw out_of_range("There is nothing in the tree");
    }
    return (findMax(root)->element);
}

/*
 * Internal method to test if an item is in a subtree
 * x is item to search for
 * t is the node that roots the tree
 */
template<class T>
bool thanosTree<T>::contains(const T &x, thanosNode<T>* t) const{
    if(t==nullptr)
        return false;
    else if(x < t->element)
        return contains(x, t->left);
    else if(t->element < x)
        return contains(x, t->right);
    else
        return true;
}

/*
 * Internal method to make subtree empty
 */
template<class T>
void thanosTree<T>::makeEmpty(thanosNode<T> *&t){
    if(t != nullptr){
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

template<class T>
thanosTree<T>::~thanosTree(){
    makeEmpty();
}

/***
 * Returns true if x is found in the tree
 **/
template<class T>
bool thanosTree<T>::contains(const T &x){
    return contains(x, root);
}

/***
 *Returns true if empty
 **/
template<class T>
bool thanosTree<T>::isEmpty() const{
    return root == nullptr;
}

/*
 * makes the tree empty
 */
template<class T>
void thanosTree<T>::makeEmpty(){
    makeEmpty(root);
}

/***
 * inster x into the tree. duplicates are ignored. twinning is not winning
 **/
template<class T>
void thanosTree<T>::insert(const T &x){
    insert(x, root);
    numNodes++;
}

//Case 1 Rotation
template<class T>
void thanosTree<T>::rotateWithLeftChild(thanosNode<T> *&k2){
    thanosNode<T>* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

//Case 2 Rotation
template<class T>
void thanosTree<T>::rotateWithRightChild(thanosNode<T> *&k1){
    thanosNode<T>* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    k1 = k2;
}

//Case 3 Rotation
template<class T>
void thanosTree<T>::doubleWithLeftChild(thanosNode<T> *&k3){
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

//Case 4 Rotation
template<class T>
void thanosTree<T>::doubleWithRightChild(thanosNode<T> *&k1){
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

//Function to find a value in the tree and return the address of the node
template<class T>
T& thanosTree<T>::find(const T &x, thanosNode<T> *rhs){
    if(rhs==nullptr){
        throw exception_ptr("The requested word cannot be found");
    }else{
        if(x < rhs->element){
            return find(x, rhs->left);
        }
        if(x > rhs->element){
            return find(x, rhs->right);
        }
        return rhs->element;
    }
}

//Private function that prints the tree in order
template<class T>
void thanosTree<T>::printTree(thanosNode<T>* t) const{
    if(t != nullptr){
        printTree(t->left);
        cout << t->element << endl;
        printTree(t->right);
    }
}

//Public function that prints the tree in order
template<class T>
void thanosTree<T>::printTree() const{
    printTree(root);
    cout << endl;
}

//Returns the number of nodes in the tree
template<class T>
int thanosTree<T>::getNumNodes(){
    return numNodes;
}


#endif // AVLTREE_H
