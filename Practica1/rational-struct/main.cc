/*****************************************************************
 * File:   main.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   9 febrero 2023
 * Coms:   Fichero main.cpp de la implemantacion con TAD
*****************************************************************/
#include "rational.h"
#include <iostream>

using namespace std;

int main(){
	Rational	a,b,r;
	char		op;
	
	while (true){
		cout << "? " << flush;

		read(a,cin);
		if (cin.fail())
			break;
			
		cin >> op;
	
		read(b,cin);
		if (cin.fail())
			break;
		
		// Calculo del resultado
		switch(op){
			case '+': 
				r = add(a, b);
				break;
			case '-': 
				r = sub(a, b);
				break;
			case '*': 
				r = mul(a, b);
				break;
			case '/': 
				r = div(a, b);
				break;
			default:
				break;
		}

		// Escritura del resultado
		write(r, cout);
		cout << endl << endl;
	}

	return 0;
}
