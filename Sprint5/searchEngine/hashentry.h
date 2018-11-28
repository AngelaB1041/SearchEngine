/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 ***************************************
 * Created November 26, 2018
 *
 */
#ifndef HASHENTRY_H
#define HASHENTRY_H
#include <cstdlib>
#include <iostream>
using namespace std;

template<class T>
class hashEntry{
    template<class U> friend class hashTable;
private:
    T key;
    T value;
    hashEntry* next;

public:
    hashEntry(T key, T value){
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }

};

template<class T>
hashEntry::hashEntry(){
    this->next = nullptr;
}

#endif // HASHENTRY_H
