/*****************************************************************
 * File:   main.cc
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Fichero main
*****************************************************************/
#include "instruccion.h"
#include "programa.h"
#include "suma.h"
#include "cuenta_atras.h"
#include "factorial.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Numero de programas a ejecutar
const int N = 3;

int main()
{
	Programa* programas[N];
	stack<int> pila;

	// Lista de programas
	programas[0] = new Suma();
	programas[1] = new CuentaAtras();
	programas[2] = new Factorial();
	//...

	// Ejecucion de todos los programas
	for (int i = 0; i<N; i++) {
		programas[i]->listar();
		programas[i]->ejecutar(pila);
	}

	// Eliminar programas
	for (int i=0; i<N; i++) {
		delete programas[i];
	}
	
	return 0;
}
