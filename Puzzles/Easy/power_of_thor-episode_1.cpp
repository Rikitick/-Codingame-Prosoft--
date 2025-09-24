#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int light_x; 
    int light_y; 
    int initial_tx; 
    int initial_ty; 
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();

    while (1) {
        int remaining_turns; 
        cin >> remaining_turns; cin.ignore();

        if (initial_tx < light_x && initial_ty < light_y) {
            cout << "SE" << endl; 
            initial_tx++; 
            initial_ty++; 
        }
        else if (initial_tx == light_x && initial_ty < light_y) {
            cout << "S" << endl; 
            initial_ty++;
        }
        else if (initial_tx < light_x && initial_ty == light_y) {
            cout << "E" << endl;
            initial_tx++;
        }
        else if (initial_tx > light_x && initial_ty > light_y) {
            cout << "NW" << endl; 
            initial_tx--; 
            initial_ty--; 
        }
        else if (initial_tx == light_x && initial_ty > light_y) {
            cout << "N" << endl; 
            initial_ty--; 
        }
        else if (initial_tx > light_x && initial_ty == light_y) {
            cout << "W" << endl; 
            initial_tx--; 
        }
        else if (initial_tx < light_x && initial_ty > light_y) {
            cout << "NE" << endl; 
            initial_tx++; 
            initial_ty--; 
        }
        else if (initial_tx > light_x && initial_ty < light_y) {
            cout << "SW" << endl; 
            initial_tx--; 
            initial_ty++; 
        }
    }

    return 0;
}
