#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void getPath(vector<string>* maze, vector<string>* mapD, int r, int c, int kr, int kc, vector<string>* res, char trigger) {
	int mapRes[r][c];
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			mapRes[i][j] = -1;  
		
	vector<pair<int, int>> wave;
	vector<pair<int, int>> oldWave;

	oldWave.push_back(pair<int, int>(kr, kc));
	int nstep = 0;  
	int nx, ny;
	mapRes[kr][kc] = nstep;  
	const int dx[] = {0, 1, 0, -1}; 
	const int dy[] = {-1, 0, 1, 0}; 

	while (oldWave.size() > 0) {
		++nstep;  
		wave.clear(); 
		for (vector<pair<int, int>>::iterator i = oldWave.begin(); i != oldWave.end(); ++i) {
			for (int d = 0; d < 4; ++d) {
				nx = i->first + dx[d];  
				ny = i->second + dy[d];  
        
				if ((*maze)[nx][ny] == '.' && mapRes[nx][ny] == -1) {
					wave.push_back(pair<int, int>(nx, ny));  
					mapRes[nx][ny] = nstep;  
				}
				if ((*maze)[nx][ny] == trigger && (*mapD)[nx][ny] == '0') {
					mapRes[nx][ny] = nstep;  
					goto done; 
				}		
			}
		}
		oldWave = wave;  
	}

    done:
        int rx = nx;
        int ry = ny;
        int cnt = 0; 
		while (mapRes[rx][ry] != 0 && cnt < 100) {
            for (int d = 0; d < 4; ++d) {
                if (mapRes[rx][ry] - 1 == mapRes[rx][ry-1]) {
                    rx = rx;
                    ry = ry-1;
                    res->push_back("LEFT");  
                    break;
                }
                if (mapRes[rx][ry] - 1 == mapRes[rx-1][ry]) {
                    rx = rx-1;
                    ry = ry;
                    res->push_back("UP"); 
                    break;
                }
                if (mapRes[rx][ry] - 1 == mapRes[rx][ry+1]) {
                    rx = rx;
                    ry = ry+1;
                    res->push_back("RIGHT"); 
                    break;
                }
                if (mapRes[rx][ry] - 1 == mapRes[rx+1][ry]) {
                    rx = rx+1;
                    ry = ry;
                    res->push_back("DOWN");  
                    break;
                }
            }
            cnt++;  
        }
        if (cnt == 100) {
            (*mapD)[nx][ny] = '0'; 
        }
}

string rev(string s) {
    if (s == "RIGHT")
        return "LEFT";
    if (s == "LEFT")
        return "RIGHT";
    if (s == "UP")
        return "DOWN";
    if (s == "DOWN")
        return "UP";
    else 
        return "ERR";  
}

int main()
{
    vector<string> res(0); 
    
    bool comeBack = false;  
    int startx; 
    int starty;  
    int r;  
    int c; 
    int a;  
    cin >> r >> c >> a; cin.ignore();  
    vector<string> mapD; 
    for (int i = 0; i < r; ++i) {
        mapD.push_back("");
        for (int j = 0; j < c; ++j) {
            mapD[mapD.size()-1] += '0';  
        }
    }

    while (1) {
        vector<string> maze; 
        string move;  
        int cnt = 0;  
        int kr;  
        int kc; 
        cin >> kr >> kc; cin.ignore(); 
        for (int i = 0; i < r; i++) {
            string row;  
            cin >> row; cin.ignore();
            maze.push_back(row);
        }
        
        if (maze[kr][kc] == 'T') {
            startx = kr;
            starty = kc;
        }
        maze[startx][starty] = '.';  
        mapD[kr][kc] = '1';  
        
        if (!res.size()) {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j)
                    if (maze[i][j] == '.' && mapD[i][j] == '0') {  
                        getPath(&maze, &mapD, r, c, kr, kc, &res, '.');  
                        break;
                    }
                if (res.size())
                    break;
            }
            if (!res.size() && !comeBack) {
                getPath(&maze, &mapD, r, c, kr, kc, &res, 'C');  
                comeBack = true;  
            }
            if (!res.size() && maze[kr][kc] == 'C') {
                mapD[startx][starty] = '0';  
                maze[startx][starty] = 'T';  
                getPath(&maze, &mapD, r, c, kr, kc, &res, 'T');  
            }
        }

        move = rev(res[res.size()-1]);
        res.pop_back();  
        cout << move << endl; 
    }
  
    return 0;
}
