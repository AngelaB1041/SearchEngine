#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;

class word
{
public:
    word();
    word(string w, int docID);
    word(const word& rhs);
    word& operator=(const word& rhs);
    ~word();
    string getWord() const;
    map<int> getDocs() const;



private:
    string theWord;
    map<int> documents;
};

#endif // WORD_H
