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
    int n;
    cin >> n; cin.ignore();
    int res = 5527;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t; cin.ignore();
        if (abs(res) > abs(t) || abs(res) == abs(t) && t > res)
            res = t;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << res % 5527 << endl;
}
