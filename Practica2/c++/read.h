/*****************************************************************
 * File:   read.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Declaracion de la clase Add, subclase de Instruccion
*****************************************************************/

#pragma once
#include "instruccion.h"
#include <iostream>
#include <stack>

using namespace std;

class Read : public Instruccion
{
public:
    // Constructor
    Read();

    // Pide un valor al usuario por la entrada estándar y lo apila
    int ejecutar(stack<int> &pila, const int contador) override;
    // Devuelve una cadena de texto que representa la instrucción
    string nombre() const override;
};