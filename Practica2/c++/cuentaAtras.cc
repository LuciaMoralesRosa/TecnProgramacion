
#include "cuentaAtras.h"
#include <iostream>
#include <stack>

using namespace std;

// Constructor
cuentaAtras::cuentaAtras()
{
   numIns = 7;
   instrucciones = new InsPtr[numIns];
   instrucciones[0] = new Read();
   instrucciones[1] = new Dup();
   instrucciones[2] = new Write();
   instrucciones[3] = new Push(-1);
   instrucciones[4] = new Add();
   instrucciones[5] = new Dup();
   instrucciones[6] = new Jumpif(1);
    
};