/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: 15 November 2018
 * ****************************
 * Word object class that holds the actual word that is being indexed
 * and a map that contains the documents it appears in and the number of times
 * it appears in each document. Lastly, it keeps track of how many total times
 * the word appears in the entire index.
 */

/* Edit History
 ******************************
 * Modified: November 16 2018
 * Added implementation for all functions except frequency ones, contains, and top 15
 *
 * Modified:
 */
#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

/* Using this approach to get the top 15 documents
 * https://stackoverflow.com/questions/
 * 1367429/sorting-a-stdmap-by-value-before-output-destroy
 */
struct IntCmp{
    bool operator()(const pair<string, int>& lhs, const pair<string, int>& rhs){
        return lhs.second > rhs.second;
    }
};

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
    int getTotalFrequency();
    void addDoc(string docID);
    void incDoc(string doc);
    bool operator<(const word& rhs) const;
    bool operator>(const word& rhs) const;
    bool operator==(const word& rhs) const;
    string maxFrequency();
    int findFrequency(string doc);
    void printWord();
    bool contains(string doc);
    void printTop15();
    vector<pair<string, int>> top15();
    friend ostream& operator <<(ostream& os, const word&);


private:
    string theWord;
    map<string, int> freqInDocs;
    int totalFrequency;

};

#endif // WORD_H

