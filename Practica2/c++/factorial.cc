/*****************************************************************
 * File:   factorial.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementacion de la clase Factorial, subclase de Programa
*****************************************************************/
#include <iostream>
#include <stack>
#include "factorial.h"

using namespace std;

// Constructor
Factorial::Factorial()
{
   nInstrucciones = 14;
   instrucciones = new InsPtr[nInstrucciones];
   instrucciones[0] = new Push(1);
   instrucciones[1] = new Read();
   instrucciones[2] = new Swap();
   instrucciones[3] = new Over();
   instrucciones[4] = new Mul();
   instrucciones[5] = new Swap();
   instrucciones[6] = new Push(-1);
   instrucciones[7] = new Add();
   instrucciones[8] = new Dup();
   instrucciones[9] = new Push(-2);
   instrucciones[10] = new Add();
   instrucciones[11] = new JumpIf(2);
   instrucciones[12] = new Swap();
   instrucciones[13] = new Write();
   
};