#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
string extend(string s, string t) {
    string prevS = s;
    for (int i = 0; i < s.length(); ++i) {
        if (s.substr(i) == t.substr(0, s.length() - i)) {
            s += t.substr(s.length() - i);
            break;
        }
    }
    if (prevS == s && s.find(t) == string::npos)
        return s + t;
    return s;
}


int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<string> sequences(n);
    for (int i = 0; i < n; i++) {
        string subseq;
        cin >> subseq; cin.ignore();
        sequences[i] = subseq;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    sort(sequences.begin(), sequences.end());

    string minSubSeq(60, '_');
    do {
        string res = "";
        for (string s : sequences)
            res = extend(res, s);
        if (res.length() < minSubSeq.length())
            minSubSeq = res;
    } while (next_permutation(sequences.begin(), sequences.end()));

    cout << minSubSeq.length() << endl;
    return 0;
}
