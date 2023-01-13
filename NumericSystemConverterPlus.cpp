#include <iostream>
#include "Extensions.cpp"
#include "UnexpectedError.h"

using namespace std;


string divisMethod(short base1, unsigned long long num, short base2) {

    string result = "";

    while (num >= base2) {
        cout << endl << (num / base2) << "       " << (num % base2);
        result += to_string((num % base2));
        num /= base2;

        if (num < base2) {
            result += to_string((num % base2));
            cout << endl << (num / base2) << "       " << (num % base2);
            num /= base2;
        }
    }

    cout << endl << endl << "The final result is: " << reverseStr(result) << endl << endl;
    
    return reverseStr(result);
}



unsigned long long multipMethod(short base1, unsigned long long num, short base2) {
    
    unsigned long long res = num, result = 0;
    auto arr = digitSplitter(num);
    int i = 0;

    while (res > 0) {
        
        string addition = " +";
        if (res / 10 == 0) { addition = " "; }
        
        cout << endl <<"Number #" << i << ": " << base1 << "^(" << i << ")" << " * " << arr[i] << " = " << power(base1, i) * arr[i] << addition << endl;
        
        result += power(base1, i) * arr[i];
        i += 1;

        res /= 10;
    }
    
        cout << endl << "The final result is: " << result << endl << endl;

    
    return result;
}




string comboMethod(short base1, unsigned long long num, short base2) {

    cout << endl << "First we convert from " << base1 << " to 10 :" << endl;
    
    unsigned long long toDecimal = multipMethod(base1 , num, base2);

    cout << endl << "Then we convert to " << base2 << " from 10 :" << endl;

    string toAnything = divisMethod(base1, toDecimal, base2);

    cout << endl << endl << "Our very final result is: " << toAnything << endl << endl;

    return toAnything;

}

int extern headStart() {

    unsigned long long num;
    short base1, base2;

    // changes done here

    cout << "Please enter the base you want to convert from: \n";
    while (!(cin >> base1)) { 
    cin.clear(); 
    cin.ignore(numeric_limits<short>::max(), '\n');
    ErrorHandler(UnexpectedError("Invalid argument(s) given", -250));
    break;
    }

    cout << "Please enter the number you want to convert: \n";
    while (!(cin >> num)) {
        cin.clear();
        cin.ignore(numeric_limits<unsigned long long>::max(), '\n');
        ErrorHandler(UnexpectedError("Invalid argument(s) given", -250));
        break;
    }

    cout << "Please enter the base you want to convert to: \n";
    while (!(cin >> base2)) {
        cin.clear();
        cin.ignore(numeric_limits<short>::max(), '\n');
        ErrorHandler(UnexpectedError("Invalid argument(s) given", -250));
        break;
    }

    auto checkNum = digitSplitter(num);

    for (int i = 0; i < checkNum.size(); i++) {
        if (checkNum[i] >= base1) {
            ErrorHandler(UnexpectedError("Invalid Number entered, must be less than the base it came in", -3));
            return -3;
        }
        else { continue; }
    }

    if (base1 > 10 || base2 > 10 || base1 < 2 || base2 < 2) {
        ErrorHandler(UnexpectedError("Base is less/greater than normal base limit. (2 | 10)", -2));
        return -2;
    }
    else if (base1 == base2) {
        ErrorHandler(UnexpectedError("Fortunately you do not have to convert from a base to the same base....Please use me responsibly!!!", -5));
        return -5;
    }
    else if (base1 == 10) {
        divisMethod(base1, num, base2);
    }
    else if (base2 == 10) {
        multipMethod(base1, num, base2);
    }
    else {
        comboMethod(base1, num, base2);
    }

    return 0;
}

int main() {

    headStart();

    while (true) {
        cout << "Thank you for using this application, would you like to convert another number? (y/n?) (n)" << endl;
        string answer;  
        cin >> answer;
        if (answer == "yes" || answer == "y" || answer == "Y") {
            system("cls");
            headStart();
        }
        else { break; }
    }

    return 100;
}