/*****************************************************************
 * File:   jumpif.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Declaracion de la clase JumpIf, subclase de Instruccion
*****************************************************************/
#pragma once
#include "instruccion.h"
#include <iostream>
#include <stack>

using namespace std;

class JumpIf : public Instruccion
{
protected:
	int l;
public:
    // Constructor
	JumpIf(int _l);

	// Desapila la cima de la pila, y si su valor es mayor o igual que cero salta la ejecución del programa a la línea l
	int ejecutar(stack<int> &pila, const int contador) override;
	// Devuelve una cadena de texto que representa la instrucción
	string nombre() const override;
};