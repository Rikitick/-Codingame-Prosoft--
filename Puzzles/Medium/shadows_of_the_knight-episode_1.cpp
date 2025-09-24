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
    int w;
    int h;
    cin >> w >> h; cin.ignore();
  
    int n;
    cin >> n; cin.ignore();
 
    int x0;
    int y0;
    cin >> x0 >> y0; cin.ignore();

    int xlr = w;
    int xll = 0;
    int yld = h;
    int ylu = 0;
  
    while (1) {
        string bomb_dir;
        
        cin >> bomb_dir; cin.ignore();

        for (int i = 0; i < bomb_dir.length(); ++i) {
            if (bomb_dir[i] == 'U') {
                yld = y0; 
                y0 = (y0 + ylu) / 2; 
            }
            if (bomb_dir[i] == 'D') {
                ylu = y0;
                y0 = (y0 + yld) / 2; 
            }
            if (bomb_dir[i] == 'R') {
                xll = x0; 
                x0 = (x0 + xlr) / 2;
            }
            if (bomb_dir[i] == 'L') {
                xlr = x0; 
                x0 = (x0 + xll) / 2; 
            }
        }
        cout << x0 << ' ' << y0 << endl;
    }

    return 0;
}
