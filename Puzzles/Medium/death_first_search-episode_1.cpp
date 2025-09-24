#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    map<int, vector<int>> graph;
    set<int> shluzSet;
    vector<int> shluzVec;
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();
    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2; cin.ignore();
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
        shluzSet.insert(ei);
        shluzVec.push_back(ei);
    }

    // game loop
    while (1) {
        bool print = false;
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();

        for (int x : graph[si]) {
            if (shluzSet.find(x) != shluzSet.end()) {
                cout << si << ' ' << x << endl;
                print = true;
                break;
            }    
        }
        if (print)
            continue;

        for (int x : shluzVec) {
            if (graph[x].size() > 0) {
                cout << x << ' ' << graph[x].back() << endl;
                graph[x].pop_back();
                break;
            }
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // Example: 0 1 are the indices of the nodes you wish to sever the link between
       
    }

    return 0;
}
