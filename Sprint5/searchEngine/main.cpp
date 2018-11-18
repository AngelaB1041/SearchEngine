/***
 *
 * Chelby Rhoades and Angela Barsallo
 * Created: November 7, 2018
 * Modified: November 18, 2018
 * *****************
 * Version Commits:
 * 11/12/18 - added the project handout and catch.hpp file - CR
 * 11/18/18 - added the myhtml library
 * *****************
 * Project handout: https://docs.google.com/document/d/1V0280YSzjL2NzBByAqymyx8UqOzwtxksSYEvAKMVNRs/edit
 **/

#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include "cheparser.h"

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <myhtml/api.h>


int main(int argc, char* argv[])
{
    //create cheparser object
    cheparser obj;
    //get file's name
    obj.goThru(argv[2], argv[3]);
    //get special word
    //Catch::Session().run();
    obj.closeFile();
    return 0;
}

//also keep a running number of times git has corrupted Chelby: 2 Angela: 1

