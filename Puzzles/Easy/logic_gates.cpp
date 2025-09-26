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

        string result;
        string firstSignal = signals[input_name_1];
        string secondSignal = signals[input_name_2];
        
        for (int j = 0; j < firstSignal.length(); j++) {
            bool a = (firstSignal[j] == '-'), b = (secondSignal[j] == '-'), res;
            
            if (type == "AND")
                res = a && b;
            else if (type == "OR")
                res = a || b;
            else if (type == "XOR")
                res = a != b;
            else if (type == "NAND")
                res = !(a && b);
            else if (type == "NOR")
                res = !(a || b);
            else if (type == "NXOR")
                res = a == b;
            
            result += res ? '-' : '_';
        }
        
        cout << output_name << " " << result << endl;
    }
}
