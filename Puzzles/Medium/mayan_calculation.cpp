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

int main()
{
    int l;
    int h;
    cin >> l >> h; cin.ignore();
    
    string digits[20] = {""};
    map<string, int> digitVal;
    
    for (int i = 0; i < h; i++) {
        string numeral;
        cin >> numeral; cin.ignore();
        
        for (int j = 0; j < 20 * h; j++) {
            int digitInd = j / h;
            digits[digitInd].push_back(numeral[j]);
        }
    }
    
    for (int i = 0; i < 20; i++) {
        digitVal[digits[i]] = i;
    }

    // Читаем 1-ое число
    int firstNumLines;
    cin >> firstNumLines; cin.ignore();
    
    string curDigit = "";
    vector<string> firstNumDigits;
    long long firstNumVal = 0;
    
    for (int i = 0; i < firstNumLines; i++) {
        string digitLine;
        cin >> digitLine; cin.ignore();
        curDigit += digitLine;
        
        if ((i + 1) % h == 0) {
            firstNumDigits.push_back(curDigit);
            curDigit.clear();
        }
    }
    
    // преобразуем число
    long long p = 1;
    while (firstNumDigits.size() > 0) {
        string digitRepres = firstNumDigits.back();
        firstNumDigits.pop_back();
        firstNumVal += digitVal[digitRepres] * p;
        p *= 20;
    }

    // читаем 2-ое число
    int secondNumLines;
    cin >> secondNumLines; cin.ignore();
    
    curDigit = "";
    vector<string> secondNumDigits;
    long long secondNumVal = 0;
    
    for (int i = 0; i < secondNumLines; i++) {
        string digitLine;
        cin >> digitLine; cin.ignore();
        curDigit += digitLine;
        
        if ((i + 1) % h == 0) {
            secondNumDigits.push_back(curDigit);
            curDigit.clear();
        }
    }

    // преобразуем число
    p = 1;
    while (secondNumDigits.size() > 0) {
        string digitRepres = secondNumDigits.back();
        secondNumDigits.pop_back();
        secondNumVal += digitVal[digitRepres] * p;
        p *= 20;
    }

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
