#pragma once
#ifndef UNEXPECTEDERROR_H_
#define UNEXPECTEDERROR_H_
#include <iostream>
using namespace std;

class UnexpectedError :
    public exception
{
private:
    string errorMessage;
    int errorCode;
public:
    UnexpectedError(string message = "An unknown error has occured", int code = 3) {
        errorMessage = message;
        errorCode = code;
    }

    string what() {
        return errorMessage;
    }

    friend ostream& operator<<(ostream& out, UnexpectedError err) {
        out << endl << err.errorMessage << endl << "With error code: " << err.errorCode;
        return out;
    }

};

void extern ErrorHandler(UnexpectedError err);

#endif