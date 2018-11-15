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

                    thanosNode(const T& theElement, thanosNode *lt, thanosNode *rt, int h = 0) : element(theElement), left(lt), right(rt), height(h){}
            };

            thanosNode* root;

            int height(thanosNode *t) const;
            int max(int lhs, int rhs) const;
            void insert(const T& x, thanosNode* & t);
            void rotateWithLeftChild(thanosNode* & k2);
            void rotateWithRightChild(thanosNode* & k2);
            void doubleWithLeftChild(thanosNode* & k3);
            void doubleWithRightChild(thanosNode* & k1);
            thanosNode* findMin(thanosNode *t) const;
            thanosNode* findMax(thanosNode *t) const;
            bool contains(const T& x, thanosNode* t) const;
            void makeEmpty(thanosNode* &t);
            void printTree(thanosNode* t) const;
            thanosNode* clone(thanosNode* t) const;


public:
            thanosTree() : root(NULL){}
            thanosTree(const thanosTree &rhs);
            ~thanosTree();
            const T& findMin();
            const T& findMax();
            bool contains(const T& x);
            bool isEmpty() const;
            void makeEmpty();
            void insert(const int &x);
            const thanosTree& operator=(const thanosTree& rhs);

};

template<class T>
thanosTree<T>::thanosTree(const thanosTree &rhs) : root(NULL){
    *this = rhs;
}

/***
 * Return the height of the node t or -1 if NULL
 **/
template<class T>
int thanosTree<T>::height(thanosNode *t) const{
    return t = NULL ? -1: t->height;
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
void thanosTree<T>::insert(const T& x, thanosNode* &t){
       if (t==NULL)
           t = new thanosNode(x, NULL, NULL);
       else if(x < t->element){
           insert(x, t->left);
           if(height(t->left) - height(t->right)==2)
               if(x < t->left->element)
                   rotateWithLeftChild(t);
                else
                   doubleWithLeftChild(t);
       }
       else if(t->element < x){
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
thanosNode* thanosTree<T>::findMin(thanosNode* t) const{
    if(t==NULL)
        return NULL;
    if(t->left==NULL)
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
thanosNode* thanosTree<T>::findMax(thanosNode *t) const{
    if(t!=NULL)
        while(t->right != NULL)
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
bool thanosTree<T>::contains(const T &x, thanosNode *t) const{
    if(t==NULL)
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
void thanosTree<T>::makeEmpty(thanosNode* &t){
    if(t != NULL){
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = NULL;
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
    return root ==NULL;
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
void thanosTree<T>::insert(const int &x){
    insert(x, root);
}

template<class T>
void thanosTree<T>::rotateWithLeftChild(thanosNode *&k2){
    thanosNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

template<class T>
void thanosTree<T>::rotateWithRightChild(thanosNode *&k1){
    thanosNode* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    k1 = k2;
}

template<class T>
void thanosTree<T>::doubleWithLeftChild(thanosNode *&k3){
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

template<class T>
void thanosTree<T>::doubleWithRightChild(thanosNode *&k1){
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

#endif // AVLTREE_H
