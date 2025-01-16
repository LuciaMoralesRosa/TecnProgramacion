/*****************************************************************
 * File:   write.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementacion de la clase Write, subclase de Instruccion
*****************************************************************/
#include "write.h"
#include <iostream>
#include <stack>

using namespace std;

// Constructor
Write::Write()
{
};

// Desapila un valor de la pila y lo muestra por la salida estándar al usuario
int Write::ejecutar(stack<int> &pila, const int contador) 
{
	cout << pila.top() << endl;
    pila.pop();
    return contador + 1;
}

// Devuelve una cadena de texto que representa la instrucción
string Write::nombre() const
{
	return "write";
}