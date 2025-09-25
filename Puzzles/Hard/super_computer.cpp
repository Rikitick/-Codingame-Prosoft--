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
    vector<pair<int, int>> calculations(n);
    for (int i = 0; i < n; i++) {
        int j;
        int d;
        cin >> j >> d; cin.ignore();
        calculations[i] = {j, j+d-1};
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    sort(
        calculations.begin(),
        calculations.end(),
        [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    );

    // for (auto x : calculations)
    //     cout << x.first << ' ' << x.second << '\n';

    int timeLastCalculate = 0;
    int cntCalculate = 0;
    for (auto calculate : calculations) {
        if (calculate.first > timeLastCalculate) {
            cntCalculate++;
            timeLastCalculate = calculate.second;
        }
    }

    cout << cntCalculate << endl;

    return 0;
}
