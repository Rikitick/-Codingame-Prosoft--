#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int w; // number of columns.
    int h; // number of rows.
    cin >> w >> h; cin.ignore();
    int rooms[h][w] = {{0}};
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; ++j)
            cin >> rooms[i][j];
    }
    int ex; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> ex; cin.ignore();

    // game loop
    while (1) {
        int xi;
        int yi;
        string pos;
        cin >> xi >> yi >> pos; cin.ignore();

        // cout << h << ' ' << w << " || ";
        // for (int i = 0; i < h; ++i) {
        //     for (int j = 0; j < w; ++j)
        //         cout << rooms[i][j] << ' ';
        //     cout << " | ";
        // }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        if (rooms[yi][xi] == 10 || (rooms[yi][xi] == 4 && pos == "TOP"))
            cout << xi-1 << ' ' << yi << endl;
        else if (rooms[yi][xi] == 11 || (rooms[yi][xi] == 5 && pos == "TOP"))
            cout << xi+1 << ' ' << yi << endl;
        else if (rooms[yi][xi] == 2 || rooms[yi][xi] == 6) {
            if (pos == "RIGHT")
                cout << xi-1 << ' ' << yi << endl;
            else if (pos == "LEFT")
                cout << xi+1 << ' ' << yi << endl;
            else {
                int blockRoomsOnRight[] = {0, 3, 4, 7, 10, 11, 12};
                int blockRoomsOnLeft[] = {0, 3, 5, 9, 10, 11, 13};
                string direction = "";
                for (int t : blockRoomsOnRight) {
                    if (rooms[yi][xi] == t) {
                        direction = "LEFT";
                        break;
                    }
                }
                if (direction == "LEFT")
                    cout << xi-1 << ' ' << yi << endl;
                else 
                    cout << xi+1 << ' ' << yi << endl;
            }
        }
        else
            cout << xi << ' ' << yi+1 << endl;  

        // One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
        //cout << "0 0" << endl;
    }
    return 0;
}
