/*
 * Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created:
 */
#ifndef THANOSNODE_H
#define THANOSNODE_H

template<class T>
class thanosNode{
    template<class U> friend class thanosTree;
public:
        T element;
        thanosNode<T> *left;
        thanosNode<T> *right;
        int height;

        thanosNode(T d, thanosNode<T> *t, thanosNode<T> *k){
            element = d;
            left = t;
            right = k;
        }
};

#endif // THANOSNODE_H
