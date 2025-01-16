/*****************************************************************
 * File:   main.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   9 febrero 2023
*****************************************************************/
#include "rational.h"
#include <iostream>

using namespace std;

int main() {
	Rational	a,b,r;
	char		op;

	while (true) {
		cout << "? " << flush;
		cin >> a;
		if (cin.fail())
			break;

		cin >> op;
		cin >> b;
		if (cin.fail())
			break;

		// Calculo del resultado
		switch(op){
			case '+':
				r = a + b;
				break;
			case '-': 
				r = a - b;
				break;
			case '*': 
				r = a * b;
				break;
			case '/': 
				r = a / b;
				break;
			default:
				break;
		}

		// Escritura del resultado
		cout << r;
		cout << endl;
	}

	return 0;
}

