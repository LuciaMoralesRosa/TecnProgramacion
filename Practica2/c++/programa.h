/*****************************************************************
 * File:   programa.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Declaración de la clase Programa
*****************************************************************/
#pragma once
#include "instruccion.h"
#include <iostream>
#include <stack>

using namespace std;
using InsPtr = Instruccion*;

class Programa
{
protected:
	// Vector de instrucciones
	InsPtr* instrucciones;
	// Numero de instrucciones
	int nInstrucciones;

public:
    // Constructor
	Programa();
	// Destructor
	~Programa();

	// Ejecuta las instrucciones del programa
	void ejecutar(stack<int> pila);
	// Lista las instrucciones del programa
	void listar() const;
};