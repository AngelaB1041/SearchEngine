#ifndef HASHENTRY_H
#define HASHENTRY_H
#include <cstdlib>
#include <iostream>
using namespace std;

template<class T, class V>
class hashEntry{
    template<class U, class X> friend class hashTable;
private:
    T key;
    V value;
    hashEntry* next;

public:
    hashEntry();
    hashEntry(T key, V value){
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }

};

//template<class T>
//hashEntry::hashEntry(){

//}

#endif // HASHENTRY_H
