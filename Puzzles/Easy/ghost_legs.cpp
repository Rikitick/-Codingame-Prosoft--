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
    vector<string> diagram(h);
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        diagram[i] = line;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    int numLines = 0;
    vector<int> linePositions;
  
    for (int i = 0; i < w; i++) {
        if (diagram[0][i] != ' ') {
            linePositions.push_back(i);
            numLines++;
        }
    }

    for (int startCol = 0; startCol < numLines; startCol++) {
        int currentPos = linePositions[startCol];
        int currentLine = startCol;
        
        for (int row = 1; row < h - 1; row++) {
            if (currentPos > 0 && diagram[row][currentPos - 1] == '-') {
                currentLine--;
                currentPos = linePositions[currentLine];
            }
            else if (currentPos < w - 1 && diagram[row][currentPos + 1] == '-') {
                currentLine++;
                currentPos = linePositions[currentLine];
            }
        }
        
        cout << diagram[0][linePositions[startCol]] 
             << diagram[h-1][linePositions[currentLine]] << endl;
    }
}
