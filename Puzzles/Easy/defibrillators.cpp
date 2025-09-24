#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string lonS;
    cin >> lonS; cin.ignore();
    string latS;
    cin >> latS; cin.ignore();
    replace(lonS.begin(), lonS.end(), ',', '.');
    replace(latS.begin(), latS.end(), ',', '.');
    long double lon = stod(lonS), lat = stod(latS);
    int n;
    cin >> n; cin.ignore();
    vector<pair<string, pair<long double, long double>>> defibrillators;
    for (int i = 0; i < n; i++) {
        string num, name, addres, contact, loni, lati;
        getline(cin, num, ';');
        getline(cin, name, ';');
        getline(cin, addres, ';');
        getline(cin, contact, ';');
        getline(cin, loni, ';');
        getline(cin, lati);
        replace(loni.begin(), loni.end(), ',', '.');
        replace(lati.begin(), lati.end(), ',', '.');

        defibrillators.push_back({name, {stod(loni), stod(lati)}});
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    long double minDistance = 100000000000;
    string res;
    for (pair<string, pair<long double, long double>> difibr : defibrillators) {
        long double x = (abs(difibr.second.first - lon) * cos((difibr.second.second + lat) / 2.0));
        long double y = abs(difibr.second.second - lat);
        long double distance = sqrt(x * x + y * y) * 6371;
        if (distance < minDistance) {
            minDistance = distance;
            res = difibr.first;
        }
    }
    cout << res << endl;

    return 0;
}
