/*****************************************************************
 * File:   rational.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   9 febrero 2023
*****************************************************************/
#pragma once

#include <iostream>
using namespace std;

// Solucion con atributos privados.

class Rational{
private:
	// Miembros
	int num, den;
	char barra;

	// Funciones auxiliares
	static int mcd(int a, int b);
	void reduce();

public:
	// Constructores
	Rational();
	Rational(int n, int d);

	// Entrada - salida
	friend ostream& operator<<(ostream& os, Rational& that);
	friend istream& operator>>(istream& is, Rational& that);

	// Operadores aritmeticos
	Rational operator+(const Rational& that) const;
	Rational operator+(int i) const;
	Rational operator-(const Rational& that) const;
	Rational operator-(int i) const;
	Rational operator*(const Rational& that) const;
	Rational operator*(int i) const;
	Rational operator/(const Rational& that) const;
	Rational operator/(int i) const;

};

// Operadores aritmeticos
Rational operator+(int i, const Rational& r);
Rational operator-(int i, const Rational& r);
Rational operator*(int i, const Rational& r);
Rational operator/(int i, const Rational& r);