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
    vector<int> horses(n);
    for (int i = 0; i < n; i++) {
        int pi;
        cin >> pi; cin.ignore();
        horses[i] = pi;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    sort(horses.begin(), horses.end());

    int minDif = 10000001;
    for (int i = 1; i < n; ++i) {
        minDif = min(minDif, horses[i] - horses[i-1]);
    }

    cout << minDif << endl;
}
