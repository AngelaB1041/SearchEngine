/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: Novemeber 18, 2018
 * **************************************
 * Edit History
 *
 * Modified: December 1 2018
 * Added function to clear the index
 * Added function to save to persistant index
 */
#include "avlhandler.h"
#include "thanosTree.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

avlHandler::avlHandler(){

}

avlHandler::~avlHandler(){

}

/*
 * Function that searches for a specific word in the AVL tree
 */
word& avlHandler::searchWord(word& w){
    //Check to see if the word is in the AVL tree
    if(!index.contains(w))
        //If not, throw exception
        throw out_of_range("This word is not in the index");
    else
        //If in the index, return object from the index
        return index.find(w);
}

/*
 * Function that inserts new word object into the AVL Tree index
 */
void avlHandler::insertWord(word& Word, string& doc){
    //If word not already in index, add word to index
    if(!index.contains(Word)){
        index.insert(Word);
    }else{
        //If word in index and document already in that word's index, increment
        //the number of times it appears in the document
        if(index.find(Word).contains(doc)){
            index.find(Word).incDoc(doc);
        //Else, add the new document to the word's index
        }else{
            index.find(Word).addDoc(doc);
        }
    }
}

/*
 * Function that clears out the index
 */
void avlHandler::yeetIndex(){
    index.makeEmpty();
}

/*
 * Function that writes the index out to a
 * .txt file
 */
void avlHandler::saveIndex(){
    ofstream saveIndex;
    saveIndex.open(indexFileName);
    saveIndex << getTotalDocs() << endl;
    saveIndex << getTotalWords() << endl;
    saveIndex << getAverageWordsperDoc() << endl;
    index.saveTree(saveIndex);
    saveIndex.close();
}
