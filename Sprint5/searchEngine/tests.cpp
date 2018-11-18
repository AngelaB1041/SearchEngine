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
#include "catch.hpp"
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
}
