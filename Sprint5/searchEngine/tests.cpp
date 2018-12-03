/* Angela Barsallo and Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: November 16, 2018
 * **************************
 */
#include <iostream>
#include <string>
#include <cstring>
#include "thanosTree.h"
#include "word.h"
#include <map>
#include "stopnstem.h"
#include "catch.hpp"
#include "avlhandler.h"
#include "word.h"
#include "hashtablehandler.h"
using namespace std;

TEST_CASE("thanosTree class", "[thanosTree]"){
    thanosTree<int> tree;
    tree.insert(2);
    tree.insert(1);
    tree.insert(4);
    tree.insert(3);
    tree.insert(5);
    tree.insert(6);
    tree.insert(9);

    SECTION("Getting size of AVL Tree"){
        REQUIRE(tree.getNumNodes()==7);
    }

    tree.printTree();
    SECTION("Putting string objects into an avl tree")
    {
        thanosTree<string> dogs;
        dogs.insert("goldens");
        dogs.insert("dobermen");
        dogs.insert("germanShepherds");
        dogs.insert("pugs");
        dogs.insert("chihuahuas");

        REQUIRE(dogs.getNumNodes()==5);
        dogs.printTree();

    }
}
TEST_CASE("StopNStemClass", "[stopNStem]")
{
    string one = "running";
    string two = "ran";
    string three = "agreement";
    stopNstem obj;

    SECTION("checking if its a stop word")
    {
        bool checkOne = obj.checkStop(one);
        REQUIRE(checkOne == false);
    }
    SECTION("stemming a word")
    {
        obj.cutStem(one);
        REQUIRE(one == "run");
    }
}
TEST_CASE("Word object in AVL", "[word obj AVL]")
{
    thanosTree<word> thanosWords;
    string kitties = "cats";
    string goodCat = "cookieDough";   //chelby's cat's name
    string goodCatAgain = "cookieDough";
    string otherCat = "honeyBunchesOfOats"; //chelby's other cat
    word first(kitties, goodCat);

    thanosWords.insert(first);

    SECTION("checking to see if word is inserted")
    {
        REQUIRE(thanosWords.getNumNodes() == 1);

    }
    SECTION("adding a document/using addDoc Function")
    {
        first.addDoc(otherCat);
        first.incDoc(otherCat);
        first.incDoc(otherCat);
        first.incDoc(otherCat);

        REQUIRE(first.findFrequency(otherCat) == 4);
    }
}

TEST_CASE("avlHander", "[avlHandler]")
{
 /*
  * Putting a word object into a thanosTree using the avlHandler
  */

    avlHandler handyman;
    string str1 = "catapult";
    string doc1 = "47289974";

    string str2 = "banana pancake";
    string doc2 = "6859394";
    word first(str1, doc1);  //creation of the word object
    handyman.insertWord(first, doc1); //inserts the word object into the avl tree;

    string top = handyman.searchWord(first).maxFrequency();
    //map<string, int> nextStep = found.getDocs();

    REQUIRE(top == "47289974");
}
TEST_CASE("hashTable", "[hashtable]")
{
    hashTableHandler noises;

    string one = "woof";
    string two = "bark";
    string three = "bow wow";
    string four = "ruff";
    string five = "meow";
    string six = "mew";
    string dog = "doggie";
    string cat = "kitty";

    word rover(one, dog);
    word duke(two, dog);
    word peanut(three, dog);
    word daisy(four, dog);
    noises.insertWord(rover, dog);
    noises.insertWord(duke, dog);
    noises.insertWord(peanut, dog);
    noises.insertWord(daisy, dog);
    word cookieDough(five, cat);
    word honeyBun(six, cat);

    string top = noises.searchWord(daisy).maxFrequency();
    cout << top;
    REQUIRE(top == dog);
}
