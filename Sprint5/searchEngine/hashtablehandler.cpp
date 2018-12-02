/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: November 28, 2018
 ****************************************
 * Edit History
 * Modified: December 1 2018
 * Added function to clear the index
 */
#include "hashtablehandler.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

hashTableHandler::hashTableHandler()
{

}

hashTableHandler::~hashTableHandler(){

}

word &hashTableHandler::searchWord(word &w){
    if(!index.contains(w.getWord()))
        cout << "This word is not in the index" << endl;
    else
        return index.search(w.getWord());
}

/*
 * Insert word function that inserts a word object into the hash table
 * Also handles if the word already exists in the index
 */
void hashTableHandler::insertWord(word& Word, string& doc){
    //theWord is the literal word we are trying to insert
    string theWord = Word.getWord();

    //Check to see if the the word is already in the index
    if(!index.contains(theWord)){
        //If not, insert the new word object
        index.insert(theWord, Word);

    }else{
        /* If already in the index, check if the word has already appeared
         * in that document
         */
        if(index.search(theWord).contains(doc)){
            //Increment the number of times the word appears in the document
            index.search(theWord).incDoc(doc);

        }else{
            //Add the document to the map of documents for that word
            index.search(theWord).addDoc(doc);
        }
    }
}

/*
 * Function that writes the index out to a
 * .txt file
 */
void hashTableHandler::saveIndex(){
    ofstream saveIndex;
    saveIndex.open(indexFileName);
    saveIndex << getTotalDocs() << endl;
    saveIndex << getTotalWords() << endl;
    saveIndex << getAverageWordsperDoc() << endl;
    index.saveTable(saveIndex);
    saveIndex.close();
}

/*
 * Function that clears out the index
 */
void hashTableHandler::yeetIndex(){
    index.clearHashTable();
}
