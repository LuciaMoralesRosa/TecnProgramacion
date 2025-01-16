/*****************************************************************
 * File:   cuenta.cc
 * Author: Lucia Morales (816906)
 * Date:   15 febrero 2022
 * Coms:   Ejercicio 2 de Tecnologia de la programacion
*****************************************************************/

#include"cuenta.h"
#include<cmath>


double Cuenta::tae() const {
   return 100.0*(valor(12)/valor(0) - 1);
}

double Cuenta::valor(int t) const {
   return 0;
}

double Plazo::valor(int t) const{
   return (t < plazo ? capital : capital*(1+(interes/100.0)));
}

double Corriente::valor(int t) const {
   return capital*pow(1+(interes/100.0), t);
}


//PARTE DOS ------------------------------------------------------------

double Nomina::valor(int t) const {
   return (capital + ingreso*t);
}

double Plazo::tae() const{
   return (valor(0) + 12*(valor(plazo) - valor(0)) / plazo);
}


void Cuenta::actualiza(int& t){
}

void Plazo::actualiza(int& t){
   t = t + 1;
}

double Divisa::valor(int t) const {
   return factor * cuenta->valor(t);
}