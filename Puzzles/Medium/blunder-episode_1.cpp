#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

enum Direction { SOUTH, EAST, NORTH, WEST };
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const string dirStr[] = {"SOUTH", "EAST", "NORTH", "WEST"};

struct State {
    int x, y;
    Direction dir;
    bool breaker;
    bool inverted;
    
    State(int x, int y, Direction d, bool b, bool i) : x(x), y(y), dir(d), breaker(b), inverted(i) {}
    
    bool operator<(const State& other) const {
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
    vector<pair<int, int>> teleporters;
    
    for (int i = 0; i < l; i++) {
        getline(cin, grid[i]);
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '@') {
                startX = i;
                startY = j;
            } else if (grid[i][j] == 'T') {
                teleporters.push_back({i, j});
            }
        }
    }
    
    State current(startX, startY, SOUTH, false, false);
    set<State> visited;
    vector<string> path;
    vector<string> tempGrid = grid;
    
    while (true) {
        if (tempGrid[current.x][current.y] == '$') {
            for (const string& move : path) {
                cout << move << endl;
            }
            return 0;
        }
        
        State stateWithoutPath(current.x, current.y, current.dir, current.breaker, current.inverted);
        if (visited.find(stateWithoutPath) != visited.end()) {
            cout << "LOOP" << endl;
            return 0;
        }
        visited.insert(stateWithoutPath);
        
        int nx = current.x + dx[current.dir];
        int ny = current.y + dy[current.dir];
        char nextChar = tempGrid[nx][ny];
        
        if (nextChar == '#' || (nextChar == 'X' && !current.breaker)) {
            vector<Direction> priorities;
            if (current.inverted) {
                priorities = {WEST, NORTH, EAST, SOUTH};
            } else {
                priorities = {SOUTH, EAST, NORTH, WEST};
            }
            
            bool moved = false;
            for (Direction d : priorities) {
                int nnx = current.x + dx[d];
                int nny = current.y + dy[d];
                char nnextChar = tempGrid[nnx][nny];
                if (nnextChar != '#' && (nnextChar != 'X' || current.breaker)) {
                    current.dir = d;
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
        
        path.push_back(dirStr[current.dir]);
        current.x = nx;
        current.y = ny;
        
        nextChar = tempGrid[current.x][current.y];
        if (nextChar == 'S') {
            current.dir = SOUTH;
        } else if (nextChar == 'E') {
            current.dir = EAST;
        } else if (nextChar == 'N') {
            current.dir = NORTH;
        } else if (nextChar == 'W') {
            current.dir = WEST;
        } else if (nextChar == 'I') {
            current.inverted = !current.inverted;
        } else if (nextChar == 'B') {
            current.breaker = !current.breaker;
        } else if (nextChar == 'T') {
            for (const auto& t : teleporters) {
                if (t.first != current.x || t.second != current.y) {
                    current.x = t.first;
                    current.y = t.second;
                    break;
                }
            }
        } else if (nextChar == 'X' && current.breaker) {
            tempGrid[current.x][current.y] = ' ';
            visited.clear(); 
        }
    }

    return 0;
}
