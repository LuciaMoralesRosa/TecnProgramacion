/*****************************************************************
 * File:   main.cc
 * Author: Lucia Morales (816906)
 * Date:   15 febrero 2022
 * Coms:   Ejercicio 2 de Tecnologia de la programacion 
*****************************************************************/

#include<iostream>
#include<iomanip>
#include"cuenta.h"

using namespace std;

//Declaracion de funciones
double total(Cuenta* cuentas[], int n, int t);
void mostrar_taes(Cuenta * cuentas[], int n);
void actualizar(Cuenta * cuentas[], int n, int& t);
void mostrarCuentas(Cuenta * cuentas[]);

//Programa principal
int main(){

   int t, num = 4;

   Cuenta* cuentas[num];
   cuentas[0] = new Corriente(100.0, 0.5);
   cuentas[1] = new Plazo(324.0, 54.2, 5);
   cuentas[2] = new Nomina(54.3, 3.2, 7);
   cuentas[3] = new Divisa(765.8, 5.4, cuentas[1]);

   mostrar_taes(cuentas, num);
   cout << endl;

   mostrarCuentas(cuentas);   
   actualizar(cuentas, num, t);
   mostrarCuentas(cuentas);

   for(int i = 0; i < 4; i++){
      delete cuentas[i];
   }

   return 0;
}

//Funciones
double total(Cuenta * cuentas[], int n, int t){
   double sol = 0.0;
   for(int i = 0; i < n; i++){
      sol += cuentas[i]->valor(t);
   }
   return sol;
}

void mostrar_taes(Cuenta * cuentas[], int n){
   cout << "Taes: ";
   for(int i = 0; i < n; i++){
      cout << cuentas[i]->tae() << " ";
   }
}

void actualizar(Cuenta * cuentas[], int n, int& t){
   for (int i = 0; i<n; i++){
      cuentas[i]->actualiza(t);
   }
}

void mostrarCuentas(Cuenta * cuentas[]){
   cout << "Mes | Valor cuentas                             | Total     " << endl;
   cout << "============================================================" << endl;
   for(int t = 0; t <= 24; t++){
      cout << setw(3) << t;
      cout << " | ";
      for(int i = 0; i < 4; i++){
         cout << fixed << setw(10) << setprecision(2) << cuentas[i]->valor(t);
      }
      cout << " | ";
      cout << fixed << setw(10) << setprecision(2) << total(cuentas, 4, t);
      cout << " euros " << endl;
   }
}