
#pragma once

#ifndef STORE_H
#define STORE_H

#include<cstring>
#include<iostream>
#include"store.h"

using namespace std;

template<typename T>

class Logger{
   private:
      string nombre;
      Store<T>* almacen[];

   public:
      Logger(const string _nombre, const Store<T>** _almacen)
         : nombre(_nombre), almacen(_almacen) {}

      void push(const T& dato){
         for (Store<T>* t : almacen){
            t->push(dato);
         }
      }
      void push(const T dato[]){
         for(T temp : dato){
            for (Store<T>* st : almacen){
               st->push(temp);
            }
         }
      }

      void log(){
         cout << nombre << ": " << endl;
         for (Store<T>* t : almacen){
            cout << t->nombre << t->value() << endl;
         }
      }
};



#endif