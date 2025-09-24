#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string t;
    getline(cin, t);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    stringstream ss(t);
    string chunk;
    string res;
    
    while (ss >> chunk) {
        if (chunk == "nl") {
            res += '\n';
            continue;
        }
        
        int numEnd = 0;
        while (numEnd < chunk.size() && isdigit(chunk[numEnd])) {
            numEnd++;
        }
        
        int cnt = stoi(chunk.substr(0, numEnd));

        string rest = chunk.substr(numEnd);
        
        char ch;
        if (rest.empty()) {
            ch = chunk.back();
            cnt = stoi(chunk.substr(0, chunk.size() - 1));
        }
        else if (rest == "sp")
            ch = ' ';
        else if (rest == "bS")
            ch = '\\';
        else if (rest == "sQ")
            ch = '\'';
        else
            ch = rest[0];
        
        res += string(cnt, ch);
    }
    
    cout << res << endl;

    return 0;
}
