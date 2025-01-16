/*****************************************************************
 * File:   cargable.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   16 marzo 2023
 * Coms:   Declaracion de la clase Cargable
*****************************************************************/
/*
 * Una Cargable es un objeto con un peso, un volumen, un nombre y un tipo,
 * que se puede cargar en un Almacen.
 */
#pragma once
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

class Cargable {
protected:
    // Nombre del elemento
    string _nombre;
    // Volumen del elemento
    double _volumen;
    // Peso del elemento
    double _peso;

public:
    // Constructor
    Cargable(const string& nombre, double volumen, double peso)
        : _nombre(nombre), _volumen(volumen), _peso(peso) {}
    
    // Devuelve el nombre del Cargable
    virtual string nombre() const {
        return _nombre;
    }
    
    // Devuelve el volumen del Cargable
    virtual double volumen() const {
        return _volumen;
    }

    // Devuelve el peso del Cargable
    virtual double peso() const {
        return _peso;
    }

    virtual ostream& pantalla(ostream& os) {
        os << "  " << nombre();
        os << " [" << setprecision(5) << volumen() << " m3]";
        os << " [" << setprecision(5) << peso() << " kg]" << endl;
        return os;
    }

	// OSTREAM
    friend ostream& operator<<(ostream& os, Cargable& item) {
        return item.pantalla(os);
    }
};