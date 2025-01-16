/*****************************************************************
 * File:   producto.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   16 marzo 2023
 * Coms:   Declaracion de la clase Producto, subclase de Carga
*****************************************************************/
/*
 * Un Producto es un tipo de Carga
 */
#pragma once
#include <iostream>
#include "carga.h"
using namespace std;

class Producto : public Carga
{
public:
    // Constructor
	Producto(const string& nombre, double volumen, double peso)
        : Carga(nombre, volumen, peso) {};
};