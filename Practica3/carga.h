/*****************************************************************
 * File:   carga.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   16 marzo 2023
 * Coms:   Declaracion de la clase Carga, subclase de Cargable
*****************************************************************/
/*
 * Una Carga es un tipo de Cargable que puede ser almacenado en camiones.
 */
#pragma once
#include "cargable.h"
#include <iostream>

using namespace std;

class Carga : public Cargable
{
public:
    // Constructor
	Carga(const string& nombre, double volumen, double peso)
		: Cargable(nombre, volumen, peso) {};
};