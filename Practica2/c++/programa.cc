/*****************************************************************
 * File:   programa.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementacion de la clase Programa
*****************************************************************/
#include "programa.h"

// Constructor
Programa::Programa()
	: instrucciones(nullptr), nInstrucciones(0)
{
};

// Destructor
Programa::~Programa()
{
	for (int i=0; i<nInstrucciones; i++) {
		delete instrucciones[i];
	}
};

// Ejecuta las instrucciones del programa
void Programa::ejecutar(stack<int> pila) 
{
	cout << "Ejecutar: " << endl;
	int contador = 0;
	while (contador < nInstrucciones) {
		// Se le asigna al contador el numero devuelto de la ejecución de la instrucción
		contador = instrucciones[contador]->ejecutar(pila, contador);
	}
	cout << endl;
}

// Lista las instrucciones del programa
void Programa::listar() const
{
	cout << "Programa: " << endl;
	for (int contador = 0; contador < nInstrucciones; contador++) {
		cout << contador << ". " << instrucciones[contador]->nombre() << endl;
	}
	cout << endl;
}
