#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

struct Cell {
    string operation;
    string arg1;
    string arg2;
    int value;
    bool calculated;
    
    Cell() : calculated(false) {}
};

bool isReference(const string& str) {
    return str[0] == '$';
}

int getReferenceIndex(const string& ref) {
    return stoi(ref.substr(1));
}

int getArgumentValue(const string& arg, const vector<Cell>& cells) {
    if (isReference(arg)) {
        int refIndex = getReferenceIndex(arg);
        return cells[refIndex].value;
    } 
    else
        return stoi(arg);
}

int calculateCell(int index, vector<Cell>& cells) {
    Cell& cell = cells[index];
    
    if (cell.calculated)
        return cell.value;
    
    int val1, val2;
    
    if (isReference(cell.arg1)) {
        int refIndex = getReferenceIndex(cell.arg1);
        val1 = calculateCell(refIndex, cells);
    }
    else
        val1 = stoi(cell.arg1);
    
    if (cell.arg2 != "_") {
        if (isReference(cell.arg2)) {
            int refIndex = getReferenceIndex(cell.arg2);
            val2 = calculateCell(refIndex, cells);
        }
        else
            val2 = stoi(cell.arg2);
    }
    else
        val2 = 0;
    
    // Выполняем операцию
    if (cell.operation == "VALUE")
        cell.value = val1;
    else if (cell.operation == "ADD")
        cell.value = val1 + val2;
    else if (cell.operation == "SUB")
        cell.value = val1 - val2;
    else if (cell.operation == "MULT")
        cell.value = val1 * val2;
    
    cell.calculated = true;
    return cell.value;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<Cell> cells(n);
    for (int i = 0; i < n; i++) {
        string operation;
        string arg_1;
        string arg_2;
        cin >> operation >> arg_1 >> arg_2; cin.ignore();
        cells[i].operation = operation;
        cells[i].arg1 = arg_1;
        cells[i].arg2 = arg_2;
    }
    for (int i = 0; i < n; i++) {

        // Write an answer using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        calculateCell(i, cells);
    }

    for (int i = 0; i < n; i++) {
        cout << cells[i].value << endl;
    }
}
