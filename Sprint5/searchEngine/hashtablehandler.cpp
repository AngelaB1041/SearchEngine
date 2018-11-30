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
        return index.search(w);
}

void hashTableHandler::insertWord(word& Word, string& doc){
    if(!index.contains(Word.getWord())){
        index.insert(Word.getWord(), Word);
    }else{
        if(index.search(Word.getWord()).contains(doc)){
            index.search(Word.getWord()).incDoc(doc);
        }else{
            index.search(Word.getWord()).addDoc(doc);
        }
    }
}
