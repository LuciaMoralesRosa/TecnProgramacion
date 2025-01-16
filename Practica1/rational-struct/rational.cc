/*****************************************************************
 * File:   rational.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   9 febrero 2023
 * Coms:   Fichero rational.cc de la implemantacion con TAD
*****************************************************************/
#include "rational.h"

// Helper functions -----------------------
// Devuelve el maximo comun divisor de a y b
int mcd(int a, int b) {
   return ( b == 0 ? a : mcd(b, a % b));
}

//Simplifica la funcion
void reduce(Rational& r) {
   int maxCom = mcd(r.num, r.den);
	r.num = r.num/maxCom;
	r.den = r.den/maxCom;
}

// Constructor -----------------------
void init(Rational& r) {
   r.num = 0;
	r.den = 1;
}
void init(Rational& r,int numerador, int denominador) {
   r.num = numerador;
	r.barra  = '/';
	r.den = denominador;
	reduce(r);
}

// Input/output ---------------------------------
void write(const Rational& r, std::ostream& os) {
	if(r.den < 0){
 		os << "= " << -r.num << r.barra << -r.den; 
	}
	else{
 		os << "= " << r.num << r.barra << r.den; 
	}
}

void read(Rational& r, std::istream& is) {
	is >> r.num;
	is >> r.barra;
	is >> r.den;
	reduce(r);
}

// Add -----------------------
Rational add(const Rational& r1, const Rational& r2) {
	Rational res;
	int denCom = mcd(r1.den, r2.den);
	int n1 = r1.den / denCom;
	int n2 = r2.den / denCom;

	init(res, n2 * r1.num + n1 * r2.num , r1.den *(r2.den/denCom));
	return res;
}

Rational add(const Rational& r, int i) {
	Rational res;
	init(res, r.den * i + r.num, r.den);
	return res;
}

Rational add(int i, const Rational& r) {
	Rational res;
	init(res, r.den * i + r.num, r.den);
	return res;
}

/*
4/3 - 5/4
den com = 12
12/3*4 - 12/4*5 = 16 - 15 = 1/12
*/

// Subtract -----------------------
Rational sub(const Rational& r1, const Rational& r2) {
	Rational res;
	int denCom = mcd(r1.den, r2.den);
	int n1 = r1.den / denCom;
	int n2 = r2.den / denCom;

	init(res, n2 * r1.num - n1 * r2.num , r1.den * (r2.den/denCom));
	return res;
}

Rational sub(const Rational& r, int i) {
	Rational res;
	init(res, r.num - (r.den * i), r.den);
	return res;
}

Rational sub(int i, const Rational& r) {
	Rational res;
	init(res, (r.den * i) - r.num, r.den);
	return res;
}

// Multiply -------------------------
Rational mul(const Rational& r1, const Rational& r2) {
	Rational res;
	init(res, r1.num * r2.num, r1.den * r2.den);
	return res;
}

Rational mul(const Rational& r, int i) {
	Rational res;
	init(res, r.num * i, r.den);
	return res;
}

Rational mul(int i, const Rational& r) {
	Rational res;
	init(res, r.num * i, r.den);
	return res;
}

// Divide ------------------------------
Rational div(const Rational& r1, const Rational& r2) {
	Rational res;
	init(res, r1.num * r2.den,  r1.den * r2.num);
	return res;
}

Rational div(const Rational& r, int i) {
	Rational res;
	init(res, r.num, r.den * i);
	return res;
}

Rational div(int i, const Rational& r) {
	Rational res;
	init(res, r.num, r.den * i);
	return res;
}