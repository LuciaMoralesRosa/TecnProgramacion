/*****************************************************************
 * File:   read.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementacion de la clase Read, subclase de Instruccion
*****************************************************************/

#include "read.h"
#include <iostream>
#include <stack>

using namespace std;

Read::Read()
{
};

// Pide un valor al usuario por la entrada estándar y lo apila
int Read::ejecutar(stack<int> &pila, const int contador) 
{
    int num;
    // Pide el numero
    cout << "? ";
    cin >> num;
    // Apila el numero
    pila.push(num);
    return contador + 1;
}

// Devuelve una cadena de texto que representa la instrucción
string Read::nombre() const
{
    return "read";
}
