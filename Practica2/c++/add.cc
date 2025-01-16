/*****************************************************************
 * File:   add.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementacion de la clase Add, subclase de Instruccion
*****************************************************************/
#include "add.h"
#include <iostream>
#include <stack>

using namespace std;

// Constructor
Add::Add()
{
};

// Desapila dos valores de la pila y apila su suma
int Add::ejecutar(stack<int> &pila, const int contador) 
{
    // Desapila los ultimos dos numeros de la pila
    int a = pila.top();
    pila.pop();
    int b = pila.top();
    pila.pop();
    // Los suma y apila el resultado
    pila.push(a+b);
    return contador + 1;
}

// Devuelve una cadena de texto que representa la instrucción
string Add::nombre() const
{
	return "add";
}