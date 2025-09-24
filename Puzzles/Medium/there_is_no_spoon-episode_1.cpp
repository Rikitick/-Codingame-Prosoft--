#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{
    int width; 
    cin >> width; 
    cin.ignore(); 

    int height; 
    cin >> height; 
    cin.ignore(); 
    
    char lines[height][width];

    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); 
        for (int j = 0; j < width; ++j) {
            lines[i][j] = line[j];
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int rx = -1, ry = -1, dx = -1, dy = -1;
            
            if (lines[i][j] == '.') {
                continue; 
            }
            
            for (int right = j+1; right < width; ++right) {
                if (lines[i][right] == '0') { 
                    rx = right; 
                    ry = i; 
                    break; 
                }
            }
            
            for (int down = i+1; down < height; ++down) {
                if (lines[down][j] == '0') { 
                    dx = j; 
                    dy = down; 
                    break; 
                }
            }
            cout << j << ' ' << i << ' ' << rx << ' ' << ry << ' ' << dx << ' ' << dy << endl;
        }
    }
    return 0;
}
