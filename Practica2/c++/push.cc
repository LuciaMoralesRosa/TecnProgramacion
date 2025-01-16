/*****************************************************************
 * File:   push.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementacion de la clase Push, subclase de Instruccion
*****************************************************************/
#include "push.h"
#include <iostream>
#include <stack>

using namespace std;

// Constructor
Push::Push(int _c)
    :c(_c)
{
};

// Apila la constante c en la pila
int Push::ejecutar(stack<int> &pila, const int contador) 
{
    pila.push(c);
    return contador + 1;
}

// Devuelve una cadena de texto que representa la instrucción
string Push::nombre() const
{
	return "push " + to_string(c);
}