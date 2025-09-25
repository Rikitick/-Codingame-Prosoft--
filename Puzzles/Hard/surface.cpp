#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int l;
    cin >> l; cin.ignore();
    int h;
    cin >> h; cin.ignore();
    vector<string> map;
    for (int i = 0; i < h; i++) {
        string row;
        getline(cin, row);
        map.push_back(row);
    }
    int n;
    cin >> n; cin.ignore();
    vector<pair<int, int>> quaries(n);
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();
        quaries[i] = {x, y};
    }
    
    for (int i = 0; i < n; i++) {
        int x = quaries[i].first, y = quaries[i].second;
        set<pair<int, int>> visited;

        vector<pair<int, int>> lakeCoords;
        lakeCoords.push_back({x, y});

        int cnt = 0;
        while (!lakeCoords.empty()) {
            pair<int, int> coord = lakeCoords.back();
            lakeCoords.pop_back();

            int xi = coord.first, yi = coord.second;
            if (xi < 0 || xi >= l || yi < 0 || yi >= h)
                continue;
            if (map[yi][xi] == 'O' && !visited.count({xi, yi})) {
                lakeCoords.push_back({xi+1, yi});
                lakeCoords.push_back({xi-1, yi});
                lakeCoords.push_back({xi, yi+1});
                lakeCoords.push_back({xi, yi-1});
                visited.insert({xi, yi});
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    cout << endl;

    return 0;
}
