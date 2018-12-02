/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: November 24, 2018
 * *****************************************
 * Hash table with collisions handled by chaining using linked lists.
 *
 * Based it on these implementations:
 * http://www.algolist.net/Data_structures/Hash_table/Chaining
 * https://www.sanfoundry.com/cpp-program-hash-tables-singly-linked-list/
 *
 * *****************************************
 * Edit History
 *
 * Modified: December 1 2018
 * Added function to clear the index
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

const long tableSize = 3000000;

template <class T, class U>
class hashTable{
public:
    hashTable();
    hashTable(const hashTable<T, U>& rhs);
    const hashTable<T, U>& operator=(const hashTable<T, U>& rhs);
    ~hashTable();
    void insert(T key, U value);
    bool contains(T x);
    long getNumWords();
    U& search(T key);
    void deleteLinkedList(hashEntry<T, U>* node);
    void clearHashTable();
    void printTable();

private:
    hashEntry<T, U>** table;
    long hashThing(T);
    long numWords;
};

//Constructor
//Good to go
template <class T, class U>
hashTable<T, U>::hashTable(){
    table = new hashEntry<T, U>* [tableSize];
    for(long i = 0; i < tableSize; i++)
        table[i] = nullptr;
    numWords = 0;
}

/*
 * Copy Constructor
 * Copies the hash table
 */
template <class T, class U>
hashTable<T, U>::hashTable(const hashTable<T, U> &rhs){
    hashEntry<T, U>** newTable;
    newTable = new hashEntry<T, U>*[tableSize];
    this->numWords = rhs.numWords;
    for (long i = 0; i < tableSize; i++){
        hashEntry<T, U>* arg = rhs.table[i];
        hashEntry<T, U>* dest;

        if(arg == nullptr){
            newTable[i] = nullptr;
            continue;
        }

        dest = new hashEntry<T, U>();
        dest->value = arg->value;

        newTable[i] = dest;
        arg = arg->next;

        while(arg != nullptr){
            hashEntry<T, U>* x = new hashEntry<T, U>();
            dest->next = x;
            dest = x;
        }

        dest->next = nullptr;
    }
}

/*
 * Overloaded assignment operator
 */
template <class T, class U>
const hashTable<T, U>& hashTable<T, U>::operator =(const hashTable<T, U>& rhs){
    hashTable<T, U> temp(rhs);
    std::swap(temp.table, table);
    std::swap(temp.numWords, numWords);
}

//Destructor
template <class T, class U>
hashTable<T, U>::~hashTable(){
    clearHashTable();
}

//Hashing function
//Good
template <class T, class U>
long hashTable<T, U>::hashThing(T thing2Hash){
    hash<T> hasher;
    size_t hashed = hasher(thing2Hash);
    return hashed % tableSize;

}

template <class T, class U>
long hashTable<T, U>::getNumWords(){
    return numWords;
}

/*
 * Insert Function
 * Good
 */
template <class T, class U>
void hashTable<T, U>::insert(T key, U value){
    bool inserted = false;
    long bucketNum = hashThing(key);
    hashEntry<T, U>* prev = nullptr;
    hashEntry<T, U>* entry = table[bucketNum];
    while(entry != nullptr){
        prev = entry;
        entry = prev->next;
    }

    if (entry == nullptr){
        entry = new hashEntry<T, U>(key, value);

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
template <class T, class U>
bool hashTable<T, U>::contains(T x){
    bool found = false;
    long hashVal = hashThing(x);
    if(table[hashVal]==nullptr){
        return false;
    }else{
        hashEntry<T, U>* entry = table[hashVal];
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

template <class T, class U>
U& hashTable<T, U>::search(T key){
    bool found = false;
    long hashVal = hashThing(key);
    hashEntry<T, U>* entry = table[hashVal];
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

//Function that deletes the linked list in a bucket of the table
template <class T, class U>
void hashTable<T, U>::deleteLinkedList(hashEntry<T, U> *node){
    while(node != nullptr){
        if(node->next = nullptr){
            delete node;
            break;
        }else{
            hashEntry<T, U>* next = node->next;
            delete node;
            node = next;
        }
    }
}

//Function that clears the Hash Table
template <class T, class U>
void hashTable<T, U>::clearHashTable(){
    for(long i = 0; i < tableSize; i++){
        hashEntry<T, U>* entry = table[i];
        deleteLinkedList(entry);
    }
    delete[] table;
}

template<class T, class U>
void hashTable<T, U>::printTable(){
    hashEntry<T, U>* temp;
    for(long i = 0; i < tableSize; i++){
        temp = table[i];
        if(temp != nullptr){
            while(temp != nullptr){
                cout << temp->value;
                temp = temp->next;
            }
        }
    }
}

#endif // HASHTABLE_H
