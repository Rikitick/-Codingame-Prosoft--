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
    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int elevation;
            cin >> elevation; cin.ignore();
            map[i][j] = elevation;
        }
    }

    int start = n / 2;
    vector<vector<bool>> visited(n, vector<bool>(n));
    vector<pair<int, int>> q;
    q.push_back({start, start});
    visited[start][start] = true;
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    bool found = false;
    while (!q.empty()) {
        pair<int, int> curPos = q.back();
        q.pop_back();
        int x = curPos.first;
        int y = curPos.second;
        
        if (x == 0 || x == n-1 || y == 0 || y == n-1) {
            found = true;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                if (abs(map[x][y] - map[nx][ny]) <= 1) {
                    visited[nx][ny] = true;
                    q.push_back({nx, ny});
                }
            }
        }
    }
    
    if (found) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}
