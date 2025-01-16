/*****************************************************************
 * File:   instruccion.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Declaracion de la clase Instruccion
*****************************************************************/
#pragma once
#include <iostream>
#include <stack>

using namespace std;

class Instruccion
{
public:
    // Constructor
	Instruccion();

    // Modifica la pila y devuelve el número en el que aumentar el contador de instrucciones
	virtual int ejecutar(stack<int> &pila, const int contador);
    // Devuelve una cadena de texto que representa la instrucción
	virtual string nombre() const;
};