#include "catch.hpp"
#include <iostream>
#include "stopnstem.h"
/*  Chelby Rhoades
 * Created: November 15, 2018
 * Modified: November 15, 2018
 *          Added an extra assertion on the 'StopNStemClass' case. CR
 *
 * This class is not required for the project, but they sure do help in checking on the code.
 *
 */
TEST_CASE("StopNStemClass", "[stopNStem]")
{
    string one = "running";
    string two = "ran";
    string three = "agreement";
    stopNstem obj;

    SECTION("checking if its a stop word")
    {
        string shouldBe = "the";
        bool checkOne = obj.checkStop(one);
        REQUIRE(checkOne == false);

        bool checkAgain = obj.checkStop(shouldBe);
        REQUIRE(checkAgain == true);
    }
    SECTION("stemming a word")
    {
        obj.cutStem(one);
        REQUIRE(one == "run");
    }
}
