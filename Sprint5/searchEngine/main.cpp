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
#include "thanosTree.h"
#include "word.h"
#include "catch.hpp"
#include "parser.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stdexcept>
#include <dirent.h>
#include "userI.h"
using namespace std;

int runCatchTests(){
    return Catch::Session().run();
}

/* adapted from:
 * https://stackoverflow.com/questions/612097
 * /how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
 */

vector<string> get_files_at_path_with_extn(string path, string extn) {
    vector<string> result;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            int len = strlen(ent->d_name);
            if (ent->d_type == DT_REG &&
                len > extn.length() &&
                strcmp(ent->d_name + len - extn.length(), extn.c_str()) == 0)
                result.push_back(ent->d_name);
        }
        closedir(dir);
    }
    else {
        throw invalid_argument("Provided path could not be opened");
    }
    return result;
}

int main(int argc, char* argv[]) {
    string dir_path;
    string extention = ".json";
    if (argc < 2) {
        dir_path = ".";
    }
    else {
        dir_path = argv[1];
    }
    vector<string> files = get_files_at_path_with_extn(dir_path, extention);
    for (int i = 0; i < files.size(); i++)
        cout << files[i] << endl;

    string wor = argv[2];
    userI oRunner;
    oRunner.promptForMode(files, argv[1], wor);
    return 0;
}

//also keep a running number of times git has corrupted Chelby: 1 Angela:
