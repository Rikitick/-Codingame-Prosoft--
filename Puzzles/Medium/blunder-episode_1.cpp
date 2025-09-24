#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem Blunderment.
 **/

enum Direction { SOUTH, EAST, NORTH, WEST };
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const string dirStr[] = {"SOUTH", "EAST", "NORTH", "WEST"};

struct Blunder {
    int x, y;
    Direction dir;
    bool breaker;
    bool inverted;
    
    Blunder(int x, int y, Direction d, bool b, bool i) : x(x), y(y), dir(d), breaker(b), inverted(i) {}
    
    bool operator<(const Blunder& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        if (dir != other.dir) return dir < other.dir;
        if (breaker != other.breaker) return breaker < other.breaker;
        return inverted < other.inverted;
    }
};

int main() {
    int l;
    int c;
    cin >> l >> c; cin.ignore();
    
    vector<string> grid(l);
    int startX = -1, startY = -1;
    vector<pair<int, int>> teleports;
    
    for (int i = 0; i < l; i++) {
        getline(cin, grid[i]);
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '@') {
                startX = i;
                startY = j;
            } else if (grid[i][j] == 'T') {
                teleports.push_back({i, j});
            }
        }
    }
    
    Blunder cur(startX, startY, SOUTH, false, false);
    set<Blunder> visited;
    vector<string> path;
    vector<string> tempGrid = grid;
    
    while (true) {
        if (tempGrid[cur.x][cur.y] == '$') {
            for (const string& move : path) {
                cout << move << endl;
            }
            return 0;
        }
        
        Blunder BlunderWithoutPath(cur.x, cur.y, cur.dir, cur.breaker, cur.inverted);
        if (visited.find(BlunderWithoutPath) != visited.end()) {
            cout << "LOOP" << endl;
            return 0;
        }
        visited.insert(BlunderWithoutPath);
        
        int nx = cur.x + dx[cur.dir];
        int ny = cur.y + dy[cur.dir];
        char nextChar = tempGrid[nx][ny];
        
        if (nextChar == '#' || (nextChar == 'X' && !cur.breaker)) {
            vector<Direction> priorities;
            if (cur.inverted) {
                priorities = {WEST, NORTH, EAST, SOUTH};
            } else {
                priorities = {SOUTH, EAST, NORTH, WEST};
            }
            
            bool moved = false;
            for (Direction d : priorities) {
                int nnx = cur.x + dx[d];
                int nny = cur.y + dy[d];
                char nnextChar = tempGrid[nnx][nny];
                if (nnextChar != '#' && (nnextChar != 'X' || cur.breaker)) {
                    cur.dir = d;
                    nx = nnx;
                    ny = nny;
                    moved = true;
                    break;
                }
            }
            if (!moved) {
                cout << "LOOP" << endl;
                return 0;
            }
        }
        
        path.push_back(dirStr[cur.dir]);
        cur.x = nx;
        cur.y = ny;
        
        nextChar = tempGrid[cur.x][cur.y];
        if (nextChar == 'S') {
            cur.dir = SOUTH;
        } else if (nextChar == 'E') {
            cur.dir = EAST;
        } else if (nextChar == 'N') {
            cur.dir = NORTH;
        } else if (nextChar == 'W') {
            cur.dir = WEST;
        } else if (nextChar == 'I') {
            cur.inverted = !cur.inverted;
        } else if (nextChar == 'B') {
            cur.breaker = !cur.breaker;
        } else if (nextChar == 'T') {
            for (const auto& t : teleports) {
                if (t.first != cur.x || t.second != cur.y) {
                    cur.x = t.first;
                    cur.y = t.second;
                    break;
                }
            }
        } else if (nextChar == 'X' && cur.breaker) {
            tempGrid[cur.x][cur.y] = ' ';
            visited.clear(); 
        }
    }

    return 0;
}
