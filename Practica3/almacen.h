/*****************************************************************
 * File:   almacen.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   16 marzo 2023
 * Coms:   Declaracion e implementación de la clase genérica Almacen
*****************************************************************/
/*
 * Un Almacen es un objeto que puede almacenar otros elementos
 * en su interior. Tiene una cierta capacidad. Su peso es el 
 * equivalente a sumar el peso de todos los elementos en su interior.
 * Su volumen es el equivalente a sumar el o volumen de todos los
 * elementos en su interior. El volumen nunca puede superar la capacidad.
 */
#pragma once
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

template<typename T>
class Almacen
{
protected:
	// Máxima capacidad
	double _capacidad;
    // Volumen total de su contenido
	double _volumen;
	// Peso total de su contenido
	double _peso;
	// Lista de elementos en su interior
	list<T*> listaT;

public:
	// Constructor
    Almacen(double capacidad) 
		: _capacidad(capacidad), _volumen(0.0), _peso(0.0) {};

	// Devuelve el nombre del Almacen
	virtual string nombre() const {
		return "Almacen";
	}

	// Devuelve el volumen del Almacen
	double volumen() const {
		return _volumen;
	}

	// Devuelve el peso del Almacen
	double peso() const {
		return _peso;
	}
	
	// Guarda un elemento en el Almacen
	// Devuelve 'true' si ha conseguido guardar el elemento
	// Devuelve 'false' si el volumen añadido superaría la capacidad
	// del almacen, no se añade el elemento.
	bool guardar(T* elemento) {

		if (_volumen + elemento->volumen() > _capacidad){
			return false;
		}


		//Se guarda el elemento
		listaT.push_back(elemento);

		//Se suma el volumen y el peso al Almacen
		_peso = _peso + elemento->peso();
		_volumen = _volumen + elemento->volumen();

		return true;
	}
};