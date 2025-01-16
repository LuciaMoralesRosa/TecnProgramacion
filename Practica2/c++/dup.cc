/*****************************************************************
 * File:   dup.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementacion de la clase Dup, subclase de Instruccion
*****************************************************************/
#include "dup.h"
#include <iostream>
#include <stack>

using namespace std;

// Constructor
Dup::Dup()
{
};

// Duplica la cima de la pila
int Dup::ejecutar(stack<int> &pila, const int contador) 
{
    // Copia el ultimo elemento apilado
    int a = pila.top();
    // Apila el elemento
    pila.push(a);
    return contador + 1;
}

// Devuelve una cadena de texto que representa la instrucción
string Dup::nombre() const
{
	return "dup";
}