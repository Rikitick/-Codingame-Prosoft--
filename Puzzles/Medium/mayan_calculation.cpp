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
    map<string, int> digitToValue;
    
    for (int i = 0; i < h; i++) {
        string numeral;
        cin >> numeral; cin.ignore();
        
        for (int j = 0; j < 20 * h; j++) {
            int digitIndex = j / h;
            digits[digitIndex].push_back(numeral[j]);
        }
    }
    
    for (int i = 0; i < 20; i++) {
        digitToValue[digits[i]] = i;
    }

    // Читаем 1-ое число
    int firstNumberLines;
    cin >> firstNumberLines; cin.ignore();
    
    string currentDigit = "";
    vector<string> firstNumberDigits;
    long long firstNumberValue = 0;
    
    for (int i = 0; i < firstNumberLines; i++) {
        string digitLine;
        cin >> digitLine; cin.ignore();
        currentDigit += digitLine;
        
        if ((i + 1) % h == 0) {
            firstNumberDigits.push_back(currentDigit);
            currentDigit.clear();
        }
    }
    
    // преобразуем число
    long long power = 1;
    while (firstNumberDigits.size() > 0) {
        string digitRepresentation = firstNumberDigits.back();
        firstNumberDigits.pop_back();
        firstNumberValue += digitToValue[digitRepresentation] * power;
        power *= 20;
    }

    // читаем 2-ое число
    int secondNumberLines;
    cin >> secondNumberLines; cin.ignore();
    
    currentDigit = "";
    vector<string> secondNumberDigits;
    long long secondNumberValue = 0;
    
    for (int i = 0; i < secondNumberLines; i++) {
        string digitLine;
        cin >> digitLine; cin.ignore();
        currentDigit += digitLine;
        
        if ((i + 1) % h == 0) {
            secondNumberDigits.push_back(currentDigit);
            currentDigit.clear();
        }
    }

    // преобразуем число
    power = 1;
    while (secondNumberDigits.size() > 0) {
        string digitRepresentation = secondNumberDigits.back();
        secondNumberDigits.pop_back();
        secondNumberValue += digitToValue[digitRepresentation] * power;
        power *= 20;
    }

    char operation;
    cin >> operation; cin.ignore();

    long long resultValue;
    if (operation == '*')
        resultValue = firstNumberValue * secondNumberValue;
    else if (operation == '/')
        resultValue = firstNumberValue / secondNumberValue;
    else if (operation == '+')
        resultValue = firstNumberValue + secondNumberValue;
    else if (operation == '-')
        resultValue = firstNumberValue - secondNumberValue;
    
    vector<string> resultDigits;
    
    // случай, если результат = 0
    if (resultValue == 0) {
        resultDigits.push_back(digits[0]);
    } else {
        while (resultValue > 0) {
            int digit = resultValue % 20;
            resultDigits.push_back(digits[digit]);
            resultValue /= 20;
        }
    }
    
    while (resultDigits.size() > 0) {
        string digitRepresentation = resultDigits.back();
        resultDigits.pop_back();
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                cout << digitRepresentation[i * h + j];
            }
            cout << endl;
        }
    }
    
    return 0;
}
