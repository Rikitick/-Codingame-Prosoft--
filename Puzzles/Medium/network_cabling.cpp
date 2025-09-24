#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<long long> cordX;
    vector<long long> cordY;
    long long minX = 10000000000000, maxX = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        long long y;
        cin >> x >> y; cin.ignore();
        cordX.push_back(x);
        cordY.push_back(y);
        minX = min(minX, x);
        maxX = max(maxX, x);
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    sort(cordY.begin(), cordY.end());
    
    long long medianY = cordY[n/2];
    long long len = maxX - minX;

    for (int y : cordY)
        len += abs(medianY - y);
    
    cout << len << endl;

    return 0;
}
