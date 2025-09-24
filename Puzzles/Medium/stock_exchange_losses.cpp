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
    int stockVals[n] = {0};
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        stockVals[i] = v;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    long long maxDif = 0, maxV = 0;
    for (int i = 0; i < n; ++i) {
        if (stockVals[i] < maxV)
            maxDif = min(maxDif, stockVals[i] - maxV);
        else 
            maxV = stockVals[i];
    }
    
    cout << maxDif << endl;

    return 0;
}
