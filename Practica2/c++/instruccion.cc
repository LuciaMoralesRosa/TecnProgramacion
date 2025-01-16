/*****************************************************************
 * File:   instruccion.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementacion de la clase Instruccion
*****************************************************************/
#include "instruccion.h"
#include <iostream>
#include <stack>

using namespace std;

// Constructor
Instruccion::Instruccion()
{
};

// Modifica la pila y devuelve el número en el que modificar el contador para que ejecute la siguiente instruccion
int Instruccion::ejecutar(stack<int> &pila, const int contador) 
{
	return 1;
}

// Devuelve una cadena de texto que representa la instrucción
string Instruccion::nombre() const
{
	return "instruccion";
}
