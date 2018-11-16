///*  Chelby Rhoades, Angela
// *  Created: 07 November 2018 Chelby Rhoades
// *  Modified: 09 November 2018 Chelby Rhoades
// *  ThanosTree is our AVLtree, but renamed because of the nature of the AVLtree. Everything is perfectly balanced, as it should be.
// */


//#ifndef THANOSTREE_H
//#define THANOSTREE_H
//#include <iostream>
//using namespace std;

//class thanosTree{
//    private:
//            class thanosNode
//            {
//            public:
//                    int element;
//                    thanosNode *left;
//                    thanosNode *right;
//                    int height;

//                    thanosNode(const int& theElement, thanosNode *lt, thanosNode *rt, int h = 0) : element(theElement), left(lt), right(rt), height(h){}
//            };
//            thanosNode *root;
//   public:
//            thanosTree() : root(NULL){}
//            thanosTree(const thanosTree &rhs) : root(NULL)
//            {
//                *this = rhs;
//            }
//            ~thanosTree()
//            {
//                makeEmpty();
//            }
//            /***
//             * Find minimum item in the tree. throw underflowexveption if empty
//             **/
//            const int& findMin() const
//            {
//                if(isEmpty())
//                {
//                    throw UnderflowException();

//                }
//                return findMin(root)->element;
//            }

//            /***
//             * Find the largest item in the tree.
//             * Throw UnderflowException if empty
//             **/
//            const int &findMax() const
//            {
//                if(isEmpty())
//                {
//                    throw UnderflowException();

//                }
//                return findMax(root)->element;
//            }

//            /***
//             * Returns true if x is found in the tree
//             **/
//            bool contains(const int &x) const
//            {
//                return contains(x, root);
//            }

//            /***
//             *Returns true if empty
//             **/
//            bool isEmpty() const
//            {
//                return root ==NULL;
//            }
//            /*
//             * makes the tree empty
//             */
//            void makeEmpty()
//            {
//                makeEmpty(root);
//            }

//            /***
//             * inster x into the tree. duplicates are ignored. twinning is not winning
//             **/
//            void insert(const int &x)
//            {
//                insert(x, root);
//            }



//private:
//            /***
//             * Return the height of the node t or -1 if NULL
//             **/
//            int height(thanosNode *t) const
//            {
//                return t = NULL ? -1: t->height;
//            }

//            int max(int lhs, int rhs) const
//            {
//                return lhs > rhs ? lhs : rhs;
//            }

//            /***
//             * Internal method to insert into a subtree.
//             * x is the item to insert
//             * t is the node that roots the subtree.
//             * Set the new root of the subtree
//             **/
//            void insert(const int &x, thanosNode * &t)
//            {

//            }
//};


//#endif // AVLTREE_H
