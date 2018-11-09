/*  Chelby Rhoades, Angela
 *  Created: 07 November 2018 Chelby Rhoades
 *  Modified: 09 November 2018 Chelby Rhoades
 *  ThanosTree is our AVLtree, but renamed because of the nature of the AVLtree. Everything is perfectly balanced, as it should be.
 */


#ifndef THANOSTREE_H
#define THANOSTREE_H
#include <iostream>
using namespace std;

class thanosTree{
    private:
            class thanosNode
            {
            public:
                    int element;
                    thanosNode *left;
                    thanosNode *right;
                    int height;

                    thanosNode(const int& theElement, thanosNode *lt, thanosNode *rt, int h = 0) : element(theElement), left(lt), right(rt), height(h){}
            };
            thanosNode *root;
   public:
            thanosTree() : root(NULL){}
            thanosTree(const thanosTree &rhs) : root(NULL)
            {
                *this = rhs;
            }
            ~thanosTree()
            {
                makeEmpty();
            }
            /***
             * Find minimum item in the tree. throw underflowexveption if empty
             **/
            const int& findMin() const
            {
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
            const int &findMax() const
            {
                if(isEmpty())
                {
                    throw UnderflowException();

                }
                return findMax(root)->element;
            }
};

#endif // AVLTREE_H
