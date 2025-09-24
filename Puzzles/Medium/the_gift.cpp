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
    int c;
    cin >> c; cin.ignore();
    vector<int> budgets(n);
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b; cin.ignore();
        budgets[i] = b;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    sort(budgets.begin(), budgets.end());
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        int needSum = c / (n - i);
        if (budgets[i] < needSum) {
            c -= budgets[i];
            res.push_back(budgets[i]);
        }
        else {
            c -= needSum;
            res.push_back(needSum);
        }
    }
    sort(res.begin(), res.end());
    if (c > 0)
        cout << "IMPOSSIBLE";
    else 
        for (int x : res)
            cout << x << '\n';
    cout << endl;

    return 0;
}
