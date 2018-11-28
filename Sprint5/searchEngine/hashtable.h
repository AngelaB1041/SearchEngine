/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: November 24, 2018
 * *****************************************
 *
 */
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <functional>
#include "hashentry.h"
using namespace std;

const long tableSize = 1500000;

template <class T>
class hashTable{
private:
    hashEntry** table;
    long hashThing(T);
    long numWords;

public:
    hashTable();
    hashTable(const hashTable<T>& rhs);
    const hashTable& operator=(const hashTable& rhs);
    ~hashTable();
    void insert(T key, T value);
    bool contains(T x);
    long getNumWords();
    T& search(T key);
    void deleteLinkedList(hashEntry* node);

};

//Constructor
//Good to go
template<class T>
hashTable::hashTable(){
    hashMap = new hashEntry* [tableSize];
    for(long i = 0; i < tableSize; i++)
        hashMap[i] = nullptr;
    numWords = 0;
}

/*
 * Copy Constructor
 * Copies the hash table
 */
template<class T>
hashTable::hashTable(const hashTable<T> &rhs){
    newTable = new hashEntry*[tableSize];
    this->numWords = rhs.numWords;
    for (long i = 0; i < tableSize; i++){
        hashEntry* arg = rhs.table[i];
        hashEntry* dest;

        if(arg == nullptr){
            newTable[i] = nullptr;
            continue;
        }

        dest = new hashEntry();
        dest->value = arg->value;

        newTable[i] = dest;
        arg = arg->next;

        while(arg != nullptr){
            hashEntry* x = new hashEntry();
            dest->next = x;
            dest = x;
        }

        dest->next = nullptr;
    }
}

/*
 * Overloaded assignment operator
 */
template<class T>
hashTable& hashTable::operator =(const hashTable<T>& rhs){
    hashTable temp(rhs);
    std::swap(temp.table, table);
    std::swap(temp.numWords, numWords);
}

//Destructor
//Good
template<class T>
hashTable::~hashTable(){
    for(long i = 0; i < tableSize; i++){
        hashEntry* entry = table[i];
        deleteLinkedList(entry);
    }
    delete[] table;
}

//Hashing function
//Good
template<class T>
long hashTable::hashThing(T thing2Hash){
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
    long bucketNum = hashThing(key);
    hashEntry* prev = nullptr;
    hashEntry* entry = table[bucketNum];
    while(entry != nullptr){
        prev = entry;
        entry = prev->next;
    }

    if (entry == nullptr){
        entry = new hashEntry(key, value);

        if(prev == nullptr){
            table[bucketNum] = entry;
        }else{
            prev->next = entry;
        }
    }else{
        entry->value = value;
        inserted = true;
    }
    if(inserted == true){
        numWords++;
    }
}

/*
 * Contains function that returns a boolean value if the
 * map contains a certain key
 */
template<class T>
bool hashTable::contains(T x){
    bool found = false;
    long hashVal = hashThing(x);
    if(table[hashVal]==nullptr){
        return false;
    }else{
        hashEntry* entry = table[hashVal];
        while(entry != nullptr && entry->key != x)
            entry = entry->next;
        if (entry == nullptr)
            return false;
        else
            found = true;
            return true;
    }
    return found;
}

template<class T>
T& hashTable::search(T key){
    bool found = false;
    long hashVal = hashThing(key);
    hashEntry* entry = table[hashVal];
    while(entry != nullptr){
        if(entry->key == key){
            return entry->value;
            found = true;
        }
        entry = entry->next;
    }
    if(!found)
        throw out_of_range("The value you are looking for is not in the table");
}

template<class T>
void hashTable::deleteLinkedList(hashEntry *node){
    while(node != nullptr){
        if(node->next = nullptr){
            delete node;
            break;
        }else{
            hashEntry* next = node->next;
            delete node;
            node = next;
        }
    }
}

#endif // HASHTABLE_H
