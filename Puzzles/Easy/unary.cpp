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
    string message;
    getline(cin, message);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    string bin = "";
    for (char c : message) {
        for (int i = 6; i >= 0; i--) {
            bin += ((c >> i) & 1) ? '1' : '0';
        }
    }
    
    string res = "";
    int i = 0;
    int n = bin.size();
    
    while (i < n) {
        char cur = bin[i];
        int cnt = 1;
        while (i + cnt < n && bin[i + cnt] == cur) {
            cnt++;
        }
        
        if (cur == '1') {
            res += "0 ";
        } else {
            res += "00 ";
        }
        
        for (int j = 0; j < cnt; j++) {
            res += "0";
        }
        
        i += cnt;
        if (i < n) {
            res += " ";
        }
    }
    
    cout << res << endl;
}
