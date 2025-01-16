/*****************************************************************
 * File:   contenedor.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   16 marzo 2023
 * Coms:   Declaracion de la clase Contenedor, subclase de Almacen
 * 		   y de Carga
*****************************************************************/
/*
 * Un Contenedor es un tipo de Almacen y de Carga.
 * Por lo que puede almacenar otros elementos y ser almacenado.
 */
#pragma once
#include "carga.h"
#include "toxico.h"
#include "servivo.h"
#include "almacen.h"
#include <iostream>
#include <list>

using namespace std;

template<typename T>
class Contenedor : public Carga, public Almacen<T>
{
public:
    // Constructor
	Contenedor(double capacidad)
		: Carga("Contenedor",0.0, 0.0), Almacen<T>(capacidad) { };

	// Devuelve el nombre del Contenedor
	string nombre() const override {
		return _nombre;
	}

	// Devuelve el peso del Contenedor
	double peso() const override {
		return Almacen<T>::_peso;
	}

	// Devuelve el volumen del Contenedor
	double volumen() const override {
		return Almacen<T>::_capacidad;
	}

	// OSTREAM
	ostream& pantalla(ostream& os) override {
		os << nombre();
		os << " [" << setprecision(5) << volumen() << " m3]";
		os << " [" << setprecision(5) << peso() << " kg] ";
		os << "de Carga Estandar" << endl;
		for(auto elemento : Almacen<T>::listaT){
			os << "    " << *elemento;
		}
		return os;
	}
};

// Para contenedor de Toxicos
template<>
class Contenedor<Toxico> : public Carga, public Almacen<Toxico>
{
public:
    // Constructor
	Contenedor(double capacidad)
		: Carga("Contenedor",0.0, 0.0), Almacen<Toxico>(capacidad) { };

	// Devuelve el nombre del Contenedor
	string nombre() const override {
		return _nombre;
	}

	// Devuelve el peso del Contenedor
	double peso() const override {
		return Almacen<Toxico>::_peso;
	}

	// Devuelve el volumen del Contenedor
	double volumen() const override {
		return Almacen<Toxico>::_capacidad;
	}

	// OSTREAM
	ostream& pantalla(ostream& os) override {
		os << nombre();
		os << " [" << setprecision(5) << volumen() << " m3]";
		os << " [" << setprecision(5) << peso() << " kg] ";
		os << "de Productos Toxicos" << endl;
		for(auto elemento : Almacen<Toxico>::listaT){
			os << "    " << *elemento;
		}
		return os;
	}
};

// Para contenedor de SerVivos
template<>
class Contenedor<SerVivo> : public Carga, public Almacen<SerVivo>
{
public:
    // Constructor
	Contenedor(double capacidad)
		: Carga("Contenedor",0.0, 0.0), Almacen<SerVivo>(capacidad) { };

	// Devuelve el nombre del Contenedor
	string nombre() const override {
		return _nombre;
	}

	// Devuelve el peso del Contenedor
	double peso() const override {
		return Almacen<SerVivo>::_peso;
	}

	// Devuelve el volumen del Contenedor
	double volumen() const override {
		return Almacen<SerVivo>::_capacidad;
	}

	// OSTREAM
	ostream& pantalla(ostream& os) override {
		os << nombre();
		os << " [" << setprecision(5) << volumen() << " m3]";
		os << " [" << setprecision(5) << peso() << " kg] ";
		os << "de Seres Vivos" << endl;
		for(auto elemento : Almacen<SerVivo>::listaT){
			os << "    " << *elemento;
		}
		return os;
	}
};