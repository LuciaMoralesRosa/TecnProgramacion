/*****************************************************************
 * File:   cuenta_atras.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementacion de la clase CuentaAtras, subclase de Programa
*****************************************************************/
#include "cuenta_atras.h"
#include "add.h"
#include "read.h"
#include "write.h"
#include "push.h"
#include "dup.h"
#include "jumpif.h"
#include <iostream>
#include <stack>

using namespace std;

// Constructor
CuentaAtras::CuentaAtras()
{
    nInstrucciones = 7;
    instrucciones = new InsPtr[nInstrucciones];
    instrucciones[0] = new Read();
    instrucciones[1] = new Dup();
    instrucciones[2] = new Write();
    instrucciones[3] = new Push(-1);
    instrucciones[4] = new Add();
    instrucciones[5] = new Dup();
    instrucciones[6] = new JumpIf(1);
};