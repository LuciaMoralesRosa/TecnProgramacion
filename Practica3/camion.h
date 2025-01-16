/*****************************************************************
 * File:   camion.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   16 marzo 2023
 * Coms:   Declaracion de la clase Camion, subclase de Almacen
 * 		   de tipo Carga
*****************************************************************/
/*
 * Un Camion es un tipo de Almacen que solo puede almacenar Cargas.
 */
#pragma once
#include "almacen.h"
#include "carga.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Camion : public Almacen<Carga>
{
public:
    // Constructor
	Camion(double capacidad)
	: Almacen(capacidad) {}
	
	// Devuelve el nombre del Almacen
	string nombre() const override {
		return "Camion";
	}
	
	// OSTREAM
	friend ostream& operator<<(ostream& os, Camion& item) {
		os << item.nombre();
		os << " [" << setprecision(5) << item._capacidad << " m3]";
		os << " [" << setprecision(5) << item.peso() << " kg]" << endl;
		for(auto elemento : item.listaT){
			os << "  " << *elemento;
		}
		return os;
	}
};