#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; cin.ignore();
    int q; 
    cin >> q; cin.ignore();
    unordered_map<string, string> mimeMap;
    mimeMap.reserve(n*2);
    mimeMap.max_load_factor(0.7);
    for (int i = 0; i < n; i++) {
        string ext;
        string mt;
        cin >> ext >> mt; cin.ignore();
        for (char &c : ext)
            c = tolower(c);
        mimeMap[move(ext)] = move(mt);
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    string filename;
    filename.reserve(256); 

    for (int i = 0; i < q; ++i) {
        cin >> filename;
        int dotPos = filename.rfind('.');
        if (dotPos == string::npos || dotPos + 1 >= filename.size()) {
            cout << "UNKNOWN\n";
            continue;
        }
        string ext = filename.substr(dotPos + 1);
        for (char &c : ext)
            c = tolower(c);
        auto it = mimeMap.find(ext);
        if (it != mimeMap.end())
            cout << it->second << '\n';
        else
            cout << "UNKNOWN\n";
    }
    cout << endl;
    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
}
