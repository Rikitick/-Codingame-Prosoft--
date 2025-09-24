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
    int r;
    cin >> r; cin.ignore();
    int l;
    cin >> l; cin.ignore();

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    string res = "";
    res.push_back('0' + r);

    for (int i = 1; i < l; ++i) {
        string temp = "";
        char curCymb = res.front();
        int cnt = 0;
        for (char c : res) {
            if (curCymb == c)
                cnt++;
            else {
                temp.push_back('0' + cnt);
                temp.push_back(curCymb);
                curCymb = c;
                cnt = 1;
            }
        }
        temp.push_back('0' + cnt);
        temp.push_back(curCymb);
        res = temp;
    }

    for (int i = 0; i < res.length(); ++i) {
        cout << res[i] - '0';
        if (i != res.length()-1)
            cout << ' ';
    }
    cout << endl;

    return 0;
}
