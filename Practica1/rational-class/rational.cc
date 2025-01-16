/*****************************************************************
 * File:   rational.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   9 febrero 2023
*****************************************************************/
#include "rational.h"
using namespace std;

// Helper methods -----------------------
int Rational::mcd(int a, int b) {
   return ( b == 0 ? a : mcd(b,a%b));
}

void Rational::reduce() {
	int max = mcd(this->num, this->den);
	this->num = this->num/max;
	this->den = this->den/max;
}

// Constructor -----------------------
Rational::Rational() {
	num = 0;
	den = 1;
}

Rational::Rational(int n, int d) {
   num = n;
	den = d;
	reduce();
}

// Input/output ---------------------------------
ostream& operator<<(ostream& os, Rational& r) {
	if(r.den < 0){
	 	os << "= " << -r.num << '/' << -r.den;
	}
	else{
 		os << "= " << r.num << '/' << r.den;
	}
	return os;
}

istream& operator>>(istream& is, Rational& r) {
	is >> r.num;
	is >> r.barra;
	is >> r.den;
	r.reduce();
	return is;
}

// Add -----------------------
Rational Rational::operator+(const Rational& that) const {
	Rational res;
	int denCom = mcd(this->den, that.den);
	res.den =  this->den *(that.den/denCom);
	res.num = that.den / denCom * this->num + this->den / denCom * that.num ;
	return res;
}

Rational Rational::operator+(int i) const {
	return Rational(this->den * i + this->num, this->den);
}

Rational operator+(int i, const Rational& r) {
	Rational res;
	res = r + i;
	return res;
}

// Subtract -----------------------
Rational Rational::operator-(const Rational& that) const{
	Rational res;
	int denCom = mcd(this->den, that.den);
	res.den =  this->den *(that.den/denCom);
	res.num = that.den / denCom * this->num - this->den / denCom * that.num ;
	return res;
}

Rational Rational::operator-(int i) const{
	return Rational(this->num - (this->den * i), this->den);
}

Rational operator-(int i, const Rational& r){
	Rational res, otro(i, 1);
	res = otro - r;
	return res;
}


// Multiply -------------------------
Rational Rational::operator*(const Rational& that) const{
	return Rational(this->num * that.num, this->den * that.den);
}

Rational Rational::operator*(int i) const{
	return Rational(this->num * i, this->den);
}

Rational operator*(int i, const Rational& r){
	Rational res;
	res = r * i;
	return res;
}


// Divide ------------------------------
Rational Rational::operator/(const Rational& that) const{
	return Rational(this->num * that.den, this->den * that.num);
}

Rational Rational::operator/(int i) const{
	return Rational(this->num, this->den * i);
}

Rational operator/(int i, const Rational& r){
	Rational res,  otro(i, 1);
	res = otro / r;
	return res;
}



