/*****************************************************************
 * File:   servivo.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   16 marzo 2023
 * Coms:   Declaracion de la clase SerVivo, subclase de Cargable
*****************************************************************/
/*
 * Un Ser Vivo es un tipo de Cargable
 */
#pragma once
#include "cargable.h"
#include <iostream>

using namespace std;

class SerVivo : public Cargable
{
public:
    // Constructor
	SerVivo(const string& nombre, double volumen, double peso)
		: Cargable(nombre, volumen, peso) {};
};