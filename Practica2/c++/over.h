/*****************************************************************
 * File:   over.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Declaracion de la clase Over, subclase de Instruccion
*****************************************************************/
#pragma once
#include "instruccion.h"
#include <iostream>
#include <stack>

using namespace std;

   class Over : public Instruccion {
   protected:
      int c;
   public:
      // Constructor
      Over();

      // Copia el valor que está tras la cima de la pila
      int ejecutar(stack<int> &pila, const int contador) override;
      // Devuelve una cadena de texto que representa la instrucción
      string nombre() const override;
};