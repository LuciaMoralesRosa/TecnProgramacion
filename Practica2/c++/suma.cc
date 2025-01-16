/*****************************************************************
 * File:   suma.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementacion de la clase Suma, subclase de Programa
*****************************************************************/
#include "suma.h"
#include "add.h"
#include "read.h"
#include "write.h"
#include <iostream>
#include <stack>

using namespace std;

// Constructor
Suma::Suma()
{
    nInstrucciones = 4;
    instrucciones = new InsPtr[nInstrucciones];
    instrucciones[0] = new Read();
    instrucciones[1] = new Read();
    instrucciones[2] = new Add();
    instrucciones[3] = new Write();
};