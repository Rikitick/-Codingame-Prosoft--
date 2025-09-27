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

vector<string> inputNumDigits(int numLines, int h) {
    string curDigit = "";
    vector<string> numDigits;
    for (int i = 0; i < numLines; i++) {
        string digitLine;
        cin >> digitLine; cin.ignore();
        curDigit += digitLine;
        
        if ((i + 1) % h == 0) {
            numDigits.push_back(curDigit);
            curDigit.clear();
        }
    }
    return numDigits;
}

long long getNumVal(map<string, int>& digitsVal, vector<string> numDigits) {
    long long numVal = 0;
    long long p = 1;
    while (numDigits.size() > 0) {
        string digitRepres = numDigits.back();
        numDigits.pop_back();
        numVal += digitsVal[digitRepres] * p;
        p *= 20;
    }
    return numVal;
}

int main()
{
    int l;
    int h;
    cin >> l >> h; cin.ignore();
    
    string digits[20] = {""};
    map<string, int> digitsVal;
    
    for (int i = 0; i < h; i++) {
        string numeral;
        cin >> numeral; cin.ignore();
        
        for (int j = 0; j < 20 * h; j++) {
            int digitInd = j / h;
            digits[digitInd].push_back(numeral[j]);
        }
    }
    
    for (int i = 0; i < 20; i++) {
        digitsVal[digits[i]] = i;
    }

    int firstNumLines;
    cin >> firstNumLines; cin.ignore();
    vector<string> firstNumDigits = inputNumDigits(firstNumLines, h);
    long long firstNumVal = getNumVal(digitsVal, firstNumDigits);

    int secondNumLines;
    cin >> secondNumLines; cin.ignore();
    vector<string> secondNumDigits = inputNumDigits(secondNumLines, h);
    long long secondNumVal = getNumVal(digitsVal, secondNumDigits);

    char oper;
    cin >> oper; cin.ignore();

    long long resVal;
    if (oper == '*')
        resVal = firstNumVal * secondNumVal;
    else if (oper == '/')
        resVal = firstNumVal / secondNumVal;
    else if (oper == '+')
        resVal = firstNumVal + secondNumVal;
    else if (oper == '-')
        resVal = firstNumVal - secondNumVal;
    
    vector<string> resDigits;
    
    // случай, если результат = 0
    if (resVal == 0) {
        resDigits.push_back(digits[0]);
    } else {
        while (resVal > 0) {
            int digit = resVal % 20;
            resDigits.push_back(digits[digit]);
            resVal /= 20;
        }
    }
    
    while (resDigits.size() > 0) {
        string digitRepres = resDigits.back();
        resDigits.pop_back();
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                cout << digitRepres[i * h + j];
            }
            cout << endl;
        }
    }
    
    return 0;
}
