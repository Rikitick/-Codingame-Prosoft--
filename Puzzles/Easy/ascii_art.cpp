#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int l;
    cin >> l; cin.ignore();
    int h;
    cin >> h; cin.ignore();
    string t;
    getline(cin, t);
    vector<string> asciiArt(h);
    for (int i = 0; i < h; i++) {
        string row;
        getline(cin, row);
        asciiArt[i] = row;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    for (int i = 0; i < h; i++) {
        string outputLine = "";
        for (char c : t) {
            c = toupper(c);
            int pos;
            if (c >= 'A' && c <= 'Z') {
                pos = c - 'A';
            } else {
                pos = 26; 
            }
            
            int start = pos * l;
            outputLine += asciiArt[i].substr(start, l);
        }
        cout << outputLine << endl;
    }
}
