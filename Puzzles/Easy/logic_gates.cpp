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
    int m;
    cin >> m; cin.ignore();
    unordered_map<string, string> signals;
    for (int i = 0; i < n; i++) {
        string input_name;
        string input_signal;
        cin >> input_name >> input_signal; cin.ignore();
        signals[input_name] = input_signal;
    }
    vector<vector<string>> outputs;
    for (int i = 0; i < m; i++) {
        string output_name;
        string type;
        string input_name_1;
        string input_name_2;
        cin >> output_name >> type >> input_name_1 >> input_name_2; cin.ignore();
        outputs.push_back({output_name, type, input_name_1, input_name_2});
    }
    for (int i = 0; i < m; i++) {

        // Write an answer using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        vector<string> quary = outputs[i];
        string s1 = signals[quary[2]];
        string s2 = signals[quary[3]];
        string gate = quary[1];
        string result;
        
        for (int i = 0; i < s1.length(); i++) {
            bool a = (s1[i] == '-'), b = (s2[i] == '-'), res;
            
            if (gate == "AND")
                res = a && b;
            else if (gate == "OR")
                res = a || b;
            else if (gate == "XOR")
                res = a != b;
            else if (gate == "NAND")
                res = !(a && b);
            else if (gate == "NOR")
                res = !(a || b);
            else if (gate == "NXOR")
                res = a == b;
            
            result += res ? '-' : '_';
        }
        
        cout << quary[0] << " " << result << endl;
    }
}
