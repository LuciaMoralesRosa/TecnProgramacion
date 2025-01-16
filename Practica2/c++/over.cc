/*****************************************************************
 * File:   over.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Declaracion de la clase Over, subclase de Instruccion
*****************************************************************/
#include "over.h"

Over::Over() : Instruccion(){
};

// Copia el valor que está tras la cima de la pila
int Over::ejecutar(stack<int>& pila, const int contador){
   int a = pila.top();
   pila.pop();
   int b = pila.top();
   pila.pop();
   pila.push(b);
   pila.push(a);
   pila.push(b);
   return contador + 1;
}

// Devuelve una cadena de texto que representa la instrucción
string Over::nombre() const {
   return "over";
}