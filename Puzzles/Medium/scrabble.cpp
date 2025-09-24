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
    int n;
    cin >> n; cin.ignore();
    string words[n];
    for (int i = 0; i < n; i++) {
        string w;
        getline(cin, w);
        words[i] = w;
    }
    
    map<char, int> letters = {{' ', 0}};
    map<set<char>, int> points = {
        {{'e', 'a', 'i', 'o', 'n', 'r', 't', 'l', 's', 'u'}, 1},
        {{'d', 'g'}, 2},
        {{'b', 'c', 'm', 'p'}, 3},
        {{'f', 'h', 'v', 'w', 'y'}, 4},
        {{'k'}, 5},
        {{'j', 'x'}, 8},
        {{'q', 'z'}, 10},
    };
    string letter;
    cin >> letter;
    for (char x : letter)
        letters[x]++;

    pair<string, int> maxWord = {" ", 0};
    for (string s : words) {
        bool found = true;
        int curCnt = 0;
        map<char, int> t = letters;
        for (char l : s) {
            if (t[l] == 0) {
                found = false;
                break;
            }
            else {
                t[l]--;
                for (pair<set<char>, int> p : points) {
                    if (p.first.find(l) != p.first.end()) {
                        curCnt += p.second;
                        break;
                    }
                }
            }
        }
        if (found) {
            if (curCnt > maxWord.second) {
                maxWord.first = s;
                maxWord.second = curCnt;
            }
        }
    }
    cout << maxWord.first << endl;
  
    return 0;
}
