/*****************************************************************
 * File:   push.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Declaracion de la clase Push, subclase de Instruccion
*****************************************************************/
#pragma once
#include "instruccion.h"
#include <iostream>
#include <stack>

using namespace std;

class Push : public Instruccion
{
protected:
	int c;
public:
    // Constructor
	Push(int _c);

	// Apila la constante c en la pila
	int ejecutar(stack<int> &pila, const int contador) override;
	// Devuelve una cadena de texto que representa la instrucción
	string nombre() const override;
};