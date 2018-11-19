/***
 * Chelby Rhoades and Angela Barsallo
 * Created: November 7, 2018
 * Modified: November 15, 2018
 * *****************
 * Version Commits:
 * 11/12/18 - added the project handout and catch.hpp file - CR
 * *****************
 * Project handout: https://docs.google.com/document/d/1V0280YSzjL2NzBByAqymyx8UqOzwtxksSYEvAKMVNRs/edit
 ***/
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "thanosTree.h"
#include "word.h"
#include "catch.hpp"
#include <string>
#include <cstring>
#include "catch.hpp"
//#include <myhtml/api.h>
#include "parser.h"
using namespace std;

int runCatchTests(){
    return Catch::Session().run();
}



int main(int argc, char* argv[])
{
    //Catch::Session().run();
    //create cheparser object
    //parser obj;
    //get file's name and special word
    //obj.goThru(argv[2], argv[3]);
    cout << "Hello World!" << endl;
    return 0;
}

//also keep a running number of times git has corrupted Chelby: 1 Angela:
