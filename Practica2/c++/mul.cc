/*****************************************************************
 * File:   mul.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementacion de la clase Mul, subclase de Instruccion
*****************************************************************/
#include "mul.h"

Mul::Mul() : Instruccion(){
};

// Desapila dos valores de la pila y apila su producto
int Mul::ejecutar(stack<int>& pila, const int contador){
   int a = pila.top();
   pila.pop();
   int b = pila.top();
   pila.pop();
   pila.push(a*b);

   return contador + 1;
}

// Devuelve una cadena de texto que representa la instrucción
string Mul::nombre() const {
   return "mul";
}
