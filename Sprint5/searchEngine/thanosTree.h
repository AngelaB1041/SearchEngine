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

            thanosNode *root;

            int height(thanosNode *t) const;
            int max(int lhs, int rhs) const;
            void insert(const T& x, thanosNode* & t);
            void rotateWithLeftChild(thanosNode* & k2);
            void rotateWithRightChild(thanosNode* & k2);
            void doubleWithLeftChild(thanosNode* & k3);
            void doubleWithRightChild(thanosNode* & k1);

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

};

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
void thanosTree<T>::insert(const T &x, thanosNode* &t){

}

/***
 * Find minimum item in the tree. throw underflowexveption if empty
 **/
template<class T>
const int& thanosTree<T>::findMin() const{
    if(isEmpty())
    {
        throw UnderflowException();
    }
    return findMin(root)->element;
}

/***
 * Find the largest item in the tree.
 * Throw UnderflowException if empty
 **/
template<class T>
const int &findMax() const{
    if(isEmpty())
    {
        throw UnderflowException();
    }
    return (findMax(root)->element);
}

template<class T>
thanosTree<T>::thanosTree(const thanosTree &rhs) : root(NULL){
    *this = rhs;
}

template<class T>
thanosTree<T>::~thanosTree(){
    makeEmpty();
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



#endif // AVLTREE_H
