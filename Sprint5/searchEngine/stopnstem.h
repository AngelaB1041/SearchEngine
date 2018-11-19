/*  Chelby Rhoades
 *  Created: November 13, 2018
 *  Modified: November 18, 2018
 *******************
 * Version Commits:
 * 11/18/2018
 *      added
 *******************
 * This class is what refines the word searching ability of another class. Through the stemmer, it removes any unnecessary prefix/suffixes of words and checks to see if they are stop words.
 */

#ifndef STOPNSTEM_H
#define STOPNSTEM_H
#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;
class stopNstem
{
private:
    int sizeS;   //the size of the stop words
    string buffer; //a buffer
    //the stop words. For this, only one argument is necessary
    unordered_set<string> stopWords ={"a", "about", "above" , "according" , "across", "actually", "adj", "after", "afterwards", "again", "against", "all", "almost","alone","along","already","also","although","always","am","among","amongst","an","and","another","any","anyhow","anyone","anything","anywhere","are","aren't","around","as","at","be","become","because","become","becomes","becoming","been","before","beforehand","begin","beginning","behind","below","beside","besides","between","beyond","billion","both","but","by","can","cannot","caption","co","could","couldn't","did","didn't","do","does","doesn't","don't","down","during","each","eg","eight","eighty","either","else","elsewhere","end","ending","enough","etc","even","ever","every","everyone","everything","everywhere","except","few","fifty","first","five","for","former","formerly","forty","found","four","form","from","further","had","has","hasn't","have","haven't","he","hence","her","here","hereafter","hereby","herein","hereupon","hers","herself","him","himself","his","how","however","hundred","ie","if","in","inc","Indeed","instead","into","is","isn't","it","its","it's","itself","last","later","latter","latterly","least","less","let","like","likely","ll","ltd","made","make","makes","many","maybe","me","meantime","meanwhile","might","million","miss","more","moreover","most","mostly","mr","mrs","much","must","my","myself","namely","neither","never","nevertheless","next","nine","ninety","no","nobody","none","nonetheless","noon","nor","not","nothing","now","nowhere","of","off","often","on","once","one","only","onto","or","other","others","otherwise","our","ours","ourselves","out","over","overall","own","per","perhaps","rather","re","recent","recently","same","seem","seemed","seeming","seems","seven","seventy","several","shan't","she","she'll","should","shouldn't","since","six","sixty","so","some","somehow","someone","sometime","sometimes","somewhere","still","stop","such","talking","ten","than","that","that's","the","their","them","themselves","thence","there","thereafter","thereby","therefore","therein","thereupon","these","they","thirty","this","those","though","thousand","three","through","throughout","thru","thus","to","together","too","toward","towards","trillion","twenty","two","under","unless","unlike","unlikely","until","up","upon","us","used","using","very","via","was","wasn't","we","well","were","weren't","what","whatever","when","whence","whenever","where","whereafter","whereas","whereby","wherein","whereupon","wherever","whether","which","while","whither","who","whoever","whole","whom","whomever","whose","why","will","with","within","without","won","would","wouldn't","yes","yet","you","your","yours","yourself","yourselves","about","above","according","across","actually","after","afterwards","again","against","all","almost","alone","along","already","also","although","always","am","among","amongst","an","and","another","any","anyhow","anyone","anything","anywhere","are","aren't","around","as","at","be","because","become","becomes","becoming","been","before","beforehand","behind","below","beside","besides","between","beyond","both","but","by","can","cannot","co","could","couldn't","did","didn't","do","does","doesn't","don't","down","during","each","eg","eight","either","else","elsewhere","enough","etc","even","ever","every","everyone","everything","everywhere","except","few","first","five","for","former","formerly","four","from","further","had","has","hasn't","have","haven't","he","hence","her","here","hereafter","hereby","herein","hereupon","hers","herself","him","himself","his","how","however","ie","if","in","inc","instead","into","is","isn't","it","it's","its","itself","last","later","latter","latterly","least","less","let","like","likely","ltd","many","maybe","me","meanwhile","might","more","moreover","most","mostly","much","must","my","myself","namely","neither","never","nevertheless","next","nine","no","nobody","none","nor","not","nothing","now","nowhere","of","off","often","on","once","one","only","onto","or","other","others","otherwise","our","ours","ourselves","out","over","overall","own","per","perhaps","rather","re","same","seem","seemed","seeming","seems","seven","several","she","should","shouldn't","since","six","so","some","somehow","someone","sometime","sometimes","somewhere","still","such","than","that","that's","the","their","them","themselves","thence","there","thereafter","thereby","therefore","therein","thereupon","these","they","this","those","though","three","through","throughout","thru","thus","to","together","too","toward","towards","two","under","unless","unlikely","until","up","upon","us","used","using","very","via","was","wasn't","we","well","were","weren't","what","whatever","when","whence","whenever","where","whereafter","whereas","whereby","wherein","whereupon","wherever","whether","which","while","whither","who","whoever","whole","whom","whose","why","will","with","within","without","would","wouldn't","yes","yet","you","your","yours","yourself","yourselves","me","my","myself","we","our","ours","ourselves","you","your","yours","yourself","yourselves","he","him","his","himself","she","her","hers","herself","it","its","itself","they","them","their","themselves","what","which","who","whom","this","that","these","those","am","is","are","was","were","be","been","have","has","had","do","does","did","a","an","the","and","but","if","or","because","as","until","while","of","at","by","for","with","about","against","between","into","through","during","before","after","above","below","to","from","up","down","in","out","on","off","over","under","again","further","once","here","there","when","where","why","how","all","any","both","each","few","more","most","other","some","such","no","nor","not","only","own","same","so","than","too","very","can","will","should","now"};
    unordered_map<string, string> stems; //the stems. an unordered map takes two arguments
public:
    stopNstem();    //constructor
    ~stopNstem();   //destructor
    string cutStem(std::string&);  //calls the porter2_stemmer class
    void addToStems(std::string&);  //adds a stem word to the stems map
    bool checkStop(std::string&);    //checks if it is a stop word. If it is, it returns true
    bool seeIfInStems(std::string&); //sees if it is in the unordered map
    void printMap();
};

#endif // STOPNSTEM_H
