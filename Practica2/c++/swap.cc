/*****************************************************************
 * File:   swap.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementacion de la clase Swap, subclase de Instruccion
*****************************************************************/
#include "swap.h"

Swap::Swap() : Instruccion(){
};

// Intercambia dos elementos en la cima de la pila
int Swap::ejecutar(stack<int>& pila, const int contador){
   int a = pila.top();
   pila.pop();
   int b = pila.top();
   pila.pop();
   pila.push(a);
   pila.push(b);
   return contador + 1;
}

// Devuelve una cadena de texto que representa la instrucción
string Swap::nombre() const {
   return "swap";
}