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
*/
#ifndef THANOSTREE_H
#define THANOSTREE_H
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <string>
#include "word.h"
using namespace std;

template <class T>
class thanosTree{

private:
            template <class T>
            class thanosNode{
            public:
                    T element;
                    thanosNode *left;
                    thanosNode *right;
                    int height;
                    //string key;

                    thanosNode(const T& theElement, thanosNode *lt, thanosNode *rt, int h = 0) : element(theElement), left(lt), right(rt), height(h){
                        //key = "\0";
                    }
            };

            thanosNode<T>* root;
            int numNodes;

            int height(thanosNode<T> *t) const;
            int max(int lhs, int rhs) const;
            void insert(const T& x, thanosNode<T>* & t);
            void rotateWithLeftChild(thanosNode<T>* & k2);
            void rotateWithRightChild(thanosNode<T>* & k2);
            void doubleWithLeftChild(thanosNode<T>* & k3);
            void doubleWithRightChild(thanosNode<T>* & k1);
            thanosNode* findMin(thanosNode<T> *t) const;
            thanosNode* findMax(thanosNode<T> *t) const;
            bool contains(const T& x, thanosNode<T>* t) const;
            void makeEmpty(thanosNode<T>* &t);
            void printTree(thanosNode<T>* t) const;
            thanosNode<T>* clone(thanosNode<T>* t) const;
            void copy(thanosNode<T>* t);
            void clear(thanosNode<T>*& t);

public:
            thanosTree() : root(nullptr){}
            thanosTree(const thanosTree<T> &rhs);
            ~thanosTree();
            const T& findMin();
            const T& findMax();
            bool contains(const T& x);
            bool isEmpty() const;
            void makeEmpty();
            void insert(const T &x);
            const thanosTree& operator=(const thanosTree& rhs);
            int getNumNodes();
            thanosNode& find(const T& x, thanosNode<T>* rhs);


};
//Copy function that can be called in the copy constructor
template<class T>
void thanosTree<T>::copy(thanosNode<T> *t){
    if(t!=nullptr){
        insert(t,t->key);
        copy(t->right);
        copy(t->left);
    }
}

template<class T>
thanosTree<T>::thanosTree(const thanosTree<T> &rhs) : root(nullptr){
    *this = rhs;
}

/***
 * Return the height of the node t or -1 if NULL
 **/
template<class T>
int thanosTree<T>::height(thanosNode<T> *t) const{
    return t = nullptr ? -1: t->height;
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
void thanosTree<T>::insert(const T& x, thanosNode<T> *&t){
       if (t==nullptr)
           t = new thanosNode(x, nullptr, nullptr);
           //t->key = k;
       else if(x < t->element){
           //insert(x, k, t->left);
           insert(x, t->left);
           if(height(t->left) - height(t->right)==2)
               if(x < t->left->element)
                   rotateWithLeftChild(t);
                else
                   doubleWithLeftChild(t);
       }
       else if(t->element < x){
           //insert(x, k, t->right);
           insert(x, t->right);
           if(height(t->right) - height(t->left) == 2)
               if(t->right->element < x)
                   rotateWithRightChild(t);
                else
                   doubleWithRightChild(t);
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
thanosNode* thanosTree<T>::findMin(thanosNode<T>* t) const{
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
const T& thanosTree<T>::findMin() const{
    if(isEmpty())
    {
        throw UnderflowException();
    }
    return findMin(root)->element;
}

/*
 * Internal Method to find the largest item in a subtree t.
 * Return node containing the smallest item
 */
template<class T>
thanosNode* thanosTree<T>::findMax(thanosNode<T> *t) const{
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
const T& thanosTree<T>::findMax() const{
    if(isEmpty())
    {
        throw UnderflowException();
    }
    return (findMax(root)->element);
}

/*
 * Internal method to test if an item is in a subtree
 * x is item to search for
 * t is the node that roots the tree
 */
bool thanosTree<T>::contains(const T &x, thanosNode<T> *t) const{
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
bool thanosTree<T>::contains(const T &x) const{
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
    //insert(x, k, root);
    insert(x, root);
}

template<class T>
void thanosTree<T>::rotateWithLeftChild(thanosNode<T> *&k2){
    thanosNode<T>* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

template<class T>
void thanosTree<T>::rotateWithRightChild(thanosNode<T> *&k1){
    thanosNode<T>* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    k1 = k2;
}

template<class T>
void thanosTree<T>::doubleWithLeftChild(thanosNode<T> *&k3){
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

template<class T>
void thanosTree<T>::doubleWithRightChild(thanosNode<T> *&k1){
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

//Function to find a value in the tree and return the address of the node
template<class T>
thanosNode& thanosTree<T>::find(const T &x, thanosNode<T> *rhs){
    if(rhs==nullptr){
        throw exception_ptr("The requested word cannot be found");
    }else{
        if(x < rhs->element){
            return find(x, rhs->left);
        }
        if(x > rhs->element){
            return find(x, rhs->right);
        }
        return *rhs;
    }
}

template<class T>
void thanosTree<T>::printTree(thanosNode<T>* t) const{
    if(t != nullptr){
        printTree(t->left);
        cout << t->element << endl;
        printTree(t->right);
    }
}

#endif // AVLTREE_H
