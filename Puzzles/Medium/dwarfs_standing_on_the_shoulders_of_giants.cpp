#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int maxLen(map<int, set<int>> graph, int ind, int cnt = 1) {
    if (graph[ind].size() == 0)
        return cnt;
    int maxlen = 1;
    for (int n : graph[ind])
        maxlen = max(maxLen(graph, n, cnt+1), maxlen);
    return maxlen;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    map<int, set<int>> graph;
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();
        graph[x].insert(y);  
    }

    int maxlen = 0;
    for (auto x : graph) {
        maxlen = max(maxlen, maxLen(graph, x.first));
    }
    cout << maxlen << endl;

    return 0;
}
