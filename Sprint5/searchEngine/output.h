/* Owner: Chelby Rhoades
 * Created: November 20, 2018
 *
 * This is the output file in which interacts with the user.
 */
#ifndef OUTPUT_H
#define OUTPUT_H
#include <iostream>
#include <vector>
#include <string>
using std::string;

class output
{
public:
    output();
    ~output();
    void promptForMode(std::vector<string>& files, char*hi, string& wrd);
    void maintenance(std::vector<string>& files, char*hi, string& wrd);
    void interactive(std::vector<string>& files, char*hi, string& wrd);
private:
    char mode;
};

#endif // OUTPUT_H
