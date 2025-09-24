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
    string operation, rotors[3];
    getline(cin, operation);
    int pseudo_random_number;
    cin >> pseudo_random_number; cin.ignore();
    for (int i = 0; i < 3; i++) {
        string rotor;
        getline(cin, rotor);
        rotors[i] = rotor;
    }
    string message;
    getline(cin, message);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    if (operation == "ENCODE") {
        for (int i = 0; i < message.size(); i++) 
            message[i] = 'A' + (message[i] - 'A' + pseudo_random_number + i) % 26;
        
        for (int r = 0; r < 3; r++)
            for (char &c : message)
                c = rotors[r][c - 'A'];
    } 
    else {
        for (int r = 2; r >= 0; r--)
            for (char &c : message)
                for (int i = 0; i < 26; i++)
                    if (rotors[r][i] == c) {
                        c = 'A' + i;
                        break;
                    }
        
        for (int i = 0; i < message.size(); i++) {
            int pos = (message[i] - 'A' - pseudo_random_number - i) % 26;
            if (pos < 0) pos += 26;
            message[i] = 'A' + pos;
        }
    }
    
    cout << message << endl;

    return 0;
}
