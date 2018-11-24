/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: November 24, 2018
 * *****************************************
 *
 */
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

template <class T>
class hashTable{
private:
    long numBuckets;
    vector<T> hashMap[numBuckets];
    long hashThing(T&);
    long numWords;

public:
    hashTable(long buckets);
    ~hashTable();
    void insert(T& x);

};

template<class T>
hashTable::hashTable(long buckets){
    hashMap = new vector<T>* [buckets];
    for(long i = 0; i < buckets; i++)
        hashMap[i] = new vector<T>;
}

template<class T>
hashTable::~hashTable(){
    for(long i = 0; i < numBuckets; i++)
        delete table[i];
}

template<class T>
long hashTable::hashThing(T& thing2Hash){
    hash<T> hasher;
    size_t hashed = hasher(thing2Hash);
    return hashed % numBuckets;

}

template<class T>
void hashTable::insert(T& x){
    bool inserted = false;
    long bucketNum = hashThing(x);
    hashMap[bucketNum]->
}

#endif // HASHTABLE_H
