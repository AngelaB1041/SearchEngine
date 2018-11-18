/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: 15 November 2018
 * ****************************
 */
#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <unordered_map>
using namespace std;

class word
{
public:
    word();
    word(string w, string docName);
    word(const word& rhs);
    word& operator=(const word& rhs);
    ~word();
    void setWord(string w);
    string getWord() const;
    map<string, int> getDocs();
    void addDoc(string docID);
    void incDoc(string doc);
    bool operator<(const word& rhs) const;
    bool operator>(const word& rhs) const;
    bool operator==(const word& rhs) const;
    int maxFrequency();
    int findFrequency(string doc);


private:
    string theWord;
    map<string, int> freqInDocs;

};

#endif // WORD_H
