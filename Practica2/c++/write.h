/*****************************************************************
 * File:   write.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Declaracion de la clase Write, subclase de Instruccion
*****************************************************************/
#pragma once
#include "instruccion.h"
#include <iostream>
#include <stack>

using namespace std;

class Write : public Instruccion
{
public:
    // Constructor
	Write();

	// Desapila un valor de la pila y lo muestra por la salida estándar al usuario
	int ejecutar(stack<int> &pila, const int contador) override;
	// Devuelve una cadena de texto que representa la instrucción
	string nombre() const override;
};