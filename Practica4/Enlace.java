/*****************************************************************
 * File:   Enlace.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   13 abril 2023
 * Coms:   Implementación de la clase Enlace, subclase de Nodo
*****************************************************************/

class Enlace extends Nodo {

   private Nodo referencia;

   //Constructor
   public Enlace(String _name, Nodo _refecencia){
      super(_name, 0);
      referencia = _refecencia;
   };

   
   //Funcion recursiva de tamaño
   //Devuelve el valor del nodo enlazado
   private int tamRec(int iter, int tam){
      if(iter < 10){
         iter = iter + 1;
         tam = tam + referencia.tamano(iter);
      }
      else{
         tam = 0;
      }
      return tam;
   }

   //Devuelve el tamaño del enlace
   @Override
   public int tamano(int iter){
      int tam = 0;
      tam = tamRec(iter, tam);
      return tam;
   }

   //Devuelve el nodo referenciado por el enlace
   public Nodo ref(){
      return referencia;
   }

}