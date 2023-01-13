#include "UnexpectedError.h"
#include <iostream>


void extern ErrorHandler(UnexpectedError err) {
	
	extern int headStart();

	cout << "Uh-Oh! We have an error! it says: " << endl << endl << err << endl << endl << "We're going to start over!" << endl;

	system("pause");

	system("cls");

	headStart();

}