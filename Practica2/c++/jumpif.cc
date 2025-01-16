/*****************************************************************
 * File:   jumpif.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementacion de la clase JumpIf, subclase de Instruccion
*****************************************************************/
#include "jumpif.h"
#include <iostream>
#include <stack>

using namespace std;

// Constructor
JumpIf::JumpIf(int _l)
    :l(_l)
{
};

// Desapila la cima de la pila, y si su valor es mayor o igual que cero salta la ejecución del programa a la línea l
int JumpIf::ejecutar(stack<int> &pila, const int contador) 
{
    // Desapila el ultimo numero de la pila
    int a = pila.top();
    pila.pop();
    
    // Si a>=0 salta a l, sino, continua a la siguiente instruccion
    if (a >= 0) {
        return l;
    }
    else 
        return contador + 1;
}

// Devuelve una cadena de texto que representa la instrucción
string JumpIf::nombre() const
{
	return "jumpif " + to_string(l);
}