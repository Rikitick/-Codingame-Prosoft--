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
    string result;
    
    while (ss >> chunk) {
        if (chunk == "nl") {
            result += '\n';
            continue;
        }
        
        int num_end = 0;
        while (num_end < chunk.size() && isdigit(chunk[num_end])) {
            num_end++;
        }
        
        int count = stoi(chunk.substr(0, num_end));

        string rest = chunk.substr(num_end);
        
        char ch;
        if (rest.empty()) {
            ch = chunk.back();
            count = stoi(chunk.substr(0, chunk.size() - 1));
        }
        else if (rest == "sp")
            ch = ' ';
        else if (rest == "bS")
            ch = '\\';
        else if (rest == "sQ")
            ch = '\'';
        else
            ch = rest[0];
        
        result += string(count, ch);
    }
    
    cout << result << endl;
}
