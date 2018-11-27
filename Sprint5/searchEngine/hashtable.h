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
    long numBuckets = 1500000;
    vector<T> hashMap[numBuckets];
    long hashThing(T&);
    long numWords;

public:
    hashTable(long buckets);
    ~hashTable();
    void insert(T key, T value);
    bool contains(T& x);
    long getNumWords();

};

//Constructor
template<class T>
hashTable::hashTable(long buckets){
    hashMap = new vector<T> [buckets];
    for(long i = 0; i < buckets; i++)
        hashMap[i] = new vector<T>;
    numWords = 0;
}

//Destructor
//Good
template<class T>
hashTable::~hashTable(){
    for(long i = 0; i < numBuckets; i++)
        delete hashMap[i];
}

//Hashing function
//Good
template<class T>
long hashTable::hashThing(T& thing2Hash){
    hash<T> hasher;
    size_t hashed = hasher(thing2Hash);
    return hashed % numBuckets;

}

template<class T>
long hashTable::getNumWords(){
    return numWords;
}

/* Insert Function
 * Needs to be fixed
 */
template<class T>
void hashTable::insert(T key, T value){
    bool inserted = false;
    long bucketNum = hashThing(x);
    hashMap[bucketNum].push_back(x);
    inserted = true;
    if(inserted == true){
        numWords++;
    }
}

template<class T>
bool hashTable::contains(T &x){
    bool found = false;
    while(!found){
        for(long i = 0; i < numBuckets; i++){
            for(int j = 0; j < hashMap[i].size; j++){
                if(hashMap[i][j]==x)
                    found = true;
            }
        }
    }
}

#endif // HASHTABLE_H
