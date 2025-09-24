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

int main() {
    int l;
    int c;
    int n;
    cin >> l >> c >> n; cin.ignore();
    vector<int> groups(n);
    for (int i = 0; i < n; i++) {
        int pi;
        cin >> pi; cin.ignore();
        groups[i] = pi;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    vector<long long> earnings(n);
    vector<int> next_start(n);     
    
    for (int start = 0; start < n; start++) {
        int cur = start;
        long long earn = 0;
        int capacity = l;
        int count = 0;
        while (count < n && groups[cur] <= capacity) {
            earn += groups[cur];
            capacity -= groups[cur];
            cur = (cur + 1) % n;
            count++;
        }
        earnings[start] = earn;
        next_start[start] = cur;
    }
    
    long long total = 0;
    int cur_start = 0;
    map<int, int> visited;
    int ride = 0;
    while (ride < c) {
        if (visited.find(cur_start) != visited.end()) {
            int prev_ride = visited[cur_start];
            int cycle_length = ride - prev_ride;
            long long cycle_earn = 0;
            for (int i = prev_ride; i < ride; i++) {
                cycle_earn += earnings[cur_start];
                cur_start = next_start[cur_start];
            }
            int cycles_left = (c - ride) / cycle_length;
            total += cycles_left * cycle_earn;
            ride += cycles_left * cycle_length;
            if (ride >= c) break;
        }
        visited[cur_start] = ride;
        total += earnings[cur_start];
        cur_start = next_start[cur_start];
        ride++;
    }
    
    cout << total << endl;
  
    return 0;
}
