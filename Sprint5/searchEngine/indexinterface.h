#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H
#include "word.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class indexInterface
{
public:
    virtual ~indexInterface() = 0;
    //virtual void loadIndex() = 0;
    virtual void insertWord(word& w, string& doc) = 0;
    virtual word& searchWord(word& w) = 0;
    //virtual void saveIndex() = 0;
};

//indexInterface::~indexInterface(){

//}


#endif // INDEXINTERFACE_H
