/*****************************************************************
 * File:   toxico.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   16 marzo 2023
 * Coms:   Declaracion de la clase Toxico, subclase de Cargable
*****************************************************************/
/*
 * Un Toxico es un tipo de Cargable
 */
#pragma once
#include "cargable.h"
#include <iostream>

using namespace std;

class Toxico : public Cargable
{
public:
    // Constructor
	Toxico(const string& nombre, double volumen, double peso)
		: Cargable(nombre, volumen, peso) {};
};